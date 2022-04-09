#ifndef CS100_VECTOR_HPP
#define CS100_VECTOR_HPP

#include <algorithm>
#include <cstddef>
#include <iostream>

// We do not separate the allocation of memory and the construction of object,
// which is fine because we only store some ints.
class Vector {
  size_t m_size, m_capacity;
  int *m_data;

 public:
  Vector() : m_size(0), m_capacity(0), m_data(nullptr) {}
  explicit Vector(int *arr, size_t n) : Vector(arr, arr + n) {}
  explicit Vector(int *begin, int *end) : Vector(end - begin) {
    std::copy(begin, end, m_data);
  }
  explicit Vector(size_t n) // a Vector with n elements value-initialized.
      : m_size(n), m_capacity(n), m_data(new int[n]()) {}

  Vector(const Vector &other)
      : m_size(other.m_size), m_capacity(other.m_capacity),
        m_data(new int[m_capacity]) {
    std::copy(other.m_data, other.m_data + other.m_size, m_data);
  }
  Vector &operator=(const Vector &other) {
    int *new_data = new int[other.m_capacity];
    std::copy(other.m_data, other.m_data + other.m_size, new_data);
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    delete[] m_data;
    m_data = new_data;
    return *this;
  }
  ~Vector() {
    delete[] m_data;
  }

  void push_back(int x) {
    check_and_realloc();
    m_data[m_size++] = x;
  }
  void pop_back() {
    --m_size;
  }

  void shrink_to_fit() {
    if (m_size)
      reallocate(m_size);
    else {
      delete[] m_data;
      m_data = nullptr;
      m_capacity = 0;
    }
  }
  void clear() {
    m_size = 0;
  }

  size_t size() const {
    return m_size;
  }
  size_t capacity() const {
    return m_capacity;
  }
  bool empty() const {
    return size() == 0;
  }

  int &front() {
    return m_data[0];
  }
  const int &front() const {
    return m_data[0];
  }
  int &back() {
    return m_data[m_size - 1];
  }
  const int &back() const {
    return m_data[m_size - 1];
  }

  int &at(size_t n) {
    return m_data[n];
  }
  const int &at(size_t n) const {
    return m_data[n];
  }

 private:
  void reallocate(size_t new_cap) {
    int *new_data = new int[new_cap];
    std::copy(m_data, m_data + m_size, new_data);
    delete[] m_data;
    m_capacity = new_cap;
    m_data = new_data;
  }

  void check_and_realloc() {
    if (m_size == m_capacity)
      reallocate(m_capacity ? m_capacity * 2 : 1);
  }

  friend bool operator==(const Vector &, const Vector &);
  friend bool operator<(const Vector &, const Vector &);
};

inline bool operator==(const Vector &lhs, const Vector &rhs) {
  if (lhs.m_size != rhs.m_size)
    return false;
  for (size_t i = 0; i < lhs.m_size; ++i)
    if (lhs.m_data[i] != rhs.m_data[i])
      return false;
  return true;
}

inline bool operator<(const Vector &lhs, const Vector &rhs) {
  size_t size = std::min(lhs.m_size, rhs.m_size);
  for (size_t i = 0; i < size; ++i) {
    if (lhs.m_data[i] < rhs.m_data[i])
      return true;
    if (rhs.m_data[i] < lhs.m_data[i])
      return false;
  }
  return lhs.m_size < rhs.m_size;
}

inline bool operator!=(const Vector &lhs, const Vector &rhs) {
  return !(lhs == rhs);
}

inline bool operator>(const Vector &lhs, const Vector &rhs) {
  return rhs < lhs;
}

inline bool operator<=(const Vector &lhs, const Vector &rhs) {
  return !(lhs > rhs);
}

inline bool operator>=(const Vector &lhs, const Vector &rhs) {
  return !(lhs < rhs);
}

void print_vector(const Vector &vec) {
  for (size_t i = 0; i + 1 < vec.size(); ++i)
    std::cout << vec.at(i) << ' ';
  if (vec.size() > 1)
    std::cout << vec.back();
}

#endif // CS100_VECTOR_HPP
