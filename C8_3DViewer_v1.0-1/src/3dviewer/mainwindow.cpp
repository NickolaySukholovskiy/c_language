#include "mainwindow.h"

#include <QDialogButtonBox>
#include <iostream>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  modelWidget = new modelViewer(this);
  settings = new QSettings();
  ui->gridLayout->addWidget(modelWidget);
  timerGif = new QTimer(this);
  connect(this, SIGNAL(sendFilepath(QString)), modelWidget,
          SLOT(getFilepath(QString)));
  connect(timerGif, SIGNAL(timeout()), this, SLOT(recordSlot()));
  connect(this, SIGNAL(width_and_size_changed(float, float)), modelWidget,
          SLOT(set_obj_width(float, float)));
}

MainWindow::~MainWindow() {
  saveSettings();
  delete ui;
}

void MainWindow::on_pushButton_load_clicked() { loadSettings(); }

void MainWindow::loadSettings() {
  backgroundColor =
      settings->value("backgroundColor", QVector3D(1.0f, 1.0f, 0.0f))
          .value<QVector3D>();
  modelWidget->set_background_color(backgroundColor);

  fileName = settings->value("modelPath", fileName).value<QString>();
  emit sendFilepath(fileName);

  modelColor = settings->value("modelColor", QVector3D(1.0f, 1.0f, 1.0f))
                   .value<QVector3D>();
  modelWidget->get_obj_color(modelColor);

  pointColor = settings->value("pointColor", QVector3D(1.0f, 1.0f, 1.0f))
                   .value<QVector3D>();
  modelWidget->get_point_color(pointColor);

  width = settings->value("modelWidth", width).value<float>();
  size = settings->value("modelSize", size).value<float>();
  emit width_and_size_changed(width, size);
  ui->spinBox_obj_W->setValue(width);
  ui->spinBox_obj_P->setValue(size);

  line_type = settings->value("modelPointType", line_type).value<QString>();
  modelWidget->get_line_type(line_type);

  point_type = settings->value("modelPointType", point_type).value<QString>();
  modelWidget->get_point_type(point_type);

  x = settings->value("modelX", x).value<int>();
  if (x >= -20 && x <= 20) {
    modelWidget->change_x_coordinate(x);
  }

  y = settings->value("modelY", y).value<int>();
  if (y >= -20 && y <= 20) {
    modelWidget->change_y_coordinate(y);
  }

  z = settings->value("modelZ", z).value<int>();
  modelWidget->change_z_coordinate(z);
  if (z >= -20 && z <= 20) {
    modelWidget->change_z_coordinate(z);
  }
}

void MainWindow::saveSettings() {
  settings->setValue("backgroundColor", backgroundColor);
  settings->setValue("modelColor", modelColor);
  settings->setValue("pointColor", pointColor);
  settings->setValue("modelPath", fileName);
  settings->setValue("modelWidth", width);
  settings->setValue("modelSize", size);
  settings->setValue("modelPointType", point_type);
  settings->setValue("modelLineType", line_type);
  settings->setValue("modelX", x);
  settings->setValue("modelY", y);
  settings->setValue("modelZ", z);
}

void MainWindow::on_change_model_button_clicked() {
  fileName = QFileDialog::getOpenFileName(
      this, tr("Выберите модель"),
      "/Users/margertf/Desktop/projects/C_Projects", tr("Object Files (*.obj)"),
      0, QFileDialog::DontUseNativeDialog);
  emit sendFilepath(fileName);
}

void MainWindow::on_pushButton_apply_color_clicked() {
  red = (float)ui->spinBox_obj_R->value();
  green = (float)ui->spinBox_obj_G->value();
  blue = (float)ui->spinBox_obj_B->value();

  if (ui->radioButton_obj->isChecked()) {
    modelColor = QVector3D(red, green, blue);
    modelWidget->get_obj_color(modelColor);
  } else if (ui->radioButton_back->isChecked()) {
    backgroundColor = QVector3D(red, green, blue);
    modelWidget->set_background_color(backgroundColor);
  } else {
    pointColor = QVector3D(red, green, blue);
    modelWidget->get_point_color(pointColor);
  }
}

void MainWindow::on_pushButton_apply_width_clicked() {
  width = ui->spinBox_obj_W->value();
  size = ui->spinBox_obj_P->value();
  emit width_and_size_changed(width, size);
}

void MainWindow::on_btnScreenShot_clicked() {
  QImage imageOfModel = modelWidget->grabFramebuffer();
  if (ui->comboBox->currentIndex() == 0) {
    QString saveLocation = QFileDialog::getSaveFileName(
        this, "Set filename and location to save", "/",
        tr("JPEG files (*.jpg)"), 0, QFileDialog::DontUseNativeDialog);
    imageOfModel.save(saveLocation, "JPEG");
  } else if (ui->comboBox->currentIndex() == 1) {
    QString saveLocation = QFileDialog::getSaveFileName(
        this, "Set filename and location to save", "/", tr("BMP files (*.bmp)"),
        0, QFileDialog::DontUseNativeDialog);
    imageOfModel.save(saveLocation, "BMP");
  }
}

void MainWindow::on_btnRecordGif_clicked() {
  gifka = new QGifImage(/*QSize(640, 480)*/);
  gifFilePath = QFileDialog::getSaveFileName(
      this, "Specify where to save a file", "/", tr("GIF files (*.gif)"), 0,
      QFileDialog::DontUseNativeDialog);
  timerGif->start(100);
}

void MainWindow::recordSlot() {
  QImage modelImage = modelWidget->grabFramebuffer();
  //    modelImage = modelImage.scaled(640, 480);
  gifka->addFrame(modelImage);
  if (gifka->frameCount() == 50) {
    timerGif->stop();
    gifka->setDefaultDelay(100);
    bool saveRes = gifka->save(gifFilePath);
    QString saveAlert;
    if (saveRes) {
      saveAlert = "File saved at" + gifFilePath;
    } else {
      saveAlert = "Gif wasn't saved, something went wrong(";
    }
    qDebug() << saveAlert;
    delete gifka;
    gifka = NULL;
  }
  qDebug() << "recordSlot";
}

void MainWindow::on_comboBox_line_currentTextChanged(QString arg1) {
  line_type = arg1;
  modelWidget->get_line_type(arg1);
}

void MainWindow::on_comboBox_point_currentTextChanged(QString arg1) {
  point_type = arg1;
  modelWidget->get_point_type(arg1);
}

void MainWindow::on_horizontalSlider_X_valueChanged(int value) {
  x = value;
  modelWidget->change_x_coordinate(value);
}

void MainWindow::on_horizontalSlider_Y_valueChanged(int value) {
  y = value;
  modelWidget->change_y_coordinate(value);
}

void MainWindow::on_horizontalSlider_Z_valueChanged(int value) {
  z = value;
  modelWidget->change_z_coordinate(value);
}

void MainWindow::on_checkBox_change_view_stateChanged(int arg1) {
  qInfo() << arg1;
  modelWidget->change_projection(arg1);
}
