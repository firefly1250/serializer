#ifndef SERIALIZER_H_
#define SERIALIZER_H_

#include <cstdint>
#include "etl/queue.h"

using Serializer =
    etl::queue<uint8_t, 1024, etl::memory_model::MEMORY_MODEL_MEDIUM>;

class ISerializable {
public:
  virtual void serialize(Serializer &serializer) const = 0;
  virtual void deserialize(Serializer &serializer) = 0;
};

Serializer &operator<<(Serializer &out, const ISerializable &obj);
Serializer &operator>>(Serializer &in, ISerializable &obj);
Serializer &operator<<(Serializer &out, const uint8_t obj);
Serializer &operator>>(Serializer &in, uint8_t &ref);
Serializer &operator<<(Serializer &out, const uint16_t obj);
Serializer &operator>>(Serializer &in, uint16_t &ref);
Serializer &operator<<(Serializer &out, const uint32_t obj);
Serializer &operator>>(Serializer &in, uint32_t &ref);
Serializer &operator<<(Serializer &out, const int8_t obj);
Serializer &operator>>(Serializer &in, int8_t &ref);
Serializer &operator<<(Serializer &out, const int16_t obj);
Serializer &operator>>(Serializer &in, int16_t &ref);
Serializer &operator<<(Serializer &out, const int32_t obj);
Serializer &operator>>(Serializer &in, int32_t &ref);
Serializer &operator<<(Serializer &out, const float obj);
Serializer &operator>>(Serializer &in, float &ref);
Serializer &operator<<(Serializer &out, const bool obj);
Serializer &operator>>(Serializer &in, bool &ref);
Serializer &operator<<(Serializer &out, const char obj);
Serializer &operator>>(Serializer &in, char &ref);

#endif