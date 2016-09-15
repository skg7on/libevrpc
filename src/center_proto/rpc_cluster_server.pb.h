// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rpc_cluster_server.proto

#ifndef PROTOBUF_rpc_5fcluster_5fserver_2eproto__INCLUDED
#define PROTOBUF_rpc_5fcluster_5fserver_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "center_type.pb.h"
// @@protoc_insertion_point(includes)

namespace libevrpc {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_rpc_5fcluster_5fserver_2eproto();
void protobuf_AssignDesc_rpc_5fcluster_5fserver_2eproto();
void protobuf_ShutdownFile_rpc_5fcluster_5fserver_2eproto();

class RpcClusterServer;

// ===================================================================

class RpcClusterServer : public ::google::protobuf::Message {
 public:
  RpcClusterServer();
  virtual ~RpcClusterServer();

  RpcClusterServer(const RpcClusterServer& from);

  inline RpcClusterServer& operator=(const RpcClusterServer& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const RpcClusterServer& default_instance();

  void Swap(RpcClusterServer* other);

  // implements Message ----------------------------------------------

  RpcClusterServer* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const RpcClusterServer& from);
  void MergeFrom(const RpcClusterServer& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string cluster_server_addr = 1;
  inline bool has_cluster_server_addr() const;
  inline void clear_cluster_server_addr();
  static const int kClusterServerAddrFieldNumber = 1;
  inline const ::std::string& cluster_server_addr() const;
  inline void set_cluster_server_addr(const ::std::string& value);
  inline void set_cluster_server_addr(const char* value);
  inline void set_cluster_server_addr(const char* value, size_t size);
  inline ::std::string* mutable_cluster_server_addr();
  inline ::std::string* release_cluster_server_addr();
  inline void set_allocated_cluster_server_addr(::std::string* cluster_server_addr);

  // optional float load = 2;
  inline bool has_load() const;
  inline void clear_load();
  static const int kLoadFieldNumber = 2;
  inline float load() const;
  inline void set_load(float value);

  // optional float cpu_used = 3;
  inline bool has_cpu_used() const;
  inline void clear_cpu_used();
  static const int kCpuUsedFieldNumber = 3;
  inline float cpu_used() const;
  inline void set_cpu_used(float value);

  // optional int32 connection_num = 4;
  inline bool has_connection_num() const;
  inline void clear_connection_num();
  static const int kConnectionNumFieldNumber = 4;
  inline ::google::protobuf::int32 connection_num() const;
  inline void set_connection_num(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:libevrpc.RpcClusterServer)
 private:
  inline void set_has_cluster_server_addr();
  inline void clear_has_cluster_server_addr();
  inline void set_has_load();
  inline void clear_has_load();
  inline void set_has_cpu_used();
  inline void clear_has_cpu_used();
  inline void set_has_connection_num();
  inline void clear_has_connection_num();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* cluster_server_addr_;
  float load_;
  float cpu_used_;
  ::google::protobuf::int32 connection_num_;
  friend void  protobuf_AddDesc_rpc_5fcluster_5fserver_2eproto();
  friend void protobuf_AssignDesc_rpc_5fcluster_5fserver_2eproto();
  friend void protobuf_ShutdownFile_rpc_5fcluster_5fserver_2eproto();

  void InitAsDefaultInstance();
  static RpcClusterServer* default_instance_;
};
// ===================================================================


// ===================================================================

// RpcClusterServer

// optional string cluster_server_addr = 1;
inline bool RpcClusterServer::has_cluster_server_addr() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void RpcClusterServer::set_has_cluster_server_addr() {
  _has_bits_[0] |= 0x00000001u;
}
inline void RpcClusterServer::clear_has_cluster_server_addr() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void RpcClusterServer::clear_cluster_server_addr() {
  if (cluster_server_addr_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    cluster_server_addr_->clear();
  }
  clear_has_cluster_server_addr();
}
inline const ::std::string& RpcClusterServer::cluster_server_addr() const {
  // @@protoc_insertion_point(field_get:libevrpc.RpcClusterServer.cluster_server_addr)
  return *cluster_server_addr_;
}
inline void RpcClusterServer::set_cluster_server_addr(const ::std::string& value) {
  set_has_cluster_server_addr();
  if (cluster_server_addr_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    cluster_server_addr_ = new ::std::string;
  }
  cluster_server_addr_->assign(value);
  // @@protoc_insertion_point(field_set:libevrpc.RpcClusterServer.cluster_server_addr)
}
inline void RpcClusterServer::set_cluster_server_addr(const char* value) {
  set_has_cluster_server_addr();
  if (cluster_server_addr_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    cluster_server_addr_ = new ::std::string;
  }
  cluster_server_addr_->assign(value);
  // @@protoc_insertion_point(field_set_char:libevrpc.RpcClusterServer.cluster_server_addr)
}
inline void RpcClusterServer::set_cluster_server_addr(const char* value, size_t size) {
  set_has_cluster_server_addr();
  if (cluster_server_addr_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    cluster_server_addr_ = new ::std::string;
  }
  cluster_server_addr_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:libevrpc.RpcClusterServer.cluster_server_addr)
}
inline ::std::string* RpcClusterServer::mutable_cluster_server_addr() {
  set_has_cluster_server_addr();
  if (cluster_server_addr_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    cluster_server_addr_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:libevrpc.RpcClusterServer.cluster_server_addr)
  return cluster_server_addr_;
}
inline ::std::string* RpcClusterServer::release_cluster_server_addr() {
  clear_has_cluster_server_addr();
  if (cluster_server_addr_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = cluster_server_addr_;
    cluster_server_addr_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void RpcClusterServer::set_allocated_cluster_server_addr(::std::string* cluster_server_addr) {
  if (cluster_server_addr_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete cluster_server_addr_;
  }
  if (cluster_server_addr) {
    set_has_cluster_server_addr();
    cluster_server_addr_ = cluster_server_addr;
  } else {
    clear_has_cluster_server_addr();
    cluster_server_addr_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:libevrpc.RpcClusterServer.cluster_server_addr)
}

// optional float load = 2;
inline bool RpcClusterServer::has_load() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void RpcClusterServer::set_has_load() {
  _has_bits_[0] |= 0x00000002u;
}
inline void RpcClusterServer::clear_has_load() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void RpcClusterServer::clear_load() {
  load_ = 0;
  clear_has_load();
}
inline float RpcClusterServer::load() const {
  // @@protoc_insertion_point(field_get:libevrpc.RpcClusterServer.load)
  return load_;
}
inline void RpcClusterServer::set_load(float value) {
  set_has_load();
  load_ = value;
  // @@protoc_insertion_point(field_set:libevrpc.RpcClusterServer.load)
}

// optional float cpu_used = 3;
inline bool RpcClusterServer::has_cpu_used() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void RpcClusterServer::set_has_cpu_used() {
  _has_bits_[0] |= 0x00000004u;
}
inline void RpcClusterServer::clear_has_cpu_used() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void RpcClusterServer::clear_cpu_used() {
  cpu_used_ = 0;
  clear_has_cpu_used();
}
inline float RpcClusterServer::cpu_used() const {
  // @@protoc_insertion_point(field_get:libevrpc.RpcClusterServer.cpu_used)
  return cpu_used_;
}
inline void RpcClusterServer::set_cpu_used(float value) {
  set_has_cpu_used();
  cpu_used_ = value;
  // @@protoc_insertion_point(field_set:libevrpc.RpcClusterServer.cpu_used)
}

// optional int32 connection_num = 4;
inline bool RpcClusterServer::has_connection_num() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void RpcClusterServer::set_has_connection_num() {
  _has_bits_[0] |= 0x00000008u;
}
inline void RpcClusterServer::clear_has_connection_num() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void RpcClusterServer::clear_connection_num() {
  connection_num_ = 0;
  clear_has_connection_num();
}
inline ::google::protobuf::int32 RpcClusterServer::connection_num() const {
  // @@protoc_insertion_point(field_get:libevrpc.RpcClusterServer.connection_num)
  return connection_num_;
}
inline void RpcClusterServer::set_connection_num(::google::protobuf::int32 value) {
  set_has_connection_num();
  connection_num_ = value;
  // @@protoc_insertion_point(field_set:libevrpc.RpcClusterServer.connection_num)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace libevrpc

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_rpc_5fcluster_5fserver_2eproto__INCLUDED
