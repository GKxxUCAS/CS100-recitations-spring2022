#ifndef CS100_DEMO_ITEMS_HPP
#define CS100_DEMO_ITEMS_HPP

#include <cstddef>
#include <iostream>
#include <string>

class Item {
 private:
  std::string name;

 protected:
  double price = 0.0;

 public:
  Item() = default;
  Item(const std::string &s, double p) : name(s), price(p) {}
  std::string get_name() const {
    return name;
  }
  virtual double net_price(std::size_t n) const {
    return n * price;
  }
  virtual ~Item() = default;
};

class Discounted_item : public Item {
  std::size_t min_quantity = 0;
  double discount = 1.0;

 public:
  Discounted_item() = default;
  Discounted_item(const std::string &s, double p, std::size_t qty, double disc)
      : Item(s, p), min_quantity(qty), discount(disc) {}
  virtual double net_price(std::size_t n) const override {
    if (n >= min_quantity)
      return n * discount * price;
    else
      return n * price;
  }
};

inline void print_item(const Item &item) {
  std::cout << "name: " << item.get_name() << ", price: " << item.net_price(1);
}

#endif // CS100_DEMO_ITEMS_HPP