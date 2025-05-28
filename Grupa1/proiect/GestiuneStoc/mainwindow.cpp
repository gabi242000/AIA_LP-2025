#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    model = new QStandardItemModel(this);
    model->setColumnCount(3);
    model->setHorizontalHeaderLabels({"Nume", "Cantitate", "Pret (lei)"});


    ui->productTableView->setModel(model);
    ui->productTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->productTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->productTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


    ui->productTableView->setStyleSheet(
        "QTableView { border: 1px solid #ddd; gridline-color: #eee; }"
        "QHeaderView::section { "
        "   background-color: #4CAF50; "
        "   color: white; "
        "   padding: 5px; "
        "   border: none; "
        "}"
        );


    connect(ui->productTableView, &QTableView::doubleClicked, this, &MainWindow::on_table_doubleClicked);


    ui->inputGroup->setStyleSheet(
        "QGroupBox { "
        "   border: 1px solid #ddd; "
        "   border-radius: 5px; "
        "   margin-top: 1ex; "
        "} "
        "QGroupBox::title { "
        "   subcontrol-origin: margin; "
        "   left: 10px; "
        "   padding: 0 3px; "
        "}"
        );


    ui->addButton->setStyleSheet(
        "QPushButton { "
        "   background-color: #4CAF50; "
        "   color: white; "
        "   border: none; "
        "   padding: 5px 10px; "
        "   border-radius: 3px; "
        "} "
        "QPushButton:hover { "
        "   background-color: #45a049; "
        "}"
        );

    ui->removeButton->setStyleSheet(
        "QPushButton { "
        "   background-color: #f44336; "
        "   color: white; "
        "   border: none; "
        "   padding: 5px 10px; "
        "   border-radius: 3px; "
        "} "
        "QPushButton:hover { "
        "   background-color: #d32f2f; "
        "}"
        );

    ui->editButton->setStyleSheet(
        "QPushButton { "
        "   background-color: #f39c12; "
        "   color: white; "
        "   border: none; "
        "   padding: 5px 10px; "
        "   border-radius: 3px; "
        "} "
        "QPushButton:hover { "
        "   background-color: #d68910; "
        "}"
        );


    connect(ui->productTableView, &QTableView::doubleClicked, this, &MainWindow::on_table_doubleClicked);
    connect(ui->filterButton, &QPushButton::clicked, this, &MainWindow::on_filterButton_clicked);
    connect(ui->resetFilterButton, &QPushButton::clicked, this, &MainWindow::on_resetFilterButton_clicked);


    updateProductList();
    updateStatusBar();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;

}

void MainWindow::setupStyles()
{

    this->setStyleSheet("background-color: #f5f5f5;");

    ui->productTableView->setStyleSheet(
        "QTableView {"
        "   border: 1px solid #ddd;"
        "   gridline-color: #eee;"
        "   background-color: white;"
        "   selection-background-color: #e3f2fd;"
        "}"
        "QHeaderView::section {"
        "   background-color: #4CAF50;"
        "   color: white;"
        "   padding: 6px;"
        "   border: none;"
        "   font-weight: bold;"
        "}"
        );


    QString groupBoxStyle =
        "QGroupBox {"
        "   border: 1px solid #ddd;"
        "   border-radius: 5px;"
        "   margin-top: 10px;"
        "   background-color: white;"
        "}"
        "QGroupBox::title {"
        "   subcontrol-origin: margin;"
        "   left: 10px;"
        "   padding: 0 5px;"
        "}";

    ui->inputGroup->setStyleSheet(groupBoxStyle);
    ui->filterGroup->setStyleSheet(groupBoxStyle);


    QString buttonStyle =
        "QPushButton {"
        "   padding: 8px 12px;"
        "   border-radius: 4px;"
        "   font-weight: bold;"
        "   min-width: 80px;"
        "   border: none;"
        "}"
        "QPushButton:hover { opacity: 0.9; }";

    ui->addButton->setStyleSheet(buttonStyle + "background-color: #4CAF50; color: white;");
    ui->removeButton->setStyleSheet(buttonStyle + "background-color: #f44336; color: white;");
    ui->editButton->setStyleSheet(buttonStyle + "background-color: #2196F3; color: white;");
    ui->filterButton->setStyleSheet(buttonStyle + "background-color: #9b59b6; color: white;");
    ui->resetFilterButton->setStyleSheet(buttonStyle + "background-color: #95a5a6; color: white;");


    QString inputStyle =
        "QLineEdit, QSpinBox, QDoubleSpinBox {"
        "   padding: 5px;"
        "   border: 1px solid #ddd;"
        "   border-radius: 3px;"
        "   background-color: white;"
        "}";

    ui->nameLineEdit->setStyleSheet(inputStyle);
    ui->quantitySpinBox->setStyleSheet(inputStyle);
    ui->priceDoubleSpinBox->setStyleSheet(inputStyle);
    ui->filterLineEdit->setStyleSheet(inputStyle);
}

void MainWindow::updateProductList(const QString &filter)
{
    model->removeRows(0, model->rowCount());
//adauga doar produsele filtrate
    for (const Product &p : storage.getAllProducts()) {
        if (!filter.isEmpty() && !p.getName().contains(filter, Qt::CaseInsensitive)) {
            continue;
        }

        QList<QStandardItem*> rowItems;
        rowItems << new QStandardItem(p.getName());
        rowItems << new QStandardItem(QString::number(p.getQuantity()));
        rowItems << new QStandardItem(QString::number(p.getPrice(), 'f', 2));


        for (QStandardItem* item : rowItems) {
            item->setTextAlignment(Qt::AlignCenter);
        }


        if (p.getQuantity() < 3) {
            for (QStandardItem* item : rowItems) {
                item->setBackground(QBrush(QColor(255, 230, 230)));
                item->setForeground(QBrush(QColor(200, 0, 0)));
            }
        }

        model->appendRow(rowItems);
    }
}
//bara de status
void MainWindow::updateStatusBar()
{
    int totalProducts = storage.getAllProducts().size();
    int filteredProducts = model->rowCount();
    int lowStockItems = 0;
    double totalValue = 0.0;

    for (const Product &p : storage.getAllProducts()) {
        totalValue += p.getPrice() * p.getQuantity();
        if (p.getQuantity() < 3) lowStockItems++;
    }

    QString statsText = QString("Produse: %1 (%2 afisate) | Valoare totala: %3 lei | Stoc redus: %4")
                            .arg(totalProducts)
                            .arg(filteredProducts)
                            .arg(totalValue, 0, 'f', 2)
                            .arg(lowStockItems);

    statusBar()->showMessage(statsText);
}

void MainWindow::clearInputFields()
{
    ui->nameLineEdit->clear();
    ui->quantitySpinBox->setValue(0);
    ui->priceDoubleSpinBox->setValue(0.0);
}
//add buton
void MainWindow::on_addButton_clicked()
{
    QString name = ui->nameLineEdit->text().trimmed();
    int quantity = ui->quantitySpinBox->value();
    double price = ui->priceDoubleSpinBox->value();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Eroare", "Numele produsului este gol!");
        return;
    }

    storage.addProduct(Product(name, quantity, price));
    updateProductList(ui->filterLineEdit->text());
    updateStatusBar();
    clearInputFields();
}
// remove button
void MainWindow::on_removeButton_clicked()
{
    QModelIndexList selected = ui->productTableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Eroare", "Selectati un produs!");
        return;
    }

    QString name = model->item(selected.first().row(), 0)->text();
    if (storage.removeProduct(name)) {
        updateProductList(ui->filterLineEdit->text());
        updateStatusBar();
    } else {
        QMessageBox::warning(this, "Eroare", "Produsul nu a fost gasit!");
    }
}
// edit button
void MainWindow::on_editButton_clicked()
{
    QModelIndexList selected = ui->productTableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Eroare", "Selectati un produs pentru editare!");
        return;
    }

    QString oldName = model->item(selected.first().row(), 0)->text();
    QString newName = ui->nameLineEdit->text().trimmed();
    int quantity = ui->quantitySpinBox->value();
    double price = ui->priceDoubleSpinBox->value();

    if (newName.isEmpty()) {
        QMessageBox::warning(this, "Eroare", "Numele produsului nu poate fi gol!");
        return;
    }

    storage.removeProduct(oldName);
    storage.addProduct(Product(newName, quantity, price));

    updateProductList(ui->filterLineEdit->text());
    updateStatusBar();
    clearInputFields();
}

void MainWindow::on_table_doubleClicked(const QModelIndex &index)
{
    QString name = model->item(index.row(), 0)->text();
    int quantity = model->item(index.row(), 1)->text().toInt();
    double price = model->item(index.row(), 2)->text().toDouble();

    ui->nameLineEdit->setText(name);
    ui->quantitySpinBox->setValue(quantity);
    ui->priceDoubleSpinBox->setValue(price);
}

void MainWindow::on_filterButton_clicked()
{
    QString filterText = ui->filterLineEdit->text().trimmed();
    updateProductList(filterText);
    updateStatusBar();
}

void MainWindow::on_resetFilterButton_clicked()
{
    ui->filterLineEdit->clear();
    updateProductList();
    updateStatusBar();
}
