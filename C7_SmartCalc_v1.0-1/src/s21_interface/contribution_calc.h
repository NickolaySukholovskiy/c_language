#ifndef CONTRIBUTION_CALC_H
#define CONTRIBUTION_CALC_H

#include <QDialog>

extern "C" {
#include "../backend/s21_calc.h"
}

namespace Ui {
class Contribution_calc;
}

class Contribution_calc : public QDialog
{
    Q_OBJECT

public:
    explicit Contribution_calc(QWidget *parent = nullptr);
    ~Contribution_calc();

private slots:
    void on_pushButton_x_clicked();

private:
    Ui::Contribution_calc *ui;
};

#endif // CONTRIBUTION_CALC_H
