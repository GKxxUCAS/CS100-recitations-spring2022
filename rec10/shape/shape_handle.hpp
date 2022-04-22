#ifndef CS100_DEMO_SHAPE_HPP
#define CS100_DEMO_SHAPE_HPP

#include <cmath>

class Shape_base {
  friend class Shape;

  int use{1};

  virtual double perimeter() const = 0;
  virtual double area() const = 0;

 protected:
  virtual ~Shape_base() = default;
  Shape_base() = default;
};

class Shape {
  Shape_base *bp;

 public:
  double perimeter() const {
    return bp->perimeter();
  }
  double area() const {
    return bp->area();
  }
  bool is_null() const {
    return !bp;
  }
  Shape(const Shape &other) : bp(other.bp) {
    if (bp)
      ++bp->use;
  }
  Shape &operator=(const Shape &other) {
    if (other.bp)
      ++other.bp->use;
    if (bp && !--bp->use)
      delete bp;
    bp = other.bp;
    return *this;
  }
  ~Shape() {
    if (!--bp->use)
      delete bp;
  }

 private:
  Shape(Shape_base *p) : bp(p) {}
};

class Rectangle : public Shape_base {
  friend Shape make_rectangle(double, double);

  double height, width;

  Rectangle(double h, double w) : height(h), width(w) {}
  virtual double perimeter() const override {
    return 2 * (height + width);
  }
  virtual double area() const override {
    return height * width;
  }
};

class Circle : public Shape_base {
  friend Shape make_circle(double);

  double radius;

  Circle(double r) : radius(r) {}
  virtual double perimeter() const override {
    return 2 * M_PI * radius;
  }
  virtual double area() const override {
    return M_PI * radius * radius;
  }
};

#endif // CS100_DEMO_SHAPE_HPP