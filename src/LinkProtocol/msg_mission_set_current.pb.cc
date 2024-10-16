// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msg_mission_set_current.proto

#include "msg_mission_set_current.pb.h"

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

inline constexpr MissionSetCurrent::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : seq_{0},
        reset_{false},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR MissionSetCurrent::MissionSetCurrent(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct MissionSetCurrentDefaultTypeInternal {
  PROTOBUF_CONSTEXPR MissionSetCurrentDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~MissionSetCurrentDefaultTypeInternal() {}
  union {
    MissionSetCurrent _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 MissionSetCurrentDefaultTypeInternal _MissionSetCurrent_default_instance_;
}  // namespace UsvLink
static ::_pb::Metadata file_level_metadata_msg_5fmission_5fset_5fcurrent_2eproto[1];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_msg_5fmission_5fset_5fcurrent_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_msg_5fmission_5fset_5fcurrent_2eproto = nullptr;
const ::uint32_t TableStruct_msg_5fmission_5fset_5fcurrent_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::UsvLink::MissionSetCurrent, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::UsvLink::MissionSetCurrent, _impl_.seq_),
    PROTOBUF_FIELD_OFFSET(::UsvLink::MissionSetCurrent, _impl_.reset_),
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::UsvLink::MissionSetCurrent)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::UsvLink::_MissionSetCurrent_default_instance_._instance,
};
const char descriptor_table_protodef_msg_5fmission_5fset_5fcurrent_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\035msg_mission_set_current.proto\022\007UsvLink"
    "\"/\n\021MissionSetCurrent\022\013\n\003seq\030\001 \001(\005\022\r\n\005re"
    "set\030\002 \001(\010b\006proto3"
};
static ::absl::once_flag descriptor_table_msg_5fmission_5fset_5fcurrent_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_msg_5fmission_5fset_5fcurrent_2eproto = {
    false,
    false,
    97,
    descriptor_table_protodef_msg_5fmission_5fset_5fcurrent_2eproto,
    "msg_mission_set_current.proto",
    &descriptor_table_msg_5fmission_5fset_5fcurrent_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_msg_5fmission_5fset_5fcurrent_2eproto::offsets,
    file_level_metadata_msg_5fmission_5fset_5fcurrent_2eproto,
    file_level_enum_descriptors_msg_5fmission_5fset_5fcurrent_2eproto,
    file_level_service_descriptors_msg_5fmission_5fset_5fcurrent_2eproto,
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
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_msg_5fmission_5fset_5fcurrent_2eproto_getter() {
  return &descriptor_table_msg_5fmission_5fset_5fcurrent_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_msg_5fmission_5fset_5fcurrent_2eproto(&descriptor_table_msg_5fmission_5fset_5fcurrent_2eproto);
namespace UsvLink {
// ===================================================================

class MissionSetCurrent::_Internal {
 public:
};

MissionSetCurrent::MissionSetCurrent(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:UsvLink.MissionSetCurrent)
}
MissionSetCurrent::MissionSetCurrent(
    ::google::protobuf::Arena* arena, const MissionSetCurrent& from)
    : MissionSetCurrent(arena) {
  MergeFrom(from);
}
inline PROTOBUF_NDEBUG_INLINE MissionSetCurrent::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0} {}

inline void MissionSetCurrent::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, seq_),
           0,
           offsetof(Impl_, reset_) -
               offsetof(Impl_, seq_) +
               sizeof(Impl_::reset_));
}
MissionSetCurrent::~MissionSetCurrent() {
  // @@protoc_insertion_point(destructor:UsvLink.MissionSetCurrent)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void MissionSetCurrent::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.~Impl_();
}

PROTOBUF_NOINLINE void MissionSetCurrent::Clear() {
// @@protoc_insertion_point(message_clear_start:UsvLink.MissionSetCurrent)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.seq_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.reset_) -
      reinterpret_cast<char*>(&_impl_.seq_)) + sizeof(_impl_.reset_));
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* MissionSetCurrent::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 0, 0, 2> MissionSetCurrent::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_MissionSetCurrent_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    // bool reset = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<bool, offsetof(MissionSetCurrent, _impl_.reset_), 63>(),
     {16, 63, 0, PROTOBUF_FIELD_OFFSET(MissionSetCurrent, _impl_.reset_)}},
    // int32 seq = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(MissionSetCurrent, _impl_.seq_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(MissionSetCurrent, _impl_.seq_)}},
  }}, {{
    65535, 65535
  }}, {{
    // int32 seq = 1;
    {PROTOBUF_FIELD_OFFSET(MissionSetCurrent, _impl_.seq_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
    // bool reset = 2;
    {PROTOBUF_FIELD_OFFSET(MissionSetCurrent, _impl_.reset_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBool)},
  }},
  // no aux_entries
  {{
  }},
};

::uint8_t* MissionSetCurrent::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:UsvLink.MissionSetCurrent)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // int32 seq = 1;
  if (this->_internal_seq() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<1>(
            stream, this->_internal_seq(), target);
  }

  // bool reset = 2;
  if (this->_internal_reset() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(
        2, this->_internal_reset(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:UsvLink.MissionSetCurrent)
  return target;
}

::size_t MissionSetCurrent::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:UsvLink.MissionSetCurrent)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 seq = 1;
  if (this->_internal_seq() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
        this->_internal_seq());
  }

  // bool reset = 2;
  if (this->_internal_reset() != 0) {
    total_size += 2;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData MissionSetCurrent::_class_data_ = {
    MissionSetCurrent::MergeImpl,
    nullptr,  // OnDemandRegisterArenaDtor
};
const ::google::protobuf::Message::ClassData* MissionSetCurrent::GetClassData() const {
  return &_class_data_;
}

void MissionSetCurrent::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<MissionSetCurrent*>(&to_msg);
  auto& from = static_cast<const MissionSetCurrent&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:UsvLink.MissionSetCurrent)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_seq() != 0) {
    _this->_internal_set_seq(from._internal_seq());
  }
  if (from._internal_reset() != 0) {
    _this->_internal_set_reset(from._internal_reset());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void MissionSetCurrent::CopyFrom(const MissionSetCurrent& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:UsvLink.MissionSetCurrent)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool MissionSetCurrent::IsInitialized() const {
  return true;
}

::_pbi::CachedSize* MissionSetCurrent::AccessCachedSize() const {
  return &_impl_._cached_size_;
}
void MissionSetCurrent::InternalSwap(MissionSetCurrent* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(MissionSetCurrent, _impl_.reset_)
      + sizeof(MissionSetCurrent::_impl_.reset_)
      - PROTOBUF_FIELD_OFFSET(MissionSetCurrent, _impl_.seq_)>(
          reinterpret_cast<char*>(&_impl_.seq_),
          reinterpret_cast<char*>(&other->_impl_.seq_));
}

::google::protobuf::Metadata MissionSetCurrent::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_msg_5fmission_5fset_5fcurrent_2eproto_getter, &descriptor_table_msg_5fmission_5fset_5fcurrent_2eproto_once,
      file_level_metadata_msg_5fmission_5fset_5fcurrent_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace UsvLink
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"
