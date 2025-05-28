#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "storage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_editButton_clicked();
    void on_table_doubleClicked(const QModelIndex &index);
    void on_filterButton_clicked();
    void on_resetFilterButton_clicked();

private:
    Ui::MainWindow *ui;
    Storage storage;
    QStandardItemModel *model;
    void updateProductList(const QString &filter = "");
    void updateStatusBar();
    void clearInputFields();
    void setupStyles();
};

#endif
