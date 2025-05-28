#include "storage.h"
#include <QDebug>

Storage::Storage()
{

    loadFromFile();
}

Storage::~Storage()
{

    saveToFile();
}
//adauga produs
void Storage::addProduct(const Product &product) {
    products.append(product);
    saveToFile();
}
//sterge produs dupa nume
bool Storage::removeProduct(const QString &productName) {
    for (int i = 0; i < products.size(); ++i) {
        if (products[i].getName() == productName) {
            products.remove(i);
            saveToFile();
            return true;
        }
    }
    return false;
}

QVector<Product> Storage::getAllProducts() const {
    return products;
}
//verifica produs daca exista
bool Storage::productExists(const QString &productName) const {
    for (const Product &p : products) {
        if (p.getName() == productName) {
            return true;
        }
    }
    return false;
}
//pathing pt json
QString Storage::getDataFilePath() const {
    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(dataPath);
    if (!dir.exists()) {
        dir.mkpath(dataPath);
    }
    return dataPath + "/products.json";
}

bool Storage::saveToFile() {
    QString filePath = getDataFilePath();

    QJsonArray jsonArray;
    for (const Product &product : products) {
        QJsonObject productObj;
        productObj["name"] = product.getName();
        productObj["quantity"] = product.getQuantity();
        productObj["price"] = product.getPrice();
        jsonArray.append(productObj);
    }

    QJsonDocument doc(jsonArray);

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Nu pot deschide fisierul pentru scriere:" << filePath;
        return false;
    }

    file.write(doc.toJson());
    file.close();

    qDebug() << "Produse salvate in:" << filePath;
    return true;
}

bool Storage::loadFromFile() {
    QString filePath = getDataFilePath();

    QFile file(filePath);
    if (!file.exists()) {
        qDebug() << "Fisierul nu exista inca:" << filePath;
        return true;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Nu pot deschide fisierul pentru citire:" << filePath;
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray()) {
        qDebug() << "Formatul fisierului nu este valid";
        return false;
    }

    products.clear();
    QJsonArray jsonArray = doc.array();

    for (const QJsonValue &value : jsonArray) {
        QJsonObject obj = value.toObject();
        QString name = obj["name"].toString();
        int quantity = obj["quantity"].toInt();
        double price = obj["price"].toDouble();

        products.append(Product(name, quantity, price));
    }

    qDebug() << "Incarcate" << products.size() << "produse din:" << filePath;
    return true;
}
