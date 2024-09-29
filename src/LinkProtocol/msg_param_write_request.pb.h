// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msg_param_write_request.proto
// Protobuf C++ Version: 4.25.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_msg_5fparam_5fwrite_5frequest_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_msg_5fparam_5fwrite_5frequest_2eproto_2epb_2eh

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

#define PROTOBUF_INTERNAL_EXPORT_msg_5fparam_5fwrite_5frequest_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_msg_5fparam_5fwrite_5frequest_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_msg_5fparam_5fwrite_5frequest_2eproto;
namespace UsvLink {
class ParamWriteRequest;
struct ParamWriteRequestDefaultTypeInternal;
extern ParamWriteRequestDefaultTypeInternal _ParamWriteRequest_default_instance_;
}  // namespace UsvLink
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace UsvLink {

// ===================================================================


// -------------------------------------------------------------------

class ParamWriteRequest final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:UsvLink.ParamWriteRequest) */ {
 public:
  inline ParamWriteRequest() : ParamWriteRequest(nullptr) {}
  ~ParamWriteRequest() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR ParamWriteRequest(::google::protobuf::internal::ConstantInitialized);

  inline ParamWriteRequest(const ParamWriteRequest& from)
      : ParamWriteRequest(nullptr, from) {}
  ParamWriteRequest(ParamWriteRequest&& from) noexcept
    : ParamWriteRequest() {
    *this = ::std::move(from);
  }

  inline ParamWriteRequest& operator=(const ParamWriteRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline ParamWriteRequest& operator=(ParamWriteRequest&& from) noexcept {
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
  static const ParamWriteRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const ParamWriteRequest* internal_default_instance() {
    return reinterpret_cast<const ParamWriteRequest*>(
               &_ParamWriteRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ParamWriteRequest& a, ParamWriteRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(ParamWriteRequest* other) {
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
  void UnsafeArenaSwap(ParamWriteRequest* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ParamWriteRequest* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<ParamWriteRequest>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const ParamWriteRequest& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const ParamWriteRequest& from) {
    ParamWriteRequest::MergeImpl(*this, from);
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
  void InternalSwap(ParamWriteRequest* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "UsvLink.ParamWriteRequest";
  }
  protected:
  explicit ParamWriteRequest(::google::protobuf::Arena* arena);
  ParamWriteRequest(::google::protobuf::Arena* arena, const ParamWriteRequest& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kParamItemsFieldNumber = 1,
  };
  // repeated .UsvLink.ParamItem param_items = 1;
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
  // @@protoc_insertion_point(class_scope:UsvLink.ParamWriteRequest)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 1,
      0, 2>
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
    ::google::protobuf::RepeatedPtrField< ::UsvLink::ParamItem > param_items_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_msg_5fparam_5fwrite_5frequest_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// ParamWriteRequest

// repeated .UsvLink.ParamItem param_items = 1;
inline int ParamWriteRequest::_internal_param_items_size() const {
  return _internal_param_items().size();
}
inline int ParamWriteRequest::param_items_size() const {
  return _internal_param_items_size();
}
inline ::UsvLink::ParamItem* ParamWriteRequest::mutable_param_items(int index)
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable:UsvLink.ParamWriteRequest.param_items)
  return _internal_mutable_param_items()->Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField<::UsvLink::ParamItem>* ParamWriteRequest::mutable_param_items()
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable_list:UsvLink.ParamWriteRequest.param_items)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _internal_mutable_param_items();
}
inline const ::UsvLink::ParamItem& ParamWriteRequest::param_items(int index) const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:UsvLink.ParamWriteRequest.param_items)
  return _internal_param_items().Get(index);
}
inline ::UsvLink::ParamItem* ParamWriteRequest::add_param_items() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::UsvLink::ParamItem* _add = _internal_mutable_param_items()->Add();
  // @@protoc_insertion_point(field_add:UsvLink.ParamWriteRequest.param_items)
  return _add;
}
inline const ::google::protobuf::RepeatedPtrField<::UsvLink::ParamItem>& ParamWriteRequest::param_items() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_list:UsvLink.ParamWriteRequest.param_items)
  return _internal_param_items();
}
inline const ::google::protobuf::RepeatedPtrField<::UsvLink::ParamItem>&
ParamWriteRequest::_internal_param_items() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.param_items_;
}
inline ::google::protobuf::RepeatedPtrField<::UsvLink::ParamItem>*
ParamWriteRequest::_internal_mutable_param_items() {
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

#endif  // GOOGLE_PROTOBUF_INCLUDED_msg_5fparam_5fwrite_5frequest_2eproto_2epb_2eh
