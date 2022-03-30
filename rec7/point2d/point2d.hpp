#ifndef CS100_POINT2D_HPP
#define CS100_POINT2D_HPP

#include <iostream>

class Point2d {
  double m_x, m_y;

 public:
  Point2d() : m_x(0), m_y(0) {}
  Point2d(double x, double y) : m_x(x), m_y(y) {}
  double get_x() const {
    return m_x;
  }
  double get_y() const {
    return m_y;
  }
  Point2d &set_x(double x) {
    m_x = x;
    return *this;
  }
  Point2d &set_y(double y) {
    m_y = y;
    return *this;
  }
};

void print_point2d(std::ostream &os, const Point2d &point) {
  os << "(" << point.get_x() << ", " << point.get_y() << ")";
}

void read_point2d(std::istream &is, Point2d &point) {
  double x, y;
  is >> x >> y;
  if (is)
    point.set_x(x).set_y(y);
}

#endif // CS100_POINT2D_HPP
