// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messages.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "messages.pb.h"

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

namespace Messages {

namespace {

const ::google::protobuf::Descriptor* Message_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Message_reflection_ = NULL;
const ::google::protobuf::Descriptor* Message_Login_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Message_Login_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* Message_MessageType_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_messages_2eproto() {
  protobuf_AddDesc_messages_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "messages.proto");
  GOOGLE_CHECK(file != NULL);
  Message_descriptor_ = file->message_type(0);
  static const int Message_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message, messagetype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message, login_),
  };
  Message_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Message_descriptor_,
      Message::default_instance_,
      Message_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Message));
  Message_Login_descriptor_ = Message_descriptor_->nested_type(0);
  static const int Message_Login_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message_Login, username_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message_Login, password_),
  };
  Message_Login_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Message_Login_descriptor_,
      Message_Login::default_instance_,
      Message_Login_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message_Login, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message_Login, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Message_Login));
  Message_MessageType_descriptor_ = Message_descriptor_->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_messages_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Message_descriptor_, &Message::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Message_Login_descriptor_, &Message_Login::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_messages_2eproto() {
  delete Message::default_instance_;
  delete Message_reflection_;
  delete Message_Login::default_instance_;
  delete Message_Login_reflection_;
}

void protobuf_AddDesc_messages_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016messages.proto\022\010Messages\"\227\002\n\007Message\0222"
    "\n\013messageType\030\001 \002(\0162\035.Messages.Message.M"
    "essageType\022&\n\005login\030\002 \001(\0132\027.Messages.Mes"
    "sage.Login\032+\n\005Login\022\020\n\010username\030\001 \002(\t\022\020\n"
    "\010password\030\002 \002(\t\"\202\001\n\013MessageType\022\r\n\tDISP_"
    "PLAY\020\000\022\024\n\020DISP_PLAY_CANCEL\020\001\022\n\n\006LOG_OK\020\002"
    "\022\007\n\003LOG\020\003\022\030\n\024NEW_PLAYER_DISP_PLAY\020\004\022\037\n\033N"
    "EW_PLAYER_DISP_PLAY_CANCEL\020\005", 308);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "messages.proto", &protobuf_RegisterTypes);
  Message::default_instance_ = new Message();
  Message_Login::default_instance_ = new Message_Login();
  Message::default_instance_->InitAsDefaultInstance();
  Message_Login::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_messages_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_messages_2eproto {
  StaticDescriptorInitializer_messages_2eproto() {
    protobuf_AddDesc_messages_2eproto();
  }
} static_descriptor_initializer_messages_2eproto_;

// ===================================================================

const ::google::protobuf::EnumDescriptor* Message_MessageType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Message_MessageType_descriptor_;
}
bool Message_MessageType_IsValid(int value) {
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

#ifndef _MSC_VER
const Message_MessageType Message::DISP_PLAY;
const Message_MessageType Message::DISP_PLAY_CANCEL;
const Message_MessageType Message::LOG_OK;
const Message_MessageType Message::LOG;
const Message_MessageType Message::NEW_PLAYER_DISP_PLAY;
const Message_MessageType Message::NEW_PLAYER_DISP_PLAY_CANCEL;
const Message_MessageType Message::MessageType_MIN;
const Message_MessageType Message::MessageType_MAX;
const int Message::MessageType_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int Message_Login::kUsernameFieldNumber;
const int Message_Login::kPasswordFieldNumber;
#endif  // !_MSC_VER

Message_Login::Message_Login()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Message_Login::InitAsDefaultInstance() {
}

Message_Login::Message_Login(const Message_Login& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Message_Login::SharedCtor() {
  _cached_size_ = 0;
  username_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  password_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Message_Login::~Message_Login() {
  SharedDtor();
}

void Message_Login::SharedDtor() {
  if (username_ != &::google::protobuf::internal::kEmptyString) {
    delete username_;
  }
  if (password_ != &::google::protobuf::internal::kEmptyString) {
    delete password_;
  }
  if (this != default_instance_) {
  }
}

void Message_Login::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Message_Login::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Message_Login_descriptor_;
}

const Message_Login& Message_Login::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_messages_2eproto();
  return *default_instance_;
}

Message_Login* Message_Login::default_instance_ = NULL;

Message_Login* Message_Login::New() const {
  return new Message_Login;
}

void Message_Login::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_username()) {
      if (username_ != &::google::protobuf::internal::kEmptyString) {
        username_->clear();
      }
    }
    if (has_password()) {
      if (password_ != &::google::protobuf::internal::kEmptyString) {
        password_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Message_Login::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string username = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_username()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->username().data(), this->username().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_password;
        break;
      }

      // required string password = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_password:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_password()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->password().data(), this->password().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Message_Login::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string username = 1;
  if (has_username()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->username().data(), this->username().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->username(), output);
  }

  // required string password = 2;
  if (has_password()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->password().data(), this->password().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->password(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Message_Login::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string username = 1;
  if (has_username()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->username().data(), this->username().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->username(), target);
  }

  // required string password = 2;
  if (has_password()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->password().data(), this->password().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->password(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Message_Login::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string username = 1;
    if (has_username()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->username());
    }

    // required string password = 2;
    if (has_password()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->password());
    }

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

void Message_Login::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Message_Login* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Message_Login*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Message_Login::MergeFrom(const Message_Login& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_username()) {
      set_username(from.username());
    }
    if (from.has_password()) {
      set_password(from.password());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Message_Login::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Message_Login::CopyFrom(const Message_Login& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Message_Login::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void Message_Login::Swap(Message_Login* other) {
  if (other != this) {
    std::swap(username_, other->username_);
    std::swap(password_, other->password_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Message_Login::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Message_Login_descriptor_;
  metadata.reflection = Message_Login_reflection_;
  return metadata;
}


// -------------------------------------------------------------------

#ifndef _MSC_VER
const int Message::kMessageTypeFieldNumber;
const int Message::kLoginFieldNumber;
#endif  // !_MSC_VER

Message::Message()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Message::InitAsDefaultInstance() {
  login_ = const_cast< ::Messages::Message_Login*>(&::Messages::Message_Login::default_instance());
}

Message::Message(const Message& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Message::SharedCtor() {
  _cached_size_ = 0;
  messagetype_ = 0;
  login_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Message::~Message() {
  SharedDtor();
}

void Message::SharedDtor() {
  if (this != default_instance_) {
    delete login_;
  }
}

void Message::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Message::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Message_descriptor_;
}

const Message& Message::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_messages_2eproto();
  return *default_instance_;
}

Message* Message::default_instance_ = NULL;

Message* Message::New() const {
  return new Message;
}

void Message::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    messagetype_ = 0;
    if (has_login()) {
      if (login_ != NULL) login_->::Messages::Message_Login::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Message::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .Messages.Message.MessageType messageType = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::Messages::Message_MessageType_IsValid(value)) {
            set_messagetype(static_cast< ::Messages::Message_MessageType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_login;
        break;
      }

      // optional .Messages.Message.Login login = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_login:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_login()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Message::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required .Messages.Message.MessageType messageType = 1;
  if (has_messagetype()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->messagetype(), output);
  }

  // optional .Messages.Message.Login login = 2;
  if (has_login()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->login(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Message::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required .Messages.Message.MessageType messageType = 1;
  if (has_messagetype()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->messagetype(), target);
  }

  // optional .Messages.Message.Login login = 2;
  if (has_login()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->login(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Message::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .Messages.Message.MessageType messageType = 1;
    if (has_messagetype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->messagetype());
    }

    // optional .Messages.Message.Login login = 2;
    if (has_login()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->login());
    }

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

void Message::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Message* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Message*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Message::MergeFrom(const Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_messagetype()) {
      set_messagetype(from.messagetype());
    }
    if (from.has_login()) {
      mutable_login()->::Messages::Message_Login::MergeFrom(from.login());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Message::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Message::CopyFrom(const Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Message::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_login()) {
    if (!this->login().IsInitialized()) return false;
  }
  return true;
}

void Message::Swap(Message* other) {
  if (other != this) {
    std::swap(messagetype_, other->messagetype_);
    std::swap(login_, other->login_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Message::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Message_descriptor_;
  metadata.reflection = Message_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Messages

// @@protoc_insertion_point(global_scope)
