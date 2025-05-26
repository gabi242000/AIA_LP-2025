#include "mainwindow.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Tema roz pentru aplicatie
    qApp->setStyleSheet(R"(
        QWidget {
            background-color: #ffeaf4;
            font-family: 'Segoe UI';
            font-size: 14px;
        }

        QLineEdit {
            background-color: white;
            border: 2px solid #f5a3c7;
            border-radius: 10px;
            padding: 8px;
            color: #333;
        }

        QPushButton {
            background-color: #f8b6d2;
            color: #fff;
            border: none;
            padding: 12px;
            border-radius: 10px;
        }

        QPushButton:hover {
            background-color: #f59fc1;
        }

        QPushButton:pressed {
            background-color: #e68ab5;
        }
    )");


    // Titlu personalizat in bara de sus
    w.setWindowTitle("Calculator Roz cu Expresii 🌸");

    w.show();
    return a.exec();
}
