// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msg_param_read_response.proto
// Protobuf C++ Version: 4.25.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_msg_5fparam_5fread_5fresponse_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_msg_5fparam_5fread_5fresponse_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4025000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4025001 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
#include "msg_param_item.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_msg_5fparam_5fread_5fresponse_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_msg_5fparam_5fread_5fresponse_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_msg_5fparam_5fread_5fresponse_2eproto;
namespace UsvLink {
class ParamReadResponse;
struct ParamReadResponseDefaultTypeInternal;
extern ParamReadResponseDefaultTypeInternal _ParamReadResponse_default_instance_;
}  // namespace UsvLink
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace UsvLink {

// ===================================================================


// -------------------------------------------------------------------

class ParamReadResponse final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:UsvLink.ParamReadResponse) */ {
 public:
  inline ParamReadResponse() : ParamReadResponse(nullptr) {}
  ~ParamReadResponse() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR ParamReadResponse(::google::protobuf::internal::ConstantInitialized);

  inline ParamReadResponse(const ParamReadResponse& from)
      : ParamReadResponse(nullptr, from) {}
  ParamReadResponse(ParamReadResponse&& from) noexcept
    : ParamReadResponse() {
    *this = ::std::move(from);
  }

  inline ParamReadResponse& operator=(const ParamReadResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline ParamReadResponse& operator=(ParamReadResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const ParamReadResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const ParamReadResponse* internal_default_instance() {
    return reinterpret_cast<const ParamReadResponse*>(
               &_ParamReadResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ParamReadResponse& a, ParamReadResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(ParamReadResponse* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ParamReadResponse* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ParamReadResponse* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<ParamReadResponse>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const ParamReadResponse& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const ParamReadResponse& from) {
    ParamReadResponse::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(ParamReadResponse* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "UsvLink.ParamReadResponse";
  }
  protected:
  explicit ParamReadResponse(::google::protobuf::Arena* arena);
  ParamReadResponse(::google::protobuf::Arena* arena, const ParamReadResponse& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kParamItemsFieldNumber = 3,
    kErrMsgFieldNumber = 2,
    kAckFieldNumber = 1,
  };
  // repeated .UsvLink.ParamItem param_items = 3;
  int param_items_size() const;
  private:
  int _internal_param_items_size() const;

  public:
  void clear_param_items() ;
  ::UsvLink::ParamItem* mutable_param_items(int index);
  ::google::protobuf::RepeatedPtrField< ::UsvLink::ParamItem >*
      mutable_param_items();
  private:
  const ::google::protobuf::RepeatedPtrField<::UsvLink::ParamItem>& _internal_param_items() const;
  ::google::protobuf::RepeatedPtrField<::UsvLink::ParamItem>* _internal_mutable_param_items();
  public:
  const ::UsvLink::ParamItem& param_items(int index) const;
  ::UsvLink::ParamItem* add_param_items();
  const ::google::protobuf::RepeatedPtrField< ::UsvLink::ParamItem >&
      param_items() const;
  // optional string err_msg = 2;
  bool has_err_msg() const;
  void clear_err_msg() ;
  const std::string& err_msg() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_err_msg(Arg_&& arg, Args_... args);
  std::string* mutable_err_msg();
  PROTOBUF_NODISCARD std::string* release_err_msg();
  void set_allocated_err_msg(std::string* value);

  private:
  const std::string& _internal_err_msg() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_err_msg(
      const std::string& value);
  std::string* _internal_mutable_err_msg();

  public:
  // int32 ack = 1;
  void clear_ack() ;
  ::int32_t ack() const;
  void set_ack(::int32_t value);

  private:
  ::int32_t _internal_ack() const;
  void _internal_set_ack(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:UsvLink.ParamReadResponse)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 3, 1,
      41, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::google::protobuf::RepeatedPtrField< ::UsvLink::ParamItem > param_items_;
    ::google::protobuf::internal::ArenaStringPtr err_msg_;
    ::int32_t ack_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_msg_5fparam_5fread_5fresponse_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// ParamReadResponse

// int32 ack = 1;
inline void ParamReadResponse::clear_ack() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.ack_ = 0;
}
inline ::int32_t ParamReadResponse::ack() const {
  // @@protoc_insertion_point(field_get:UsvLink.ParamReadResponse.ack)
  return _internal_ack();
}
inline void ParamReadResponse::set_ack(::int32_t value) {
  _internal_set_ack(value);
  // @@protoc_insertion_point(field_set:UsvLink.ParamReadResponse.ack)
}
inline ::int32_t ParamReadResponse::_internal_ack() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.ack_;
}
inline void ParamReadResponse::_internal_set_ack(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.ack_ = value;
}

// optional string err_msg = 2;
inline bool ParamReadResponse::has_err_msg() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void ParamReadResponse::clear_err_msg() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.err_msg_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& ParamReadResponse::err_msg() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:UsvLink.ParamReadResponse.err_msg)
  return _internal_err_msg();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void ParamReadResponse::set_err_msg(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.err_msg_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:UsvLink.ParamReadResponse.err_msg)
}
inline std::string* ParamReadResponse::mutable_err_msg() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_err_msg();
  // @@protoc_insertion_point(field_mutable:UsvLink.ParamReadResponse.err_msg)
  return _s;
}
inline const std::string& ParamReadResponse::_internal_err_msg() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.err_msg_.Get();
}
inline void ParamReadResponse::_internal_set_err_msg(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.err_msg_.Set(value, GetArena());
}
inline std::string* ParamReadResponse::_internal_mutable_err_msg() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.err_msg_.Mutable( GetArena());
}
inline std::string* ParamReadResponse::release_err_msg() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:UsvLink.ParamReadResponse.err_msg)
  if ((_impl_._has_bits_[0] & 0x00000001u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* released = _impl_.err_msg_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.err_msg_.Set("", GetArena());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void ParamReadResponse::set_allocated_err_msg(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.err_msg_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.err_msg_.IsDefault()) {
          _impl_.err_msg_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:UsvLink.ParamReadResponse.err_msg)
}

// repeated .UsvLink.ParamItem param_items = 3;
inline int ParamReadResponse::_internal_param_items_size() const {
  return _internal_param_items().size();
}
inline int ParamReadResponse::param_items_size() const {
  return _internal_param_items_size();
}
inline ::UsvLink::ParamItem* ParamReadResponse::mutable_param_items(int index)
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable:UsvLink.ParamReadResponse.param_items)
  return _internal_mutable_param_items()->Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField<::UsvLink::ParamItem>* ParamReadResponse::mutable_param_items()
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable_list:UsvLink.ParamReadResponse.param_items)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _internal_mutable_param_items();
}
inline const ::UsvLink::ParamItem& ParamReadResponse::param_items(int index) const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:UsvLink.ParamReadResponse.param_items)
  return _internal_param_items().Get(index);
}
inline ::UsvLink::ParamItem* ParamReadResponse::add_param_items() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::UsvLink::ParamItem* _add = _internal_mutable_param_items()->Add();
  // @@protoc_insertion_point(field_add:UsvLink.ParamReadResponse.param_items)
  return _add;
}
inline const ::google::protobuf::RepeatedPtrField<::UsvLink::ParamItem>& ParamReadResponse::param_items() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_list:UsvLink.ParamReadResponse.param_items)
  return _internal_param_items();
}
inline const ::google::protobuf::RepeatedPtrField<::UsvLink::ParamItem>&
ParamReadResponse::_internal_param_items() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.param_items_;
}
inline ::google::protobuf::RepeatedPtrField<::UsvLink::ParamItem>*
ParamReadResponse::_internal_mutable_param_items() {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return &_impl_.param_items_;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace UsvLink


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_msg_5fparam_5fread_5fresponse_2eproto_2epb_2eh
