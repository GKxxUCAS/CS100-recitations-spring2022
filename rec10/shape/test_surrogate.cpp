#include <iostream>
#include <vector>
#include "shape_surrogate.hpp"

int main() {
  std::vector<Shape> shapes;
  for (int i = 0; i < 3; ++i)
    shapes.push_back(make_rectangle(i + 2, i + 3));
  for (int i = 0; i < 3; ++i)
    shapes.push_back(make_circle(i + 1));
  for (const auto &shape : shapes)
    std::cout << "perimeter == " << shape.perimeter()
              << ", area == " << shape.area() << std::endl;
  for (auto &shape : shapes)
    shape.stretch(2);
  
  for (const auto &shape : shapes)
    std::cout << "perimeter == " << shape.perimeter()
              << ", area == " << shape.area() << std::endl;
  return 0;
}