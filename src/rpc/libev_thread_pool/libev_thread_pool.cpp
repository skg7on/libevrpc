/***************************************************************************
 * 
 * Copyright (c) 2014 aishuyu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file thread_pool.cpp
 * @author aishuyu(asy5178@163.com)
 * @date 2014/11/07 18:44:20
 * @brief 
 *  
 **/

#include "thread_pool.h"

#include "pthread_mutex.h"

namespace libevrpc {

volatile ATOMIC_BOOL LibevThreadPool::running_(true);


LibevThreadPool::LibevThreadPool() :
    current_thread_(-1),
    nthread_num_(10),
    max_nthread_num_(50) {
       Initialize();
}


LibevThreadPool::LibevThreadPool(int nthread) :
    nthread_num_(nthread),
    max_nthread_num_(50) {
        Initialize();
}

LibevThreadPool::~LibevThreadPool() {
    Destroy();
    free(thread_ids_);
    thread_ids_ = NULL;
}

bool LibevThreadPool::Initialize() {
    // init the task list
    thread_ids_ = (pthread_t *) malloc(nthread_num_ * sizeof(pthread_t));
    task_list_.task_head = (Task*) malloc(sizeof(Task));
    memset(thread_ids_, 0, sizeof(thread_ids_));

    task_list_.task_head->next = task_list_.task_head;
    task_list_.task_head->prev = task_list_.task_head;
    return true;
}

bool LibevThreadInitialization(int num_threads) {
    num_threads_ = num_threads;
    libev_threads_ = calloc(num_threads_, sizeof(LIBEV_THREAD));

    cq_freelist_ = NULL;

    if (NULL == libev_threads_) {
        return false;
    }

    for (int32_t i = 0; i < num_threads_; ++i) {
        int32_t fds[2];
        if (pipe(fds)) {
            perror("Create notify pipe failed!");
            exit(1);
        }
        /*
         * start to init the libev info in every thread
         */
        LIBEV_THREAD* cur_thread = libev_threads_[i];
        cur_thread->notify_receive_fd = fds[0];
        cur_thread->notify_send_fd = fds[1];

        cur_thread->epoller = ev_loop_new(0);
        if (NULL == cur_thread->epoller) {
            perror("Ev loop new failed!");
            exit(-1);
        }
        cur_thread->lt_pool = this;
        ev_io_init(&cur_thread->libev_watcher, LibevThreadPool::LibevProcessor, cur_thread->notify_receive_fd, EV_READ | EV_PERSIST);
        ev_io_start(cur_thread->epoller, &cur_thread->libev_watcher);

        cur_thread->new_request_queue = malloc(sizeof(RQ));
        if (NULL == cur_thread->new_request_queue) {
            perror("Failed to allocate memory for request queue");
            exit(-1);
        }
        {
            MutexLockGuard lock(cur_thread->new_request_queue->q_mutex);
            cur_thread->cur_thread->head = NULL;
            cur_thread->cur_thread->tail = NULL;
        }
    }

    for (int i = 0; i < num_threads_; ++i) {
        pthread_create(&(libev_threads_[i]->thread_id), NULL, LibevThreadPool::LibevWorker, libev_threads_[i]);
    }

    return true;
}

void *LibevThreadPool::LibevWorker(void *arg) {
    LIBEV_THREAD* me = arg;

    ev_loop(me->epoller, 0);
}

RQ_ITEM* LibevThreadPool::RQNew() {

    return NULL;
}

bool LibevThreadPool::RQPush(RQ* req_queue, RQ_ITEM* req_item) {
    return true;
}


RQ_ITEM* LibevThreadPool::RQPop(RQ* req_queue) {
    RQ_ITEM* rq_item = NULL;
    {
        MutexLockGuard lock(req_queue->q_mutex);
        rq_item = request_queue->head;
        if (NULL != rq_item) {
            req_queue->head = rq_item->next;
            if (NULL == req_queue->head) {
                req_queue->tail = NULL;
            }
        }
    }
    return rq_item;
}

bool LibevThreadPool::Start() {
    // start all threads in the pool
    for (int i = 0; i < nthread_num_; ++i) {
        pthread_create(&thread_ids_[i], NULL, WorkerThread, this);
    }
    return true;
}

bool LibevThreadPool::Wait() {
    sleep(8);
    if (NULL != thread_ids_) {
        for (int i = 0; i < nthread_num_; ++i) {
            if (thread_ids_[i] == 0) {
                continue;
            }
            pthread_join(thread_ids_[i], NULL);
        }
    }
}

bool LibevThreadPool::Destroy() {
    running_ = false;
    ConditionBroadCast(cond_);

    Wait();

    task_list_.task_head->prev->next = NULL;
    Task* head_ptr = NULL;
    while (task_list_.task_head != NULL) {
        head_ptr = task_list_.task_head->next;
        task_list_.task_head = task_list_.task_head->next;
        free(head_ptr);
        head_ptr = NULL;
    }

    return true;

}

bool LibevThreadPool::Processor(void *(*process) (void *arg), void *arg) {
   Task* task_ptr = (Task*)malloc(sizeof(Task)); 
   task_ptr->process = process;
   task_ptr->param = arg;
   task_ptr->next = NULL;

   {
       // insert the task
       MutexLockGuard lock(task_mutex_);
       task_ptr->next = task_list_.task_head->next;
       task_ptr->prev = task_list_.task_head;
       task_list_.task_head->next->prev = task_ptr;
       task_list_.task_head->next = task_ptr;
       ++task_list_.task_num;
   }

   ConditionSignal(cond_);
   return true;
}

bool LibevThreadPool::DispatchRpcCall(void *(*rpc_call) (void *arg), void *arg) {
    if (NULL == libev_threads_) {
        perror("Dispatch rpc call failed! libev_threads ptr is null.");
        return false;
    }
    RQ_ITEM* rq_item = RQNew();
    if (NULL == rq_item) {

    }

    int32_t cur_tid = (current_thread_ + 1) % num_threads_;
    LIBEV_THREAD* cur_thread = libev_threads_ + cur_tid;
    current_thread_ = cur_tid;

    /*
     * set req item data
     */
    rq_item->processor = rpc_call;
    rq_item->param = arg;
    if (!RQPush(cur_thread->request_queue, rq_item)) {
        return false
    }

    char buf[1] = {'c'};
    if (write(cur_thread->notify_send_fd, buf, 1) != 1) {
        perror("Write to thread notify pipe failed!");
    }
    return true;
}

void *LibevThreadPool::WorkerThread(void *arg) {
    LibevThreadPool* pool = reinterpret_cast<LibevThreadPool*>(arg);
    TaskList& task_list = pool->task_list_;
    while (running_) {
        Task* task_proc = NULL;
        {
            MutexLockGuard lock(pool->task_mutex_);
            while (task_list.task_head->next == task_list.task_head) {
                ConditionWait(pool->cond_, pool->task_mutex_);
                if (false == running_) {
                    return NULL;
                    //pthread_exit(0);
                }
            }
            task_proc = task_list.task_head->prev;
            // remove the task from task list
            task_proc->next->prev = task_proc->prev;
            task_proc->prev->next = task_list.task_head;
            --task_list.task_num;
            task_proc->prev = NULL;
            task_proc->next = NULL; 
        }

        (*(task_proc->process))(task_proc->param);
    }

    return NULL;
}

void LibevThreadPool::LibevProcessor(struct ev_loop *loop, struct ev_io *watcher, int revents) {
    LIBEV_THREAD *me = watcher->data;
    if (NULL == me) {
        perror("LIBEV_THREAD data is NULL!");
        return;
    }

    char buf[1];
    if (read(watcher->fd, buf, 1) != 1) {
        perror("Can't read from libevent pipe!");
    }
    LibevThreadPool* lt_pool = me->lt_pool;
    switch (buf[0]) {
        case 'c':
            RQ_ITEM* item = lt_pool->RQPop(me->new_request_queue);
            (*(item->process))(item->param);
    }
}


} // end of namespace










/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */