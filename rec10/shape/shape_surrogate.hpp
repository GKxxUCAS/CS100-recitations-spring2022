#ifndef CS100_DEMO_SHAPE_HPP
#define CS100_DEMO_SHAPE_HPP

#include <cmath>

class Shape_base {
  friend class Shape;

  virtual double perimeter() const = 0;
  virtual double area() const = 0;

 protected:
  virtual ~Shape_base() = default;
  Shape_base() = default;
  virtual Shape_base *clone() const = 0;
};

class Shape {
  friend Shape make_rectangle(double, double);
  friend Shape make_circle(double);

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
  Shape() : bp(nullptr) {}
  Shape(const Shape &other) : bp(other.bp ? other.bp->clone() : nullptr) {}
  Shape &operator=(const Shape &other) {
    auto p = other.bp ? other.bp->clone() : nullptr;
    delete bp;
    bp = p;
    return *this;
  }
  ~Shape() {
    delete bp;
  }

 private:
  Shape(Shape_base *p) : bp(p) {}
};

class Rectangle : public Shape_base {
  friend class Shape;
  friend Shape make_rectangle(double, double);

  double height, width;

  Rectangle(double h, double w) : Shape_base(), height(h), width(w) {}
  virtual double perimeter() const override {
    return 2 * (height + width);
  }
  virtual double area() const override {
    return height * width;
  }
  virtual Rectangle *clone() const override {
    return new Rectangle(height, width);
  }
};

inline Shape make_rectangle(double h, double w) {
  return new Rectangle(h, w);
}

class Circle : public Shape_base {
  friend class Shape;
  friend Shape make_circle(double);

  double radius;

  Circle(double r) : Shape_base(), radius(r) {}
  virtual double perimeter() const override {
    return 2 * M_PI * radius;
  }
  virtual double area() const override {
    return M_PI * radius * radius;
  }
  virtual Circle *clone() const override {
    return new Circle(radius);
  }
};

inline Shape make_circle(double r) {
  return new Circle(r);
}

#endif // CS100_DEMO_SHAPE_HPP