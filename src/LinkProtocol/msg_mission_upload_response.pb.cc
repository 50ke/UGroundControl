// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msg_mission_upload_response.proto

#include "msg_mission_upload_response.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace UsvLink {

inline constexpr MissionUploadResponse::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        err_msg_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        ack_{0},
        opaque_id_{0} {}

template <typename>
PROTOBUF_CONSTEXPR MissionUploadResponse::MissionUploadResponse(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct MissionUploadResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR MissionUploadResponseDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~MissionUploadResponseDefaultTypeInternal() {}
  union {
    MissionUploadResponse _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 MissionUploadResponseDefaultTypeInternal _MissionUploadResponse_default_instance_;
}  // namespace UsvLink
static ::_pb::Metadata file_level_metadata_msg_5fmission_5fupload_5fresponse_2eproto[1];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_msg_5fmission_5fupload_5fresponse_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_msg_5fmission_5fupload_5fresponse_2eproto = nullptr;
const ::uint32_t TableStruct_msg_5fmission_5fupload_5fresponse_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    PROTOBUF_FIELD_OFFSET(::UsvLink::MissionUploadResponse, _impl_._has_bits_),
    PROTOBUF_FIELD_OFFSET(::UsvLink::MissionUploadResponse, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::UsvLink::MissionUploadResponse, _impl_.ack_),
    PROTOBUF_FIELD_OFFSET(::UsvLink::MissionUploadResponse, _impl_.err_msg_),
    PROTOBUF_FIELD_OFFSET(::UsvLink::MissionUploadResponse, _impl_.opaque_id_),
    ~0u,
    0,
    1,
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, 11, -1, sizeof(::UsvLink::MissionUploadResponse)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::UsvLink::_MissionUploadResponse_default_instance_._instance,
};
const char descriptor_table_protodef_msg_5fmission_5fupload_5fresponse_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n!msg_mission_upload_response.proto\022\007Usv"
    "Link\"l\n\025MissionUploadResponse\022\013\n\003ack\030\001 \001"
    "(\005\022\024\n\007err_msg\030\002 \001(\tH\000\210\001\001\022\026\n\topaque_id\030\003 "
    "\001(\005H\001\210\001\001B\n\n\010_err_msgB\014\n\n_opaque_idb\006prot"
    "o3"
};
static ::absl::once_flag descriptor_table_msg_5fmission_5fupload_5fresponse_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_msg_5fmission_5fupload_5fresponse_2eproto = {
    false,
    false,
    162,
    descriptor_table_protodef_msg_5fmission_5fupload_5fresponse_2eproto,
    "msg_mission_upload_response.proto",
    &descriptor_table_msg_5fmission_5fupload_5fresponse_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_msg_5fmission_5fupload_5fresponse_2eproto::offsets,
    file_level_metadata_msg_5fmission_5fupload_5fresponse_2eproto,
    file_level_enum_descriptors_msg_5fmission_5fupload_5fresponse_2eproto,
    file_level_service_descriptors_msg_5fmission_5fupload_5fresponse_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_msg_5fmission_5fupload_5fresponse_2eproto_getter() {
  return &descriptor_table_msg_5fmission_5fupload_5fresponse_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_msg_5fmission_5fupload_5fresponse_2eproto(&descriptor_table_msg_5fmission_5fupload_5fresponse_2eproto);
namespace UsvLink {
// ===================================================================

class MissionUploadResponse::_Internal {
 public:
  using HasBits = decltype(std::declval<MissionUploadResponse>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(MissionUploadResponse, _impl_._has_bits_);
  static void set_has_err_msg(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_opaque_id(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

MissionUploadResponse::MissionUploadResponse(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:UsvLink.MissionUploadResponse)
}
inline PROTOBUF_NDEBUG_INLINE MissionUploadResponse::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        err_msg_(arena, from.err_msg_) {}

MissionUploadResponse::MissionUploadResponse(
    ::google::protobuf::Arena* arena,
    const MissionUploadResponse& from)
    : ::google::protobuf::Message(arena) {
  MissionUploadResponse* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  ::memcpy(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, ack_),
           reinterpret_cast<const char *>(&from._impl_) +
               offsetof(Impl_, ack_),
           offsetof(Impl_, opaque_id_) -
               offsetof(Impl_, ack_) +
               sizeof(Impl_::opaque_id_));

  // @@protoc_insertion_point(copy_constructor:UsvLink.MissionUploadResponse)
}
inline PROTOBUF_NDEBUG_INLINE MissionUploadResponse::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        err_msg_(arena) {}

inline void MissionUploadResponse::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, ack_),
           0,
           offsetof(Impl_, opaque_id_) -
               offsetof(Impl_, ack_) +
               sizeof(Impl_::opaque_id_));
}
MissionUploadResponse::~MissionUploadResponse() {
  // @@protoc_insertion_point(destructor:UsvLink.MissionUploadResponse)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void MissionUploadResponse::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.err_msg_.Destroy();
  _impl_.~Impl_();
}

PROTOBUF_NOINLINE void MissionUploadResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:UsvLink.MissionUploadResponse)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    _impl_.err_msg_.ClearNonDefaultToEmpty();
  }
  _impl_.ack_ = 0;
  _impl_.opaque_id_ = 0;
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* MissionUploadResponse::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<2, 3, 0, 45, 2> MissionUploadResponse::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(MissionUploadResponse, _impl_._has_bits_),
    0, // no _extensions_
    3, 24,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967288,  // skipmap
    offsetof(decltype(_table_), field_entries),
    3,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_MissionUploadResponse_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // int32 ack = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(MissionUploadResponse, _impl_.ack_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(MissionUploadResponse, _impl_.ack_)}},
    // optional string err_msg = 2;
    {::_pbi::TcParser::FastUS1,
     {18, 0, 0, PROTOBUF_FIELD_OFFSET(MissionUploadResponse, _impl_.err_msg_)}},
    // optional int32 opaque_id = 3;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(MissionUploadResponse, _impl_.opaque_id_), 1>(),
     {24, 1, 0, PROTOBUF_FIELD_OFFSET(MissionUploadResponse, _impl_.opaque_id_)}},
  }}, {{
    65535, 65535
  }}, {{
    // int32 ack = 1;
    {PROTOBUF_FIELD_OFFSET(MissionUploadResponse, _impl_.ack_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
    // optional string err_msg = 2;
    {PROTOBUF_FIELD_OFFSET(MissionUploadResponse, _impl_.err_msg_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // optional int32 opaque_id = 3;
    {PROTOBUF_FIELD_OFFSET(MissionUploadResponse, _impl_.opaque_id_), _Internal::kHasBitsOffset + 1, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
  }},
  // no aux_entries
  {{
    "\35\0\7\0\0\0\0\0"
    "UsvLink.MissionUploadResponse"
    "err_msg"
  }},
};

::uint8_t* MissionUploadResponse::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:UsvLink.MissionUploadResponse)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // int32 ack = 1;
  if (this->_internal_ack() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<1>(
            stream, this->_internal_ack(), target);
  }

  cached_has_bits = _impl_._has_bits_[0];
  // optional string err_msg = 2;
  if (cached_has_bits & 0x00000001u) {
    const std::string& _s = this->_internal_err_msg();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "UsvLink.MissionUploadResponse.err_msg");
    target = stream->WriteStringMaybeAliased(2, _s, target);
  }

  // optional int32 opaque_id = 3;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<3>(
            stream, this->_internal_opaque_id(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:UsvLink.MissionUploadResponse)
  return target;
}

::size_t MissionUploadResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:UsvLink.MissionUploadResponse)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional string err_msg = 2;
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_err_msg());
  }

  // int32 ack = 1;
  if (this->_internal_ack() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
        this->_internal_ack());
  }

  // optional int32 opaque_id = 3;
  if (cached_has_bits & 0x00000002u) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
        this->_internal_opaque_id());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData MissionUploadResponse::_class_data_ = {
    MissionUploadResponse::MergeImpl,
    nullptr,  // OnDemandRegisterArenaDtor
};
const ::google::protobuf::Message::ClassData* MissionUploadResponse::GetClassData() const {
  return &_class_data_;
}

void MissionUploadResponse::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<MissionUploadResponse*>(&to_msg);
  auto& from = static_cast<const MissionUploadResponse&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:UsvLink.MissionUploadResponse)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if ((from._impl_._has_bits_[0] & 0x00000001u) != 0) {
    _this->_internal_set_err_msg(from._internal_err_msg());
  }
  if (from._internal_ack() != 0) {
    _this->_internal_set_ack(from._internal_ack());
  }
  if ((from._impl_._has_bits_[0] & 0x00000002u) != 0) {
    _this->_internal_set_opaque_id(from._internal_opaque_id());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void MissionUploadResponse::CopyFrom(const MissionUploadResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:UsvLink.MissionUploadResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool MissionUploadResponse::IsInitialized() const {
  return true;
}

::_pbi::CachedSize* MissionUploadResponse::AccessCachedSize() const {
  return &_impl_._cached_size_;
}
void MissionUploadResponse::InternalSwap(MissionUploadResponse* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.err_msg_, &other->_impl_.err_msg_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(MissionUploadResponse, _impl_.opaque_id_)
      + sizeof(MissionUploadResponse::_impl_.opaque_id_)
      - PROTOBUF_FIELD_OFFSET(MissionUploadResponse, _impl_.ack_)>(
          reinterpret_cast<char*>(&_impl_.ack_),
          reinterpret_cast<char*>(&other->_impl_.ack_));
}

::google::protobuf::Metadata MissionUploadResponse::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_msg_5fmission_5fupload_5fresponse_2eproto_getter, &descriptor_table_msg_5fmission_5fupload_5fresponse_2eproto_once,
      file_level_metadata_msg_5fmission_5fupload_5fresponse_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace UsvLink
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"
