#include <stdexcept>

namespace gkxx {

void strcpy(char *dest, const char *source) {
  if (!dest || !source)
    throw std::invalid_argument("Null pointers passed to strcpy.");
  while (*source)
    *dest++ = *source++;
  *dest = '\0';
}

} // namespace gkxx

int main() {
  gkxx::strcpy(nullptr, nullptr);
}