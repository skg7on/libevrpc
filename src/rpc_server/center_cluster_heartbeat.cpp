/***************************************************************************
 *
 * Copyright (c) 2016 aishuyu, Inc. All Rights Reserved
 *
 **************************************************************************/



/**
 * @file center_cluster_heartbeat.cpp
 * @author aishuyu(asy5178@163.com)
 * @date 2016/09/07 19:44:39
 * @brief
 *
 **/

#include "center_cluster_heartbeat.h"

#include <unistd.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <linux/kernel.h>

#include <google/protobuf/repeated_field.h>

#include "center_proto/center_cluster.pb.h"
#include "config_parser/config_parser.h"
#include "util/rpc_communication.h"
#include "util/rpc_util.h"

#define random(x) (rand()%x)


namespace libevrpc {

using ::google::protobuf::RepeatedPtrField;
using std::string;

const int32_t sleep_time = 10;

CenterClusterHeartbeat::CenterClusterHeartbeat(const string& config_file) :
    config_file_(config_file),
    center_addrs_ptr_(new ADDRS_LIST_TYPE()),
    reporter_center_addrs_ptr_(new ADDRS_LIST_TYPE()),
    running_(false),
    center_port_(NULL) {
}

CenterClusterHeartbeat::~CenterClusterHeartbeat() {
    if (NULL != center_addrs_ptr_) {
        delete center_addrs_ptr_;
    }

    if (NULL != reporter_center_addrs_ptr_) {
        delete reporter_center_addrs_ptr_;
    }

    if (NULL != center_port_) {
        free(center_port_);
    }
}

bool CenterClusterHeartbeat::InitCenterClusterHB() {
    const string cfile = "/tmp/centers.data";
    int ftyp = access(cfile.c_str(), 0);
    if (0 != ftyp) {
        /*
         * 需要的服务器列表文件不存在，无法初始化后与其他机器进行通信
         * 启动失败!!!
         */
        return false;
    }
    const char* center_port = ConfigParser::GetInstance(config_file_).IniGetString("rpc_center:port", "8899");
    strcpy(center_port_ = (char*)malloc(strlen(center_port) + 1), center_port);

    std::ifstream in(cfile);
    string line;

    const char* local_addr = GetLocalAddress();
    while (getline (in, line)) {
        if (strcmp(line.c_str(), local_addr) == 0) {
            continue;
        }
        center_addrs_ptr_->push_back(line);
    }

    int32_t random_index = random(center_addrs_ptr_->size());

    int32_t conn_fd = TcpConnect(center_addrs_ptr_->at(random_index).c_str(), center_port_, 15);
    if (conn_fd <= 0) {
        return false;
    }

    /*
     * 在RpcCenter注册本地RpcServer, 获取Report机器地址
     */
    RpcClusterServer rcs;
    rcs.set_cluster_action(REGISTER);
    rcs.set_cluster_server_addr(local_addr);

    string rcs_str;
    if (!rcs.SerializeToString(&rcs_str)) {
        return false;
    }
    if (!RpcSend(conn_fd, CENTER2CLUSTER, rcs_str, false)) {
        return false;
    }

    string crc_str;
    if (RpcRecv(conn_fd, crc_str, true) < 0) {
        return false;
    }

    CenterResponseCluster crc_proto;
    if (!crc_proto.ParseFromString(crc_str)) {
        return false;
    }

    RepeatedPtrField<string>* reporter_centers = crc_proto.mutable_should_reporter_center();
    for (RepeatedPtrField<string>::iterator iter = reporter_centers->begin();
         iter != reporter_centers->end();
         ++iter) {
        reporter_center_addrs_ptr_->push_back(std::move(*iter));
    }

    running_ = true;

    return true;
}

void CenterClusterHeartbeat::Run() {
    int32_t rca_size = reporter_center_addrs_ptr_->size();

    if (!InitCenterClusterHB() || 0 == rca_size) {
        fprintf(stderr, "Center Init HeartBeat failed!\n");
        return;
    }

    int32_t random_index = random(rca_size);
    while (running_) {
        int32_t conn_fd = TcpConnect(reporter_center_addrs_ptr_->at(random_index).c_str(), center_port_, 15);
        if (conn_fd < 0) {
            random_index = random(rca_size);
            sleep(sleep_time);
            continue;
        }

        /**
         * 获取本地机器信息 CPU LOAD5等
         */
        struct sysinfo s_info;
        int32_t error_no = sysinfo(&s_info);


        RpcClusterServer rcs_proto;
        rcs_proto.set_cluster_action(CLUSTER_PING);
        rcs_proto.set_cluster_server_addr(GetLocalAddress());
        rcs_proto.set_load(s_info.loads[0]);
        // rcs_proto.set_cpu_used();

        string rcs_str;
        if (!rcs_proto.SerializeToString(&rcs_str)) {
            close(conn_fd);
            continue;
        }
        if (!RpcSend(conn_fd, CENTER2CLUSTER, rcs_str)) {
            // TODO
        }
        close(conn_fd);
    }
}


}  // end of namespace libevrpc
















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
