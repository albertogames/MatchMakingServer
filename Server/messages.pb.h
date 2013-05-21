// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messages.proto

#ifndef PROTOBUF_messages_2eproto__INCLUDED
#define PROTOBUF_messages_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace Messages {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_messages_2eproto();
void protobuf_AssignDesc_messages_2eproto();
void protobuf_ShutdownFile_messages_2eproto();

class Message;
class Message_Login;

enum Message_MessageType {
  Message_MessageType_DISP_PLAY = 0,
  Message_MessageType_DISP_PLAY_CANCEL = 1,
  Message_MessageType_LOG_OK = 2,
  Message_MessageType_LOG = 3,
  Message_MessageType_USER_AVAILABLE_PLAY = 4,
  Message_MessageType_USER_AVAILABLE_PLAY_CANCEL = 5
};
bool Message_MessageType_IsValid(int value);
const Message_MessageType Message_MessageType_MessageType_MIN = Message_MessageType_DISP_PLAY;
const Message_MessageType Message_MessageType_MessageType_MAX = Message_MessageType_USER_AVAILABLE_PLAY_CANCEL;
const int Message_MessageType_MessageType_ARRAYSIZE = Message_MessageType_MessageType_MAX + 1;

const ::google::protobuf::EnumDescriptor* Message_MessageType_descriptor();
inline const ::std::string& Message_MessageType_Name(Message_MessageType value) {
  return ::google::protobuf::internal::NameOfEnum(
    Message_MessageType_descriptor(), value);
}
inline bool Message_MessageType_Parse(
    const ::std::string& name, Message_MessageType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Message_MessageType>(
    Message_MessageType_descriptor(), name, value);
}
// ===================================================================

class Message_Login : public ::google::protobuf::Message {
 public:
  Message_Login();
  virtual ~Message_Login();

  Message_Login(const Message_Login& from);

  inline Message_Login& operator=(const Message_Login& from) {
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
  static const Message_Login& default_instance();

  void Swap(Message_Login* other);

  // implements Message ----------------------------------------------

  Message_Login* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Message_Login& from);
  void MergeFrom(const Message_Login& from);
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

  // required string password = 1;
  inline bool has_password() const;
  inline void clear_password();
  static const int kPasswordFieldNumber = 1;
  inline const ::std::string& password() const;
  inline void set_password(const ::std::string& value);
  inline void set_password(const char* value);
  inline void set_password(const char* value, size_t size);
  inline ::std::string* mutable_password();
  inline ::std::string* release_password();
  inline void set_allocated_password(::std::string* password);

  // @@protoc_insertion_point(class_scope:Messages.Message.Login)
 private:
  inline void set_has_password();
  inline void clear_has_password();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* password_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_messages_2eproto();
  friend void protobuf_AssignDesc_messages_2eproto();
  friend void protobuf_ShutdownFile_messages_2eproto();

  void InitAsDefaultInstance();
  static Message_Login* default_instance_;
};
// -------------------------------------------------------------------

class Message : public ::google::protobuf::Message {
 public:
  Message();
  virtual ~Message();

  Message(const Message& from);

  inline Message& operator=(const Message& from) {
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
  static const Message& default_instance();

  void Swap(Message* other);

  // implements Message ----------------------------------------------

  Message* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Message& from);
  void MergeFrom(const Message& from);
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

  typedef Message_Login Login;

  typedef Message_MessageType MessageType;
  static const MessageType DISP_PLAY = Message_MessageType_DISP_PLAY;
  static const MessageType DISP_PLAY_CANCEL = Message_MessageType_DISP_PLAY_CANCEL;
  static const MessageType LOG_OK = Message_MessageType_LOG_OK;
  static const MessageType LOG = Message_MessageType_LOG;
  static const MessageType USER_AVAILABLE_PLAY = Message_MessageType_USER_AVAILABLE_PLAY;
  static const MessageType USER_AVAILABLE_PLAY_CANCEL = Message_MessageType_USER_AVAILABLE_PLAY_CANCEL;
  static inline bool MessageType_IsValid(int value) {
    return Message_MessageType_IsValid(value);
  }
  static const MessageType MessageType_MIN =
    Message_MessageType_MessageType_MIN;
  static const MessageType MessageType_MAX =
    Message_MessageType_MessageType_MAX;
  static const int MessageType_ARRAYSIZE =
    Message_MessageType_MessageType_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  MessageType_descriptor() {
    return Message_MessageType_descriptor();
  }
  static inline const ::std::string& MessageType_Name(MessageType value) {
    return Message_MessageType_Name(value);
  }
  static inline bool MessageType_Parse(const ::std::string& name,
      MessageType* value) {
    return Message_MessageType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // required .Messages.Message.MessageType messageType = 1;
  inline bool has_messagetype() const;
  inline void clear_messagetype();
  static const int kMessageTypeFieldNumber = 1;
  inline ::Messages::Message_MessageType messagetype() const;
  inline void set_messagetype(::Messages::Message_MessageType value);

  // optional string username = 2;
  inline bool has_username() const;
  inline void clear_username();
  static const int kUsernameFieldNumber = 2;
  inline const ::std::string& username() const;
  inline void set_username(const ::std::string& value);
  inline void set_username(const char* value);
  inline void set_username(const char* value, size_t size);
  inline ::std::string* mutable_username();
  inline ::std::string* release_username();
  inline void set_allocated_username(::std::string* username);

  // optional .Messages.Message.Login login = 3;
  inline bool has_login() const;
  inline void clear_login();
  static const int kLoginFieldNumber = 3;
  inline const ::Messages::Message_Login& login() const;
  inline ::Messages::Message_Login* mutable_login();
  inline ::Messages::Message_Login* release_login();
  inline void set_allocated_login(::Messages::Message_Login* login);

  // @@protoc_insertion_point(class_scope:Messages.Message)
 private:
  inline void set_has_messagetype();
  inline void clear_has_messagetype();
  inline void set_has_username();
  inline void clear_has_username();
  inline void set_has_login();
  inline void clear_has_login();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* username_;
  ::Messages::Message_Login* login_;
  int messagetype_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_messages_2eproto();
  friend void protobuf_AssignDesc_messages_2eproto();
  friend void protobuf_ShutdownFile_messages_2eproto();

  void InitAsDefaultInstance();
  static Message* default_instance_;
};
// ===================================================================


// ===================================================================

// Message_Login

// required string password = 1;
inline bool Message_Login::has_password() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Message_Login::set_has_password() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Message_Login::clear_has_password() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Message_Login::clear_password() {
  if (password_ != &::google::protobuf::internal::kEmptyString) {
    password_->clear();
  }
  clear_has_password();
}
inline const ::std::string& Message_Login::password() const {
  return *password_;
}
inline void Message_Login::set_password(const ::std::string& value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  password_->assign(value);
}
inline void Message_Login::set_password(const char* value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  password_->assign(value);
}
inline void Message_Login::set_password(const char* value, size_t size) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  password_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Message_Login::mutable_password() {
  set_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  return password_;
}
inline ::std::string* Message_Login::release_password() {
  clear_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = password_;
    password_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Message_Login::set_allocated_password(::std::string* password) {
  if (password_ != &::google::protobuf::internal::kEmptyString) {
    delete password_;
  }
  if (password) {
    set_has_password();
    password_ = password;
  } else {
    clear_has_password();
    password_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// Message

// required .Messages.Message.MessageType messageType = 1;
inline bool Message::has_messagetype() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Message::set_has_messagetype() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Message::clear_has_messagetype() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Message::clear_messagetype() {
  messagetype_ = 0;
  clear_has_messagetype();
}
inline ::Messages::Message_MessageType Message::messagetype() const {
  return static_cast< ::Messages::Message_MessageType >(messagetype_);
}
inline void Message::set_messagetype(::Messages::Message_MessageType value) {
  assert(::Messages::Message_MessageType_IsValid(value));
  set_has_messagetype();
  messagetype_ = value;
}

// optional string username = 2;
inline bool Message::has_username() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Message::set_has_username() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Message::clear_has_username() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Message::clear_username() {
  if (username_ != &::google::protobuf::internal::kEmptyString) {
    username_->clear();
  }
  clear_has_username();
}
inline const ::std::string& Message::username() const {
  return *username_;
}
inline void Message::set_username(const ::std::string& value) {
  set_has_username();
  if (username_ == &::google::protobuf::internal::kEmptyString) {
    username_ = new ::std::string;
  }
  username_->assign(value);
}
inline void Message::set_username(const char* value) {
  set_has_username();
  if (username_ == &::google::protobuf::internal::kEmptyString) {
    username_ = new ::std::string;
  }
  username_->assign(value);
}
inline void Message::set_username(const char* value, size_t size) {
  set_has_username();
  if (username_ == &::google::protobuf::internal::kEmptyString) {
    username_ = new ::std::string;
  }
  username_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Message::mutable_username() {
  set_has_username();
  if (username_ == &::google::protobuf::internal::kEmptyString) {
    username_ = new ::std::string;
  }
  return username_;
}
inline ::std::string* Message::release_username() {
  clear_has_username();
  if (username_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = username_;
    username_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Message::set_allocated_username(::std::string* username) {
  if (username_ != &::google::protobuf::internal::kEmptyString) {
    delete username_;
  }
  if (username) {
    set_has_username();
    username_ = username;
  } else {
    clear_has_username();
    username_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional .Messages.Message.Login login = 3;
inline bool Message::has_login() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Message::set_has_login() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Message::clear_has_login() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Message::clear_login() {
  if (login_ != NULL) login_->::Messages::Message_Login::Clear();
  clear_has_login();
}
inline const ::Messages::Message_Login& Message::login() const {
  return login_ != NULL ? *login_ : *default_instance_->login_;
}
inline ::Messages::Message_Login* Message::mutable_login() {
  set_has_login();
  if (login_ == NULL) login_ = new ::Messages::Message_Login;
  return login_;
}
inline ::Messages::Message_Login* Message::release_login() {
  clear_has_login();
  ::Messages::Message_Login* temp = login_;
  login_ = NULL;
  return temp;
}
inline void Message::set_allocated_login(::Messages::Message_Login* login) {
  delete login_;
  login_ = login;
  if (login) {
    set_has_login();
  } else {
    clear_has_login();
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Messages

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Messages::Message_MessageType>() {
  return ::Messages::Message_MessageType_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_messages_2eproto__INCLUDED
