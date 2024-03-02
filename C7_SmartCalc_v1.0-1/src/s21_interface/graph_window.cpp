#include "graph_window.h"
#include "ui_graph_window.h"
#include <iostream>
#include <QDebug>

graph_window::graph_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graph_window)
{
    ui->setupUi(this);
}

graph_window::~graph_window()
{
    delete ui;
}

void graph_window::show_graph(char *prefix_str, int x_flag, int minX, int maxX)
{
    double a = minX;
    double b = maxX;
    double h = 0.01;
    int N = (b - a) / h + 2;
    QVector<double> x(N), y(N);
    double result = 0;
    char *ptr_postfix = new char[255];
    char *str_to_free = ptr_postfix;
    char *str_postfix = str_to_free;
    int int_result = string_parser_to_postfix(&prefix_str, &ptr_postfix);

        if (x_flag == 1 && int_result == SUCCESS) {
            int i = 0;
            for (double X = a; X <= b; X += h) {
                if (X < 0.01 && X > 0)
                {
                    X = 0;
                }
                if (from_postfix_to_result(&str_postfix, &result, X) == SUCCESS)
                {
                    int_result = from_postfix_to_result(&str_postfix, &result, X);
                    x[i] = X;
                    y[i] = result;
                }
//                std::cout << x[i] << ' ' << y[i] << '\n';
                i++;
            }
        }
        else if (int_result == SUCCESS){
        int_result = from_postfix_to_result(&str_postfix, &result, 0);
        int i = 0;
        if (int_result == SUCCESS)
        {
            for (double X = a; X <= b; X += h) {
                x[i] = X;
                y[i] = result;
                i++;
            }
        }
    }

    if (int_result == SUCCESS)
    {
        ui->widget->clearGraphs();
        ui->widget->addGraph();
        ui->widget->graph(0)->setData(x, y);
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");

        double minY = y[0], maxY = y[0];
        for (int i = 1; i < N; i++) {
            if (y[i] < minY) minY = y[i];
            if (y[i] > maxY) maxY = y[i];
        }

        double minX = x[0], maxX = x[0];
        for (int i = 1; i < N; i++) {
            if (x[i] < minX) minX = x[i];
            if (x[i] > maxX) maxX = x[i];
        }

        ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy
        ui->widget->xAxis->setRange(minX, maxX);
        std::cout << minX << ' ' << maxX << '\n';
        ui->widget->replot();
    }

    free(str_to_free);
}
