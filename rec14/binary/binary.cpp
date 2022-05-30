#include <iostream>

template <unsigned long N>
struct binary {
  static constexpr unsigned long value = (binary<N / 10>::value << 1) + (N & 1);
};

template <>
struct binary<0ul> {
  static constexpr unsigned long value = 0;
};

int main() {
  constexpr unsigned long x = binary<101010>::value;
  std::cout << x << std::endl;
  return 0;
}