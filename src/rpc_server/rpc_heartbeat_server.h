/***************************************************************************
 *
 * Copyright (c) 2016 aishuyu, Inc. All Rights Reserved
 *
 **************************************************************************/



/**
 * @file rpc_heartbeat_server.h
 * @author aishuyu(asy5178@163.com)
 * @date 2016/04/04 22:08:26
 * @brief
 *
 **/




#ifndef __RPC_HEARTBEAT_SERVER_H
#define __RPC_HEARTBEAT_SERVER_H

// #include <atmoic>

#include "dispatch_thread.h"
#include "util/thread.h"

namespace libevrpc {

class RpcHeartbeatServer {
    public:
        RpcHeartbeatServer(
                const char* hb_host,
                const char* hb_port,
                const char* config_file);
        ~RpcHeartbeatServer();

        bool InitHeartbeatServer();
        bool Start();
        bool Wait();
        bool Stop();

        /*
         * recv the hearbeat in libev and put the hb info
         * into connectin timer manager
         */
        static void HeartBeatProcessor(int32_t fd, void *arg);

    private:
        DispatchThread*  dispatcher_thread_ptr_;
        char* hb_host_;
        char* hb_port_;
        char* config_file_;

        int32_t listenfd_;
        bool hb_running_;

};

}  // end of namespace libevrpc




#endif // __RPC_HEARTBEAT_SERVER_H



/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
