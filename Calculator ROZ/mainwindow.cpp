#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QList>
#include <QDebug>
#include <QJSEngine>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Lista tuturor butoanelor din UI
    QList<QPushButton*> allButtons = {
        ui->button0, ui->button1, ui->button2, ui->button3, ui->button4,
        ui->button5, ui->button6, ui->button7, ui->button8, ui->button9,
        ui->buttonPlus, ui->buttonMinus, ui->buttonInmultire, ui->buttonImpartire,
        ui->buttonPunct, ui->buttonEgal, ui->buttonClear,
        ui->buttonSin, ui->buttonCos, ui->buttonTan, ui->buttonCot,
        ui->buttonLn, ui->buttonLog, ui->buttonPi, ui->buttonE, ui->buttonRadical,
        ui->buttonParantezaStanga, ui->buttonParantezaDreapta,
        ui->buttonElaX, ui->buttonModul, ui->buttonInvers, ui->buttonLaPutere,
        ui->buttonMC, ui->buttonMR, ui->buttonMPlus, ui->buttonDegRad
    };

    for (QPushButton* btn : allButtons) {
        connect(btn, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QString btnText = button->text();

    if (btnText == "C") {
        ui->lineEdit->clear();
        awaitingModulClose = false;
        return;
    }

    if (btnText == "=") {
        QString expression = ui->lineEdit->text();

        // Înlocuiri simboluri matematice vizuale
        expression.replace(QChar(0x00D7), "*"); // ×
        expression.replace(QChar(0x00F7), "/"); // ÷
        expression.replace(QChar(0x2212), "-"); // −

        // Înlocuiri constante
        expression.replace("π", "3.14159265359");
        expression.replace("e", "2.71828182846");

        // Trigonometrie: sin, cos, tan
        expression.replace("sin", "Math.sin");
        expression.replace("cos", "Math.cos");
        expression.replace("tan", "Math.tan");

        // Cotangenta: cot(x) = 1 / tan(x)
        static const QRegularExpression cotRegex(R"(cot\(([^)]+)\))");
        expression.replace(cotRegex, "1/Math.tan(\\1)");


        // Puteri: ^ -> **
        expression.replace("^", "**");

        // √(x) sau √x
        expression.replace("√(", "Math.sqrt(");
        static const QRegularExpression sqrtRegex(R"(√(\d+(\.\d+)?))");
        expression.replace(sqrtRegex, "Math.sqrt(\\1)");

        // log(x) → Math.log10(x)
        expression.replace("log(", "Math.log10(");

        // ln(x) → Math.log(x)
        expression.replace("ln(", "Math.log(");

        // |x| → Math.abs(x)
        static const QRegularExpression modRegex(R"(\|([^|]+)\|)");
        expression.replace(modRegex, "Math.abs(\\1)");

        // 1/x
        static const QRegularExpression inverseRegex(R"(1\/\(([^()]+)\))");
        expression.replace(inverseRegex, "1/(\\1)");

        // Dacă suntem în modul grade, convertim în radiani
        if (isDegrees) {
            static const QRegularExpression degToRad(R"((Math\.(sin|cos|tan))\(([^()]+)\))");
            expression.replace(degToRad, "Math.\\2((\\3)*Math.PI/180)");
        }


        QJSEngine engine;
        QJSValue result = engine.evaluate(expression);

        if (result.isError()) {
            ui->lineEdit->setText("Eroare");
        } else {
            ui->lineEdit->setText(result.toString());
        }

        return;
    }

    // eˣ
    if (button == ui->buttonElaX) {
        ui->lineEdit->setText(ui->lineEdit->text() + "e^");
        return;
    }

    // |x|
    if (button == ui->buttonModul) {
        if (!awaitingModulClose) {
            ui->lineEdit->setText(ui->lineEdit->text() + "|");
            awaitingModulClose = true;
        } else {
            ui->lineEdit->setText(ui->lineEdit->text() + "|");
            awaitingModulClose = false;
        }
        return;
    }

    // Deg/Rad toggle
    if (button == ui->buttonDegRad) {
        isDegrees = !isDegrees;
        ui->buttonDegRad->setText(isDegrees ? "Deg" : "Rad");
        return;
    }


    // Memorie
    if (button == ui->buttonMC) {
        memoryValue = 0.0;
        return;
    }

    if (button == ui->buttonMR) {
        ui->lineEdit->setText(ui->lineEdit->text() + QString::number(memoryValue));
        return;
    }

    if (button == ui->buttonMPlus) {
        QString currentText = ui->lineEdit->text();
        QJSEngine engine;
        QJSValue result = engine.evaluate(currentText);
        if (!result.isError()) {
            memoryValue += result.toNumber();
        }
        return;
    }

    // Adăugăm inversa 1/x
    if (button == ui->buttonInvers) {
        ui->lineEdit->setText(ui->lineEdit->text() + "1/(");
        return;
    }

    // Adăugăm cot
    if (button == ui->buttonCot) {
        ui->lineEdit->setText(ui->lineEdit->text() + "cot(");
        return;
    }

    // Adăugăm restul butoanelor normal
    ui->lineEdit->setText(ui->lineEdit->text() + btnText);
}
