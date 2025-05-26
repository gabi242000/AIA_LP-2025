#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onButtonClicked();
//    void onMemoryClearClicked();   // MC
 //   void onMemoryRecallClicked();  // MR
 //   void onMemoryAddClicked();     // M+
private:
    Ui::MainWindow *ui;

    // Pentru gestiunea butonului |x| (modul)
    bool awaitingModulClose = false;

    // Pentru conversia DEG/RAD
    bool isDegrees = false;

    // Pentru butoanele de memorie (MC, MR, M+)
    double memoryValue = 0.0;
};

#endif // MAINWINDOW_H
