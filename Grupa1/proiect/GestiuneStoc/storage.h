#ifndef STORAGE_H
#define STORAGE_H

#include <QVector>
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QDir>
#include <QStandardPaths>
#include "product.h"

class Storage
{
public:
    Storage();
    ~Storage();

    void addProduct(const Product &product);
    bool removeProduct(const QString &productName);
    QVector<Product> getAllProducts() const;
    bool productExists(const QString &productName) const;


    bool saveToFile();
    bool loadFromFile();

private:
    QVector<Product> products;
    QString getDataFilePath() const;
};

#endif
