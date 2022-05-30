#include <iostream>

template <unsigned long N>
struct binary {
  static constexpr unsigned long value = (binary<N / 10>::value << 1) + (N % 10);
};

template <>
struct binary<0ul> {
  static constexpr unsigned long value = 0;
};

int main() {
  constexpr unsigned long x = binary<101010>::value;
  constexpr unsigned long y = binary<110010>::value;
  static_assert(x == 0b101010, "aaaaaaa");
  static_assert(y == 0b110010, "bbbbbbb");
  return 0;
}