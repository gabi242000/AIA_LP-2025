#include "product.h"

Product::Product(const QString &name, int quantity, double price)
    : name(name), quantity(quantity), price(price) {}

QString Product::getName() const {
    return name;
}

int Product::getQuantity() const {
    return quantity;
}

double Product::getPrice() const {
    return price;
}

void Product::setQuantity(int quantity) {
    this->quantity = quantity;
}

void Product::setPrice(double price) {
    this->price = price;
}
