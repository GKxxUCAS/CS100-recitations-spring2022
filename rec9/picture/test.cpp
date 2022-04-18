#include "picture.hpp"
#include <iostream>
#include <string>
#include <cassert>

int main() {
  std::string pic[] = {"Liu Big God", "is so strong", "and powerful!"};
  auto p1 = Picture(pic, pic + 3);
  std::cout << p1 << std::endl;
  assert(p1.get_height() == 3);
  assert(p1.get_width() == 13);
  std::cout << add_frame(p1) << std::endl;
  std::string pic2[] = {"algebraic geometry", "analytic number theory"};
  auto p2 = Picture(pic2, pic2 + 2);
  std::cout << add_frame((add_frame(p1) | add_frame(p2)) & p2) << std::endl;
  return 0;
}