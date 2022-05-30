#ifndef CS100_DEMO_INTARRAY_HPP
#define CS100_DEMO_INTARRAY_HPP

#include <algorithm>
#include <cstddef>

class IntArray {
 public:
  IntArray() : m_size(0), m_data(nullptr) {}
  explicit IntArray(std::size_t n) : m_size(n), m_data(new int[n]{}) {}
  IntArray(int *begin, int *end) : IntArray(end - begin) {
    std::copy(begin, end, m_data);
  }
  IntArray(const IntArray &other)
      : IntArray(other.m_data, other.m_data + other.m_size) {}
  IntArray &operator=(const IntArray &other) {
    int *new_data = new int[other.m_size];
    std::copy(other.m_data, other.m_data + other.m_size, new_data);
    m_size = other.m_size;
    delete[] m_data;
    m_data = new_data;
    return *this;
  }
  ~IntArray() {
    delete[] m_data;
  }
  int &at(std::size_t n) {
    return m_data[n];
  }
  const int &at(std::size_t n) const {
    return m_data[n];
  }
  std::size_t size() const {
    return m_size;
  }
  bool empty() const {
    return size() == 0;
  }
  void clear() {
    m_size = 0;
    delete[] m_data;
    m_data = nullptr;
  }

 private:
  std::size_t m_size;
  int *m_data;
};

#endif // CS100_DEMO_INTARRAY_HPP