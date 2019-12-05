#include <iostream>
#include "serializer.h"

class TestData : public ISerializable {
public:
  void serialize(Serializer &serializer) const override {
    serializer << a << b << c;
  }
  void deserialize(Serializer &serializer) override {
    serializer >> a >> b >> c;
  }
  TestData(int a, float b, bool c, char d)
      : a(a), b(b), c(c), unnecessary_data(d) {}
  TestData() {}

  int a;
  float b;
  bool c;
  char unnecessary_data;
};

std::basic_ostream<char> &operator<<(std::basic_ostream<char> &out,
                                     const TestData t) {
  out << "a: " << t.a << ", b: " << t.b << ", c: " << t.c
      << ", unnecessary_data: " << t.unnecessary_data;
  return out;
}

int main() {
  Serializer s;
  s << 34 << 'g' << 4.64f << TestData(23, 3.14, true, 'n');
  int a;
  char b;
  float d;
  TestData t;
  s >> a >> b >> d >> t;
  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;
  std::cout << "d: " << d << std::endl;
  std::cout << "t: " << t << std::endl;
}