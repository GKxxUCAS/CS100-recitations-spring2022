#ifndef CS100_DEMO_ARRAY_HPP
#define CS100_DEMO_ARRAY_HPP

#include <algorithm>
#include <cstddef>
#include <vector>

template <typename T>
class Array {
 public:
  Array() : m_size(0), m_data(nullptr) {}
  explicit Array(std::size_t n) : m_size(n), m_data(new T[n]{}) {}
  template <typename Iterator>
  Array(Iterator begin, Iterator end);
  Array(const Array &other)
      : Array(other.m_data, other.m_data + other.m_size) {}
  Array &operator=(const Array &other) {
    T *new_data = new T[other.m_size];
    std::copy(other.m_data, other.m_data + other.m_size, new_data);
    m_size = other.m_size;
    delete[] m_data;
    m_data = new_data;
    return *this;
  }
  ~Array() {
    delete[] m_data;
  }
  T &at(std::size_t n) {
    return m_data[n];
  }
  const T &at(std::size_t n) const {
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
  T *m_data;
};

template <typename T>
template <typename Iterator>
Array<T>::Array(Iterator begin, Iterator end) : m_size(end - begin) {
  std::copy(begin, end, m_data);
}

#endif // CS100_DEMO_ARRAY_HPP