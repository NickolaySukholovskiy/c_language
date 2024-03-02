#ifndef GRAPH_WINDOW_H
#define GRAPH_WINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "../qcustom/qcustomplot.h"

extern "C" {
#include "../backend/s21_calc.h"
}

namespace Ui {
class graph_window;
}

class graph_window : public QDialog
{
    Q_OBJECT

public:
    explicit graph_window(QWidget *parent = nullptr);
    ~graph_window();
    void show_graph(char *prefix_str, int x_flag, int minX, int maxX);

private:
    Ui::graph_window *ui;

};

#endif // GRAPH_WINDOW_H
