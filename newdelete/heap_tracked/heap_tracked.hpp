#ifndef HEAP_TRACKED_HPP_
#define HEAP_TRACKED_HPP_

#include <stdexcept>
#include <unordered_set>

class Heap_tracked {
  using Raw_addr = const void *;

  static std::unordered_set<Raw_addr> addresses;

 public:
  static void *operator new(std::size_t size);

  static void operator delete(void *ptr);

  virtual ~Heap_tracked() = 0;

  bool is_heap_based() const;

  class Missing_address;
};

Heap_tracked::~Heap_tracked() = default;

std::unordered_set<Heap_tracked::Raw_addr> Heap_tracked::addresses{};

class Heap_tracked::Missing_address : public std::invalid_argument {
 public:
  Missing_address()
      : std::invalid_argument("deleting an object that is not heap-based.") {}
};

void *Heap_tracked::operator new(std::size_t size) {
  auto ptr = ::operator new(size);
  addresses.insert(ptr);
  return ptr;
}

void Heap_tracked::operator delete(void *ptr) {
  if (!ptr)
    return;
  auto pos = addresses.find(ptr);
  if (pos != addresses.end()) {
    addresses.erase(pos);
    ::operator delete(ptr);
  } else
    throw Missing_address{};
}

bool Heap_tracked::is_heap_based() const {
  auto real_pos = dynamic_cast<Raw_addr>(this);
  return addresses.find(real_pos) != addresses.end();
}

#endif // HEAP_TRACKED_HPP_