// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: FullName.proto

#include "FullName.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace protobuf {
constexpr FullName::FullName(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : first_name_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , second_name_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , third_name_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct FullNameDefaultTypeInternal {
  constexpr FullNameDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~FullNameDefaultTypeInternal() {}
  union {
    FullName _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT FullNameDefaultTypeInternal _FullName_default_instance_;
}  // namespace protobuf
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_FullName_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_FullName_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_FullName_2eproto = nullptr;

const uint32_t TableStruct_FullName_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::protobuf::FullName, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::protobuf::FullName, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::protobuf::FullName, first_name_),
  PROTOBUF_FIELD_OFFSET(::protobuf::FullName, second_name_),
  PROTOBUF_FIELD_OFFSET(::protobuf::FullName, third_name_),
  ~0u,
  ~0u,
  0,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, -1, sizeof(::protobuf::FullName)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::protobuf::_FullName_default_instance_),
};

const char descriptor_table_protodef_FullName_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016FullName.proto\022\010protobuf\"[\n\010FullName\022\022"
  "\n\nfirst_name\030\001 \001(\t\022\023\n\013second_name\030\002 \001(\t\022"
  "\027\n\nthird_name\030\003 \001(\tH\000\210\001\001B\r\n\013_third_nameb"
  "\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_FullName_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_FullName_2eproto = {
  false, false, 127, descriptor_table_protodef_FullName_2eproto, "FullName.proto", 
  &descriptor_table_FullName_2eproto_once, nullptr, 0, 1,
  schemas, file_default_instances, TableStruct_FullName_2eproto::offsets,
  file_level_metadata_FullName_2eproto, file_level_enum_descriptors_FullName_2eproto, file_level_service_descriptors_FullName_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_FullName_2eproto_getter() {
  return &descriptor_table_FullName_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_FullName_2eproto(&descriptor_table_FullName_2eproto);
namespace protobuf {

// ===================================================================

class FullName::_Internal {
 public:
  using HasBits = decltype(std::declval<FullName>()._has_bits_);
  static void set_has_third_name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

FullName::FullName(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:protobuf.FullName)
}
FullName::FullName(const FullName& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  first_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    first_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_first_name().empty()) {
    first_name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_first_name(), 
      GetArenaForAllocation());
  }
  second_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    second_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_second_name().empty()) {
    second_name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_second_name(), 
      GetArenaForAllocation());
  }
  third_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    third_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_third_name()) {
    third_name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_third_name(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:protobuf.FullName)
}

inline void FullName::SharedCtor() {
first_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  first_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
second_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  second_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
third_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  third_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

FullName::~FullName() {
  // @@protoc_insertion_point(destructor:protobuf.FullName)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void FullName::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  first_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  second_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  third_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void FullName::ArenaDtor(void* object) {
  FullName* _this = reinterpret_cast< FullName* >(object);
  (void)_this;
}
void FullName::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void FullName::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void FullName::Clear() {
// @@protoc_insertion_point(message_clear_start:protobuf.FullName)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  first_name_.ClearToEmpty();
  second_name_.ClearToEmpty();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    third_name_.ClearNonDefaultToEmpty();
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* FullName::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string first_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_first_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "protobuf.FullName.first_name"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string second_name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_second_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "protobuf.FullName.second_name"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional string third_name = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_third_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "protobuf.FullName.third_name"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* FullName::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:protobuf.FullName)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string first_name = 1;
  if (!this->_internal_first_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_first_name().data(), static_cast<int>(this->_internal_first_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protobuf.FullName.first_name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_first_name(), target);
  }

  // string second_name = 2;
  if (!this->_internal_second_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_second_name().data(), static_cast<int>(this->_internal_second_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protobuf.FullName.second_name");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_second_name(), target);
  }

  // optional string third_name = 3;
  if (_internal_has_third_name()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_third_name().data(), static_cast<int>(this->_internal_third_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protobuf.FullName.third_name");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_third_name(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protobuf.FullName)
  return target;
}

size_t FullName::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protobuf.FullName)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string first_name = 1;
  if (!this->_internal_first_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_first_name());
  }

  // string second_name = 2;
  if (!this->_internal_second_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_second_name());
  }

  // optional string third_name = 3;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_third_name());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData FullName::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    FullName::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*FullName::GetClassData() const { return &_class_data_; }

void FullName::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<FullName *>(to)->MergeFrom(
      static_cast<const FullName &>(from));
}


void FullName::MergeFrom(const FullName& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:protobuf.FullName)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_first_name().empty()) {
    _internal_set_first_name(from._internal_first_name());
  }
  if (!from._internal_second_name().empty()) {
    _internal_set_second_name(from._internal_second_name());
  }
  if (from._internal_has_third_name()) {
    _internal_set_third_name(from._internal_third_name());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void FullName::CopyFrom(const FullName& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protobuf.FullName)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FullName::IsInitialized() const {
  return true;
}

void FullName::InternalSwap(FullName* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &first_name_, lhs_arena,
      &other->first_name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &second_name_, lhs_arena,
      &other->second_name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &third_name_, lhs_arena,
      &other->third_name_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata FullName::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_FullName_2eproto_getter, &descriptor_table_FullName_2eproto_once,
      file_level_metadata_FullName_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace protobuf
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::protobuf::FullName* Arena::CreateMaybeMessage< ::protobuf::FullName >(Arena* arena) {
  return Arena::CreateMessageInternal< ::protobuf::FullName >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>