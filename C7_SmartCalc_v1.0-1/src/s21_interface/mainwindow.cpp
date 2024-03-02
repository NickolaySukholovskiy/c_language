#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));

    connect(ui->pushButton_left_bracket, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_right_bracket, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));

    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_point, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(get_operator_number_from_button()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(get_function_from_button()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(get_function_from_button()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(get_function_from_button()));

    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(get_function_from_button()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(get_function_from_button()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(get_function_from_button()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(get_function_from_button()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(get_function_from_button()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(get_function_from_button()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::get_operator_number_from_button() {
    if (symbol_flag == 1) {
        ui->lineEdit->setText("");
        symbol_flag = 0;
    }
    QPushButton *button = (QPushButton*)sender();
    ui->lineEdit->setText(ui->lineEdit->text() + button->text());
    if (button->text() == 'x') {
        x_flag = 1;
    }
}

void MainWindow::get_function_from_button() {
    if (symbol_flag == 1) {
        ui->lineEdit->setText("");
        symbol_flag = 0;
    }
    QPushButton *button = (QPushButton*)sender();
    ui->lineEdit->setText(ui->lineEdit->text() + button->text() + '(');
}

void MainWindow::on_pushButton_graph_clicked()
{
    int int_result = 0;
    QString result = ui->lineEdit->text();
    if (result != "") {
        QByteArray byte_str = result.toLocal8Bit();
        char *prefix_str = byte_str.data();

        if (int_result == FAILURE) {
            QMessageBox::warning(this, "Ошибка", "Ошибка в записи выражения");
        }
        else {
            int minX = ui->spinBox_1->text().toInt();
            int maxX = ui->spinBox_2->text().toInt();
            if (minX < maxX)
            {
                graph_window graph;
                graph.setModal(true);
                graph.show_graph(prefix_str, x_flag, minX, maxX);
                graph.exec();
            }
            else
            {
                QMessageBox::warning(this, "Ошибка", "Неверно заданы границы x");
            }
        }
    }
}


void MainWindow::on_pushButton_equal_clicked()
{
    QString result = ui->lineEdit->text();
    int int_result = SUCCESS;

    if (result == "") {
        QMessageBox::warning(this, "Ошибка", "Вы ничего не ввели");
    }
    else {
        QByteArray byte_str = result.toLocal8Bit();
        char *prefix_str = byte_str.data();

        if (x_flag == 1) {
            int_result = FAILURE;
        }
        else {
            double double_result = 0;
            int_result = s21_connect_number(prefix_str, &double_result);
            ui->lineEdit->setText(QString::number(double_result, 'g'));
        }
    }
    if (int_result == FAILURE) {
        QMessageBox::warning(this, "Ошибка", "Ошибка в записи выражения");
    }
    x_flag = 0;
    symbol_flag = 1;
}


void MainWindow::on_pushButton_delete_clicked()
{
    ui->lineEdit->setText("");
}


void MainWindow::on_pushButton_credit_clicked()
{
    credit_calc calc;
    calc.setModal(true);
    calc.exec();
}


void MainWindow::on_pushButton_contribution_clicked()
{
    Contribution_calc calc;
    calc.setModal(true);
    calc.exec();
}

