#include "mainwindow.h"
#include "ui_mainwindow.h"

double first_number;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_pm, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_procent, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_division, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_division->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    QString label_text;

    if (ui->label->text().contains(".") && button->text() == "0") {
        label_text = ui->label->text() + button->text();
    } else {
        double number = (ui->label->text() + button->text()).toDouble();
        label_text = QString::number(number, 'g', 15);
    }

    ui->label->setText(label_text);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (!(ui->label->text().contains('.'))){
        ui->label->setText(ui->label->text() + ".");
    }

}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();
    double number;
    QString label_text;

    if (button->text() == "+/-"){
        number = (ui->label->text()).toDouble();
        number *= -1;
        label_text = QString::number(number, 'g', 15);

        ui->label->setText(label_text);
    } else if (button->text() == "%") {
        number = (ui->label->text()).toDouble();
        number *= 0.01;
        label_text = QString::number(number, 'g', 15);

        ui->label->setText(label_text);
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();

    first_number = ui->label->text().toDouble();
    ui->label->setText("");

    button->setChecked(true);
}

void MainWindow::on_pushButton_ac_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_division->setChecked(false);

    ui->label->setText("0");
}

void MainWindow::on_pushButton_equal_clicked()
{
    double label_number, second_number;
    QString label_text;

    second_number = ui->label->text().toDouble();

    if (ui->pushButton_plus->isChecked()) {
        label_number = first_number + second_number;

        QString label_text = QString::number(label_number, 'g', 15);
        ui->label->setText(label_text);
        ui->pushButton_plus->setChecked(false);
    } else if (ui->pushButton_minus->isChecked()) {
        label_number = first_number - second_number;

        QString label_text = QString::number(label_number, 'g', 15);
        ui->label->setText(label_text);
        ui->pushButton_minus->setChecked(false);
    } else if (ui->pushButton_mult->isChecked()) {
        label_number = first_number * second_number;

        QString label_text = QString::number(label_number, 'g', 15);
        ui->label->setText(label_text);
        ui->pushButton_mult->setChecked(false);
    } else if (ui->pushButton_division->isChecked()) {
        if (second_number == 0) {
            ui->label->setText("0");
        } else {
            label_number = first_number / second_number;

            QString label_text = QString::number(label_number, 'g', 15);
            ui->label->setText(label_text);
        }

        ui->pushButton_division->setChecked(false);
    }
}
