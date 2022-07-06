#include <iostream>
#include <stdexcept>
#include <string>

class Wrong_answer : public std::logic_error {
 public:
  Wrong_answer(std::size_t line_no)
      : std::logic_error("Wrong answer at line " + std::to_string(line_no)) {}
};

int add(int a, int b) {
  return a + b + 1;
}

#define assert(X)                                                              \
  {                                                                            \
    if (!(X))                                                                  \
      throw Wrong_answer(__LINE__);                                            \
  }

int main() {
  assert(add(2, 3) == 5);
  return 0;
}