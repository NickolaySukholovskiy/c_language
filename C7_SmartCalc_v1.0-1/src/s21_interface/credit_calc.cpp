#include "credit_calc.h"
#include "ui_credit_calc.h"
#include <iostream>

//extern "C" {
//#include "../backend/s21_calc.h"
//}

credit_calc::credit_calc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::credit_calc)
{
    ui->setupUi(this);
}

credit_calc::~credit_calc()
{
    delete ui;
}

void credit_calc::on_pushButton_x_clicked()
{
    double ammount = ui->doubleSpinBox_1->value();
    double percent = ui->doubleSpinBox_2->value();
    int months = ui->spinBox->text().toInt();

    if (ui->radioButton_1->isChecked()) {
        double result = 0;
        if (percent == 0)
        {
            ui->lineEdit_7->setText(QString::number(ammount, 'f', 2));
        }
        else
        {
            annuitent_function(ammount, percent, months, &result);
            std::cout << result << '\n';
            ui->lineEdit_7->setText(QString::number(result, 'f', 2));
            ui->lineEdit_8->setText(QString::number(months * result - ammount, 'f', 2));
            ui->lineEdit_9->setText(QString::number(months * result, 'f', 2));
        }
    }
    else
    {
        double result_1 = 0, result_2 = 0, result_percent = 0;
        differential_function(ammount, percent, months, &result_1, &result_2, &result_percent);
        ui->lineEdit_7->setText(QString::number(result_1, 'f', 2) + " - " + QString::number(result_2, 'f', 2));
        ui->lineEdit_8->setText(QString::number(result_percent, 'f', 2));
        ui->lineEdit_9->setText(QString::number(result_percent + ammount, 'f', 2));
    }
}
