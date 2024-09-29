// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msg_heartbeat.proto
// Protobuf C++ Version: 4.25.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_msg_5fheartbeat_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_msg_5fheartbeat_2eproto_2epb_2eh

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
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_msg_5fheartbeat_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_msg_5fheartbeat_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_msg_5fheartbeat_2eproto;
namespace UsvLink {
class Heartbeat;
struct HeartbeatDefaultTypeInternal;
extern HeartbeatDefaultTypeInternal _Heartbeat_default_instance_;
}  // namespace UsvLink
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace UsvLink {

// ===================================================================


// -------------------------------------------------------------------

class Heartbeat final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:UsvLink.Heartbeat) */ {
 public:
  inline Heartbeat() : Heartbeat(nullptr) {}
  ~Heartbeat() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR Heartbeat(::google::protobuf::internal::ConstantInitialized);

  inline Heartbeat(const Heartbeat& from)
      : Heartbeat(nullptr, from) {}
  Heartbeat(Heartbeat&& from) noexcept
    : Heartbeat() {
    *this = ::std::move(from);
  }

  inline Heartbeat& operator=(const Heartbeat& from) {
    CopyFrom(from);
    return *this;
  }
  inline Heartbeat& operator=(Heartbeat&& from) noexcept {
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
  static const Heartbeat& default_instance() {
    return *internal_default_instance();
  }
  static inline const Heartbeat* internal_default_instance() {
    return reinterpret_cast<const Heartbeat*>(
               &_Heartbeat_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Heartbeat& a, Heartbeat& b) {
    a.Swap(&b);
  }
  inline void Swap(Heartbeat* other) {
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
  void UnsafeArenaSwap(Heartbeat* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Heartbeat* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Heartbeat>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Heartbeat& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const Heartbeat& from) {
    Heartbeat::MergeImpl(*this, from);
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
  void InternalSwap(Heartbeat* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "UsvLink.Heartbeat";
  }
  protected:
  explicit Heartbeat(::google::protobuf::Arena* arena);
  Heartbeat(::google::protobuf::Arena* arena, const Heartbeat& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kLatitudeFieldNumber = 2,
    kLongitudeFieldNumber = 3,
    kAnchorRemainingFieldNumber = 4,
    kConnectStatusFieldNumber = 5,
    kConnectTargetSystemIdFieldNumber = 6,
  };
  // string name = 1;
  void clear_name() ;
  const std::string& name() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_name(Arg_&& arg, Args_... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* value);

  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(
      const std::string& value);
  std::string* _internal_mutable_name();

  public:
  // optional float latitude = 2;
  bool has_latitude() const;
  void clear_latitude() ;
  float latitude() const;
  void set_latitude(float value);

  private:
  float _internal_latitude() const;
  void _internal_set_latitude(float value);

  public:
  // optional float longitude = 3;
  bool has_longitude() const;
  void clear_longitude() ;
  float longitude() const;
  void set_longitude(float value);

  private:
  float _internal_longitude() const;
  void _internal_set_longitude(float value);

  public:
  // optional float anchor_remaining = 4;
  bool has_anchor_remaining() const;
  void clear_anchor_remaining() ;
  float anchor_remaining() const;
  void set_anchor_remaining(float value);

  private:
  float _internal_anchor_remaining() const;
  void _internal_set_anchor_remaining(float value);

  public:
  // bool connect_status = 5;
  void clear_connect_status() ;
  bool connect_status() const;
  void set_connect_status(bool value);

  private:
  bool _internal_connect_status() const;
  void _internal_set_connect_status(bool value);

  public:
  // int32 connect_target_system_id = 6;
  void clear_connect_target_system_id() ;
  ::int32_t connect_target_system_id() const;
  void set_connect_target_system_id(::int32_t value);

  private:
  ::int32_t _internal_connect_target_system_id() const;
  void _internal_set_connect_target_system_id(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:UsvLink.Heartbeat)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      3, 6, 0,
      30, 2>
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
    ::google::protobuf::internal::ArenaStringPtr name_;
    float latitude_;
    float longitude_;
    float anchor_remaining_;
    bool connect_status_;
    ::int32_t connect_target_system_id_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_msg_5fheartbeat_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Heartbeat

// string name = 1;
inline void Heartbeat::clear_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.name_.ClearToEmpty();
}
inline const std::string& Heartbeat::name() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:UsvLink.Heartbeat.name)
  return _internal_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Heartbeat::set_name(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.name_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:UsvLink.Heartbeat.name)
}
inline std::string* Heartbeat::mutable_name() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:UsvLink.Heartbeat.name)
  return _s;
}
inline const std::string& Heartbeat::_internal_name() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.name_.Get();
}
inline void Heartbeat::_internal_set_name(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.name_.Set(value, GetArena());
}
inline std::string* Heartbeat::_internal_mutable_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  return _impl_.name_.Mutable( GetArena());
}
inline std::string* Heartbeat::release_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:UsvLink.Heartbeat.name)
  return _impl_.name_.Release();
}
inline void Heartbeat::set_allocated_name(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.name_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.name_.IsDefault()) {
          _impl_.name_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:UsvLink.Heartbeat.name)
}

// optional float latitude = 2;
inline bool Heartbeat::has_latitude() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void Heartbeat::clear_latitude() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.latitude_ = 0;
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline float Heartbeat::latitude() const {
  // @@protoc_insertion_point(field_get:UsvLink.Heartbeat.latitude)
  return _internal_latitude();
}
inline void Heartbeat::set_latitude(float value) {
  _internal_set_latitude(value);
  // @@protoc_insertion_point(field_set:UsvLink.Heartbeat.latitude)
}
inline float Heartbeat::_internal_latitude() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.latitude_;
}
inline void Heartbeat::_internal_set_latitude(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.latitude_ = value;
}

// optional float longitude = 3;
inline bool Heartbeat::has_longitude() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void Heartbeat::clear_longitude() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.longitude_ = 0;
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline float Heartbeat::longitude() const {
  // @@protoc_insertion_point(field_get:UsvLink.Heartbeat.longitude)
  return _internal_longitude();
}
inline void Heartbeat::set_longitude(float value) {
  _internal_set_longitude(value);
  // @@protoc_insertion_point(field_set:UsvLink.Heartbeat.longitude)
}
inline float Heartbeat::_internal_longitude() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.longitude_;
}
inline void Heartbeat::_internal_set_longitude(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.longitude_ = value;
}

// optional float anchor_remaining = 4;
inline bool Heartbeat::has_anchor_remaining() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline void Heartbeat::clear_anchor_remaining() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.anchor_remaining_ = 0;
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline float Heartbeat::anchor_remaining() const {
  // @@protoc_insertion_point(field_get:UsvLink.Heartbeat.anchor_remaining)
  return _internal_anchor_remaining();
}
inline void Heartbeat::set_anchor_remaining(float value) {
  _internal_set_anchor_remaining(value);
  // @@protoc_insertion_point(field_set:UsvLink.Heartbeat.anchor_remaining)
}
inline float Heartbeat::_internal_anchor_remaining() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.anchor_remaining_;
}
inline void Heartbeat::_internal_set_anchor_remaining(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.anchor_remaining_ = value;
}

// bool connect_status = 5;
inline void Heartbeat::clear_connect_status() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.connect_status_ = false;
}
inline bool Heartbeat::connect_status() const {
  // @@protoc_insertion_point(field_get:UsvLink.Heartbeat.connect_status)
  return _internal_connect_status();
}
inline void Heartbeat::set_connect_status(bool value) {
  _internal_set_connect_status(value);
  // @@protoc_insertion_point(field_set:UsvLink.Heartbeat.connect_status)
}
inline bool Heartbeat::_internal_connect_status() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.connect_status_;
}
inline void Heartbeat::_internal_set_connect_status(bool value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.connect_status_ = value;
}

// int32 connect_target_system_id = 6;
inline void Heartbeat::clear_connect_target_system_id() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.connect_target_system_id_ = 0;
}
inline ::int32_t Heartbeat::connect_target_system_id() const {
  // @@protoc_insertion_point(field_get:UsvLink.Heartbeat.connect_target_system_id)
  return _internal_connect_target_system_id();
}
inline void Heartbeat::set_connect_target_system_id(::int32_t value) {
  _internal_set_connect_target_system_id(value);
  // @@protoc_insertion_point(field_set:UsvLink.Heartbeat.connect_target_system_id)
}
inline ::int32_t Heartbeat::_internal_connect_target_system_id() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.connect_target_system_id_;
}
inline void Heartbeat::_internal_set_connect_target_system_id(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.connect_target_system_id_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace UsvLink


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_msg_5fheartbeat_2eproto_2epb_2eh
