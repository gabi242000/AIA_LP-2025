#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

class Product {
public:
    Product(const QString &name = "", int quantity = 0, double price = 0.0);

    QString getName() const;
    int getQuantity() const;
    double getPrice() const;

    void setQuantity(int quantity);
    void setPrice(double price);

private:
    QString name;
    int quantity;
    double price;
};

#endif
