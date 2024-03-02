#include "contribution_calc.h"
#include "ui_contribution_calc.h"

Contribution_calc::Contribution_calc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Contribution_calc)
{
    ui->setupUi(this);
}

Contribution_calc::~Contribution_calc()
{
    delete ui;
}

void Contribution_calc::on_pushButton_x_clicked()
{
    double ammount = ui->doubleSpinBox_1->value();
    double percent = ui->doubleSpinBox_2->value();
    int months = ui->spinBox->text().toInt();

    if (percent != 0)
    {
        double result = 0;
        contribution_function(ammount, percent, months, &result);
        ui->lineEdit_8->setText(QString::number(result - ammount, 'f', 2));
        ui->lineEdit_9->setText(QString::number(result, 'f', 2));
    }
    else
    {
        ui->lineEdit_8->setText(QString::number(0, 'f', 2));
        ui->lineEdit_9->setText(QString::number(ammount, 'f', 2));
    }
}

