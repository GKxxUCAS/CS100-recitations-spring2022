#ifndef CS100_DEMO_PICTURE_HPP
#define CS100_DEMO_PICTURE_HPP

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

class Picture {
 public:
  using size_type = std::size_t;

 private:
  size_type height{0}, width{0};
  std::string content{};

  void copy_block(size_type self_r, size_type self_c, const Picture &p) {
    for (size_type i = 0; i < p.get_height(); ++i)
      for (size_type j = 0; j < p.get_width(); ++j)
        at(self_r + i, self_c + j) = p.at(i, j);
  }

 public:
  Picture() = default;
  Picture(size_type h, size_type w)
      : height(h), width(w), content(h * w, ' ') {}
  Picture(const std::string *begin, const std::string *end)
      : height(end - begin) {
    for (auto i = begin; i != end; ++i)
      if (i->size() > width)
        width = i->size();
    content.resize(height * width, ' ');
    for (size_type i = 0; i < height; ++i, ++begin)
      for (size_type j = 0; j < begin->size(); ++j)
        at(i, j) = (*begin)[j];
  }
  char &at(size_type i, size_type j) {
    return content[i * width + j];
  }
  const char &at(size_type i, size_type j) const {
    return content[i * width + j];
  }
  void show(std::ostream &os) const {
    for (size_type i = 0; i < height; ++i) {
      for (size_type j = 0; j < width; ++j)
        os << at(i, j);
      if (i + 1 != height)
        os << std::endl;
    }
  }
  size_type get_height() const {
    return height;
  }
  size_type get_width() const {
    return width;
  }
  friend Picture operator|(const Picture &, const Picture &);
  friend Picture operator&(const Picture &, const Picture &);
  friend Picture add_frame(const Picture &);
};

inline std::ostream &operator<<(std::ostream &os, const Picture &p) {
  p.show(os);
  return os;
}

Picture operator|(const Picture &left, const Picture &right) {
  auto h = std::max(left.get_height(), right.get_height());
  auto w = left.get_width() + right.get_width();
  Picture ret(h, w);
  ret.copy_block(0, 0, left);
  ret.copy_block(0, left.width, right);
  return ret;
}

Picture operator&(const Picture &up, const Picture &down) {
  auto h = up.get_height() + down.get_height();
  auto w = std::max(up.get_width(), down.get_width());
  Picture ret(h, w);
  ret.copy_block(0, 0, up);
  ret.copy_block(up.get_height(), 0, down);
  return ret;
}

Picture add_frame(const Picture &pic) {
  auto h = pic.get_height(), w = pic.get_width();
  Picture ret(h += 2, w += 2);
  ret.at(0, 0) = '+';
  ret.at(0, w - 1) = '+';
  ret.at(h - 1, 0) = '+';
  ret.at(h - 1, w - 1) = '+';
  for (decltype(h) i = 1; i < w - 1; ++i) {
    ret.at(0, i) = '-';
    ret.at(h - 1, i) = '-';
  }
  for (decltype(w) i = 1; i < h - 1; ++i) {
    ret.at(i, 0) = '|';
    ret.at(i, w - 1) = '|';
  }
  ret.copy_block(1, 1, pic);
  return ret;
}

#endif // CS100_DEMO_PICTURE_HPP