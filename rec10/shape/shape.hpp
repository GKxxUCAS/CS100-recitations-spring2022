#ifndef CS100_DEMO_SHAPE_HPP
#define CS100_DEMO_SHAPE_HPP

#include <cmath>

class Shape_base {
 public:
  virtual double perimeter() const = 0;
  virtual double area() const = 0;
  virtual ~Shape_base() = default;
  Shape_base() = default;
};

class Rectangle : public Shape_base {
  double height, width;

 public:
  Rectangle(double h, double w) : Shape_base(), height(h), width(w) {}
  virtual double perimeter() const override {
    return 2 * (height + width);
  }
  virtual double area() const override {
    return height * width;
  }
};

class Circle : public Shape_base {
  double radius;

 public:
  Circle(double r) : Shape_base(), radius(r) {}
  virtual double perimeter() const override {
    return 2 * M_PI * radius;
  }
  virtual double area() const override {
    return M_PI * radius * radius;
  }
};

#endif // CS100_DEMO_SHAPE_HPP