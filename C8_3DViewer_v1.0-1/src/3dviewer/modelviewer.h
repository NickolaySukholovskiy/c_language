#ifndef MODELVIEWER_H
#define MODELVIEWER_H

#include <QMatrix4x4>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>
#include <QTimer>
#include <QVector3D>
#include <QWidget>

#include "simpleobject3d.h"

extern "C" {
#include "../parser_v2.h"
}

class modelViewer : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  explicit modelViewer(QWidget *parent = nullptr);
  ~modelViewer();
  void get_obj_color(QVector3D color);
  void set_background_color(QVector3D color);
  void get_point_color(QVector3D color);
  void get_line_type(QString type);
  void get_point_type(QString type);
  void change_x_coordinate(int value);
  void change_y_coordinate(int value);
  void change_z_coordinate(int value);
  void change_projection(int statue);
  SimpleObject3D *bal;

 protected:
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;
  void InitShaders();
  void InitModel();

  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void wheelEvent(QWheelEvent *event) override;
  void closeEvent(QCloseEvent *event) override;

 public slots:
  void RotateModel();
  void getFilepath(QString filename);
  void set_obj_width(float width, float size);

 signals:
  void rotate(int rotationAngle);
  void send_line_width(float width, float size);

 private:
  float aspect;
  int condition;
  float position_x;
  float position_y;
  float position_z;
  model *ballerina;
  // Square position and size
  QMatrix4x4 m_projectionMatrix;
  QOpenGLShaderProgram m_program;
  QMatrix4x4 viewMatrix;
  int rotationAngle;
  QVector2D mousePosition;
  QQuaternion m_rotation;
  QString filepath;

  QVector3D background_color;
};

#endif  // MODELVIEWER_H
