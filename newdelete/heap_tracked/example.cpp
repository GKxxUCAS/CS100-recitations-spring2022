#include "heap_tracked.hpp"
#include <iostream>

class Widget : public Heap_tracked {};

int main() {
  Widget *wp = new Widget{};
  std::cout << wp->is_heap_based() << std::endl;
  Widget w{};
  std::cout << w.is_heap_based() << std::endl;
  delete wp;
  try {
    delete &w;
  } catch (Heap_tracked::Missing_address const &ma) {
    std::cout << ma.what() << std::endl;
  }
  return 0;
}