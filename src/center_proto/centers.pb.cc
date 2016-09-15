// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: centers.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "centers.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace libevrpc {

namespace {

const ::google::protobuf::Descriptor* CentersProto_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CentersProto_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* CenterStatus_descriptor_ = NULL;
const ::google::protobuf::EnumDescriptor* CenterAction_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_centers_2eproto() {
  protobuf_AddDesc_centers_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "centers.proto");
  GOOGLE_CHECK(file != NULL);
  CentersProto_descriptor_ = file->message_type(0);
  static const int CentersProto_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CentersProto, from_center_addr_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CentersProto, center_status_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CentersProto, center_action_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CentersProto, start_time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CentersProto, lc_start_time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CentersProto, logical_clock_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CentersProto, leader_center_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CentersProto, server_infos_list_),
  };
  CentersProto_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CentersProto_descriptor_,
      CentersProto::default_instance_,
      CentersProto_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CentersProto, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CentersProto, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CentersProto));
  CenterStatus_descriptor_ = file->enum_type(0);
  CenterAction_descriptor_ = file->enum_type(1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_centers_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CentersProto_descriptor_, &CentersProto::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_centers_2eproto() {
  delete CentersProto::default_instance_;
  delete CentersProto_reflection_;
}

void protobuf_AddDesc_centers_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::libevrpc::protobuf_AddDesc_center_5ftype_2eproto();
  ::libevrpc::protobuf_AddDesc_center_5fclient_2eproto();
  ::libevrpc::protobuf_AddDesc_rpc_5fcluster_5fserver_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rcenters.proto\022\010libevrpc\032\021center_type.p"
    "roto\032\023center_client.proto\032\030rpc_cluster_s"
    "erver.proto\"\226\002\n\014CentersProto\022\030\n\020from_cen"
    "ter_addr\030\001 \001(\t\022-\n\rcenter_status\030\002 \001(\0162\026."
    "libevrpc.CenterStatus\022-\n\rcenter_action\030\003"
    " \001(\0162\026.libevrpc.CenterAction\022\022\n\nstart_ti"
    "me\030\004 \001(\004\022\025\n\rlc_start_time\030\005 \001(\004\022\025\n\rlogic"
    "al_clock\030\006 \001(\004\022\025\n\rleader_center\030\007 \001(\t\0225\n"
    "\021server_infos_list\030\010 \003(\0132\032.libevrpc.RpcC"
    "lusterServer*\\\n\014CenterStatus\022\013\n\007LOOKING\020"
    "\000\022\r\n\tFOLLOWING\020\001\022\r\n\tOBSERVING\020\002\022\013\n\007LEADI"
    "NG\020\003\022\n\n\006UNKONW\020\004\022\010\n\004DEAD\020\005*i\n\014CenterActi"
    "on\022\013\n\007INQUIRY\020\000\022\014\n\010PROPOSAL\020\001\022\022\n\016LEADER_"
    "CONFIRM\020\002\022\n\n\006ACCEPT\020\003\022\013\n\007REFUSED\020\004\022\021\n\rFO"
    "LLOWER_PING\020\005", 573);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "centers.proto", &protobuf_RegisterTypes);
  CentersProto::default_instance_ = new CentersProto();
  CentersProto::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_centers_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_centers_2eproto {
  StaticDescriptorInitializer_centers_2eproto() {
    protobuf_AddDesc_centers_2eproto();
  }
} static_descriptor_initializer_centers_2eproto_;
const ::google::protobuf::EnumDescriptor* CenterStatus_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CenterStatus_descriptor_;
}
bool CenterStatus_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* CenterAction_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CenterAction_descriptor_;
}
bool CenterAction_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#ifndef _MSC_VER
const int CentersProto::kFromCenterAddrFieldNumber;
const int CentersProto::kCenterStatusFieldNumber;
const int CentersProto::kCenterActionFieldNumber;
const int CentersProto::kStartTimeFieldNumber;
const int CentersProto::kLcStartTimeFieldNumber;
const int CentersProto::kLogicalClockFieldNumber;
const int CentersProto::kLeaderCenterFieldNumber;
const int CentersProto::kServerInfosListFieldNumber;
#endif  // !_MSC_VER

CentersProto::CentersProto()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:libevrpc.CentersProto)
}

void CentersProto::InitAsDefaultInstance() {
}

CentersProto::CentersProto(const CentersProto& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:libevrpc.CentersProto)
}

void CentersProto::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  from_center_addr_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  center_status_ = 0;
  center_action_ = 0;
  start_time_ = GOOGLE_ULONGLONG(0);
  lc_start_time_ = GOOGLE_ULONGLONG(0);
  logical_clock_ = GOOGLE_ULONGLONG(0);
  leader_center_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CentersProto::~CentersProto() {
  // @@protoc_insertion_point(destructor:libevrpc.CentersProto)
  SharedDtor();
}

void CentersProto::SharedDtor() {
  if (from_center_addr_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete from_center_addr_;
  }
  if (leader_center_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete leader_center_;
  }
  if (this != default_instance_) {
  }
}

void CentersProto::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CentersProto::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CentersProto_descriptor_;
}

const CentersProto& CentersProto::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_centers_2eproto();
  return *default_instance_;
}

CentersProto* CentersProto::default_instance_ = NULL;

CentersProto* CentersProto::New() const {
  return new CentersProto;
}

void CentersProto::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<CentersProto*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 127) {
    ZR_(center_status_, logical_clock_);
    if (has_from_center_addr()) {
      if (from_center_addr_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        from_center_addr_->clear();
      }
    }
    if (has_leader_center()) {
      if (leader_center_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        leader_center_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  server_infos_list_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CentersProto::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:libevrpc.CentersProto)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string from_center_addr = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_from_center_addr()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->from_center_addr().data(), this->from_center_addr().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "from_center_addr");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_center_status;
        break;
      }

      // optional .libevrpc.CenterStatus center_status = 2;
      case 2: {
        if (tag == 16) {
         parse_center_status:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::libevrpc::CenterStatus_IsValid(value)) {
            set_center_status(static_cast< ::libevrpc::CenterStatus >(value));
          } else {
            mutable_unknown_fields()->AddVarint(2, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_center_action;
        break;
      }

      // optional .libevrpc.CenterAction center_action = 3;
      case 3: {
        if (tag == 24) {
         parse_center_action:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::libevrpc::CenterAction_IsValid(value)) {
            set_center_action(static_cast< ::libevrpc::CenterAction >(value));
          } else {
            mutable_unknown_fields()->AddVarint(3, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_start_time;
        break;
      }

      // optional uint64 start_time = 4;
      case 4: {
        if (tag == 32) {
         parse_start_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &start_time_)));
          set_has_start_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_lc_start_time;
        break;
      }

      // optional uint64 lc_start_time = 5;
      case 5: {
        if (tag == 40) {
         parse_lc_start_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &lc_start_time_)));
          set_has_lc_start_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_logical_clock;
        break;
      }

      // optional uint64 logical_clock = 6;
      case 6: {
        if (tag == 48) {
         parse_logical_clock:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &logical_clock_)));
          set_has_logical_clock();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_leader_center;
        break;
      }

      // optional string leader_center = 7;
      case 7: {
        if (tag == 58) {
         parse_leader_center:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_leader_center()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->leader_center().data(), this->leader_center().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "leader_center");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_server_infos_list;
        break;
      }

      // repeated .libevrpc.RpcClusterServer server_infos_list = 8;
      case 8: {
        if (tag == 66) {
         parse_server_infos_list:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_server_infos_list()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_server_infos_list;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:libevrpc.CentersProto)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:libevrpc.CentersProto)
  return false;
#undef DO_
}

void CentersProto::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:libevrpc.CentersProto)
  // optional string from_center_addr = 1;
  if (has_from_center_addr()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->from_center_addr().data(), this->from_center_addr().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "from_center_addr");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->from_center_addr(), output);
  }

  // optional .libevrpc.CenterStatus center_status = 2;
  if (has_center_status()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->center_status(), output);
  }

  // optional .libevrpc.CenterAction center_action = 3;
  if (has_center_action()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      3, this->center_action(), output);
  }

  // optional uint64 start_time = 4;
  if (has_start_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(4, this->start_time(), output);
  }

  // optional uint64 lc_start_time = 5;
  if (has_lc_start_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(5, this->lc_start_time(), output);
  }

  // optional uint64 logical_clock = 6;
  if (has_logical_clock()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(6, this->logical_clock(), output);
  }

  // optional string leader_center = 7;
  if (has_leader_center()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->leader_center().data(), this->leader_center().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "leader_center");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      7, this->leader_center(), output);
  }

  // repeated .libevrpc.RpcClusterServer server_infos_list = 8;
  for (int i = 0; i < this->server_infos_list_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      8, this->server_infos_list(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:libevrpc.CentersProto)
}

::google::protobuf::uint8* CentersProto::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:libevrpc.CentersProto)
  // optional string from_center_addr = 1;
  if (has_from_center_addr()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->from_center_addr().data(), this->from_center_addr().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "from_center_addr");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->from_center_addr(), target);
  }

  // optional .libevrpc.CenterStatus center_status = 2;
  if (has_center_status()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->center_status(), target);
  }

  // optional .libevrpc.CenterAction center_action = 3;
  if (has_center_action()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      3, this->center_action(), target);
  }

  // optional uint64 start_time = 4;
  if (has_start_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(4, this->start_time(), target);
  }

  // optional uint64 lc_start_time = 5;
  if (has_lc_start_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(5, this->lc_start_time(), target);
  }

  // optional uint64 logical_clock = 6;
  if (has_logical_clock()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(6, this->logical_clock(), target);
  }

  // optional string leader_center = 7;
  if (has_leader_center()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->leader_center().data(), this->leader_center().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "leader_center");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        7, this->leader_center(), target);
  }

  // repeated .libevrpc.RpcClusterServer server_infos_list = 8;
  for (int i = 0; i < this->server_infos_list_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        8, this->server_infos_list(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:libevrpc.CentersProto)
  return target;
}

int CentersProto::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string from_center_addr = 1;
    if (has_from_center_addr()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->from_center_addr());
    }

    // optional .libevrpc.CenterStatus center_status = 2;
    if (has_center_status()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->center_status());
    }

    // optional .libevrpc.CenterAction center_action = 3;
    if (has_center_action()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->center_action());
    }

    // optional uint64 start_time = 4;
    if (has_start_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->start_time());
    }

    // optional uint64 lc_start_time = 5;
    if (has_lc_start_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->lc_start_time());
    }

    // optional uint64 logical_clock = 6;
    if (has_logical_clock()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->logical_clock());
    }

    // optional string leader_center = 7;
    if (has_leader_center()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->leader_center());
    }

  }
  // repeated .libevrpc.RpcClusterServer server_infos_list = 8;
  total_size += 1 * this->server_infos_list_size();
  for (int i = 0; i < this->server_infos_list_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->server_infos_list(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CentersProto::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CentersProto* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CentersProto*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CentersProto::MergeFrom(const CentersProto& from) {
  GOOGLE_CHECK_NE(&from, this);
  server_infos_list_.MergeFrom(from.server_infos_list_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_from_center_addr()) {
      set_from_center_addr(from.from_center_addr());
    }
    if (from.has_center_status()) {
      set_center_status(from.center_status());
    }
    if (from.has_center_action()) {
      set_center_action(from.center_action());
    }
    if (from.has_start_time()) {
      set_start_time(from.start_time());
    }
    if (from.has_lc_start_time()) {
      set_lc_start_time(from.lc_start_time());
    }
    if (from.has_logical_clock()) {
      set_logical_clock(from.logical_clock());
    }
    if (from.has_leader_center()) {
      set_leader_center(from.leader_center());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CentersProto::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CentersProto::CopyFrom(const CentersProto& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CentersProto::IsInitialized() const {

  return true;
}

void CentersProto::Swap(CentersProto* other) {
  if (other != this) {
    std::swap(from_center_addr_, other->from_center_addr_);
    std::swap(center_status_, other->center_status_);
    std::swap(center_action_, other->center_action_);
    std::swap(start_time_, other->start_time_);
    std::swap(lc_start_time_, other->lc_start_time_);
    std::swap(logical_clock_, other->logical_clock_);
    std::swap(leader_center_, other->leader_center_);
    server_infos_list_.Swap(&other->server_infos_list_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CentersProto::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CentersProto_descriptor_;
  metadata.reflection = CentersProto_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace libevrpc

// @@protoc_insertion_point(global_scope)
