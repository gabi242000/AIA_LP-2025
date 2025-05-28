/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGroupBox *inputGroup;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *nameLineEdit;
    QLabel *label_2;
    QSpinBox *quantitySpinBox;
    QLabel *label;
    QDoubleSpinBox *priceDoubleSpinBox;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *removeButton;
    QGroupBox *filterGroup;
    QGridLayout *gridLayout;
    QLineEdit *filterLineEdit;
    QPushButton *filterButton;
    QPushButton *resetFilterButton;
    QTableView *productTableView;
    QMenuBar *menubar;
    QMenu *menuSTOC;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(754, 613);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        inputGroup = new QGroupBox(centralwidget);
        inputGroup->setObjectName("inputGroup");
        verticalLayout = new QVBoxLayout(inputGroup);
        verticalLayout->setObjectName("verticalLayout");
        label_3 = new QLabel(inputGroup);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        nameLineEdit = new QLineEdit(inputGroup);
        nameLineEdit->setObjectName("nameLineEdit");

        verticalLayout->addWidget(nameLineEdit);

        label_2 = new QLabel(inputGroup);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        quantitySpinBox = new QSpinBox(inputGroup);
        quantitySpinBox->setObjectName("quantitySpinBox");

        verticalLayout->addWidget(quantitySpinBox);

        label = new QLabel(inputGroup);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        priceDoubleSpinBox = new QDoubleSpinBox(inputGroup);
        priceDoubleSpinBox->setObjectName("priceDoubleSpinBox");
        priceDoubleSpinBox->setDecimals(2);
        priceDoubleSpinBox->setMaximum(100000000.000000000000000);

        verticalLayout->addWidget(priceDoubleSpinBox);

        addButton = new QPushButton(inputGroup);
        addButton->setObjectName("addButton");

        verticalLayout->addWidget(addButton);

        editButton = new QPushButton(inputGroup);
        editButton->setObjectName("editButton");

        verticalLayout->addWidget(editButton);

        removeButton = new QPushButton(inputGroup);
        removeButton->setObjectName("removeButton");

        verticalLayout->addWidget(removeButton);

        filterGroup = new QGroupBox(inputGroup);
        filterGroup->setObjectName("filterGroup");
        gridLayout = new QGridLayout(filterGroup);
        gridLayout->setObjectName("gridLayout");
        filterLineEdit = new QLineEdit(filterGroup);
        filterLineEdit->setObjectName("filterLineEdit");

        gridLayout->addWidget(filterLineEdit, 0, 0, 1, 1);

        filterButton = new QPushButton(filterGroup);
        filterButton->setObjectName("filterButton");

        gridLayout->addWidget(filterButton, 1, 0, 1, 1);

        resetFilterButton = new QPushButton(filterGroup);
        resetFilterButton->setObjectName("resetFilterButton");

        gridLayout->addWidget(resetFilterButton, 2, 0, 1, 1);


        verticalLayout->addWidget(filterGroup);


        gridLayout_2->addWidget(inputGroup, 0, 0, 1, 1);

        productTableView = new QTableView(centralwidget);
        productTableView->setObjectName("productTableView");
        productTableView->setMinimumSize(QSize(541, 0));
        productTableView->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(productTableView, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 754, 25));
        menuSTOC = new QMenu(menubar);
        menuSTOC->setObjectName("menuSTOC");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSTOC->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        inputGroup->setTitle(QCoreApplication::translate("MainWindow", "Introducere produs", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Nume produs", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Cantitate", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Pret", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Adauga produs", nullptr));
        editButton->setText(QCoreApplication::translate("MainWindow", "Modifica produs", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "Sterge produs", nullptr));
        filterGroup->setTitle(QCoreApplication::translate("MainWindow", "Filtreaza produsele", nullptr));
        filterButton->setText(QCoreApplication::translate("MainWindow", "Aplica filtrul", nullptr));
        resetFilterButton->setText(QCoreApplication::translate("MainWindow", "Reseteaza filtrul", nullptr));
        menuSTOC->setTitle(QCoreApplication::translate("MainWindow", "STOC", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
