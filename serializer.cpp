#include "serializer.h"
#include "iostream"

Serializer &operator<<(Serializer &out, const ISerializable &obj) {
  obj.serialize(out);
  return out;
}
Serializer &operator>>(Serializer &in, ISerializable &obj) {
  obj.deserialize(in);
  return in;
}

Serializer &operator<<(Serializer &out, const uint8_t obj) {
  out.push(obj);
  return out;
}
Serializer &operator>>(Serializer &in, uint8_t &ref) {
  in.pop_into(ref);
  return in;
}

Serializer &operator<<(Serializer &out, const uint16_t obj) {
  const auto data = reinterpret_cast<const uint8_t *>(&obj);
  for(int i = 0; i < sizeof(obj); i++) out.push(data[i]);
  return out;
}
Serializer &operator>>(Serializer &in, uint16_t &ref) {
  uint8_t data[sizeof(ref)];
  for(int i = 0; i < sizeof(ref); i++) in.pop_into(data[i]);
  ref = *reinterpret_cast<uint16_t *>(data);
  return in;
}

Serializer &operator<<(Serializer &out, const uint32_t obj) {
  const auto data = reinterpret_cast<const uint8_t *>(&obj);
  for(int i = 0; i < sizeof(obj); i++) out.push(data[i]);
  return out;
}
Serializer &operator>>(Serializer &in, uint32_t &ref) {
  uint8_t data[sizeof(ref)];
  for(int i = 0; i < sizeof(ref); i++) in.pop_into(data[i]);
  ref = *reinterpret_cast<uint32_t *>(data);
  return in;
}

Serializer &operator<<(Serializer &out, const int8_t obj) {
  const auto data = reinterpret_cast<const uint8_t *>(&obj);
  for(int i = 0; i < sizeof(obj); i++) out.push(data[i]);
  return out;
}
Serializer &operator>>(Serializer &in, int8_t &ref) {
  uint8_t data[sizeof(ref)];
  for(int i = 0; i < sizeof(ref); i++) in.pop_into(data[i]);
  ref = *reinterpret_cast<int8_t *>(data);
  return in;
}

Serializer &operator<<(Serializer &out, const int16_t obj) {
  const auto data = reinterpret_cast<const int8_t *>(&obj);
  for(int i = 0; i < sizeof(obj); i++) out.push(data[i]);
  return out;
}
Serializer &operator>>(Serializer &in, int16_t &ref) {
  uint8_t data[sizeof(ref)];
  for(int i = 0; i < sizeof(ref); i++) in.pop_into(data[i]);
  ref = *reinterpret_cast<int16_t *>(data);
  return in;
}

Serializer &operator<<(Serializer &out, const int32_t obj) {
  const auto data = reinterpret_cast<const int8_t *>(&obj);
  for(int i = 0; i < sizeof(obj); i++) out.push(data[i]);
  return out;
}
Serializer &operator>>(Serializer &in, int32_t &ref) {
  uint8_t data[sizeof(ref)];
  for(int i = 0; i < sizeof(ref); i++) in.pop_into(data[i]);
  ref = *reinterpret_cast<int32_t *>(data);
  return in;
}

Serializer &operator<<(Serializer &out, const float obj) {
  const auto data = reinterpret_cast<const uint8_t *>(&obj);
  for(int i = 0; i < sizeof(obj); i++) out.push(data[i]);
  return out;
}
Serializer &operator>>(Serializer &in, float &ref) {
  uint8_t data[sizeof(ref)];
  for(int i = 0; i < sizeof(ref); i++) in.pop_into(data[i]);
  ref = *reinterpret_cast<float *>(data);
  return in;
}

Serializer &operator<<(Serializer &out, const bool obj) {
  const auto data = reinterpret_cast<const uint8_t *>(&obj);
  for(int i = 0; i < sizeof(obj); i++) out.push(data[i]);
  return out;
}
Serializer &operator>>(Serializer &in, bool &ref) {
  uint8_t data[sizeof(ref)];
  for(int i = 0; i < sizeof(ref); i++) in.pop_into(data[i]);
  ref = *reinterpret_cast<bool *>(data);
  return in;
}

Serializer &operator<<(Serializer &out, const char obj) {
  const auto data = reinterpret_cast<const uint8_t *>(&obj);
  for(int i = 0; i < sizeof(obj); i++) out.push(data[i]);
  return out;
}
Serializer &operator>>(Serializer &in, char &ref) {
  uint8_t data[sizeof(ref)];
  for(int i = 0; i < sizeof(ref); i++) in.pop_into(data[i]);
  ref = *reinterpret_cast<char *>(data);
  return in;
}