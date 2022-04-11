#include "vector_v0.hpp"
#include <iostream>

int main() {
  int a[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
  Vector v1(a, sizeof(a) / sizeof(int));
  print_vector(v1);
  std::cout << std::endl;
  std::cout << "size() == " << v1.size() << ", capacity() == " << v1.capacity()
            << std::endl;
  Vector v2;
  for (size_t i = 0; i < 10; ++i)
    v2.push_back(i * i);
  std::cout << "size() == " << v2.size() << ", capacity() == " << v2.capacity()
            << std::endl;
  v2.shrink_to_fit();
  std::cout << "size() == " << v2.size() << ", capacity() == " << v2.capacity()
            << std::endl;
  if (v1 != v2) {
    Vector v3(v2.size());
    std::cout << "size() == " << v3.size()
              << ", capacity() == " << v3.capacity() << std::endl;
    for (size_t i = 0; i < v1.size(); ++i)
      v3.at(i) = v1.at(i);
    print_vector(v3);
  }
  return 0;
}
