#include "modelviewer.h"

#include <iostream>

modelViewer::modelViewer(QWidget *parent)
    : QOpenGLWidget(
          parent)  // indexBuffer(QOpenGLBuffer::IndexBuffer), rotationAngle(0)
{
  background_color = QVector3D(0.5, 0.5, 0.5);
  position_x = 0;
  position_y = 0;
  position_z = 0;
  ballerina = NULL;
}

modelViewer::~modelViewer() {
  if (filepath.isEmpty() != true) {
    removemodel(ballerina);
  }
}

void modelViewer::initializeGL() {
  initializeOpenGLFunctions();
  viewMatrix.setToIdentity();
  viewMatrix.translate(0, -0.2, -1);

  glEnable(GL_DEPTH_TEST);
  InitShaders();
}

void modelViewer::resizeGL(int w, int h) {
  aspect = w / (float)h;
  //  aspect = 0;
  //  m_projectionMatrix.setToIdentity();  // делаем матрицу единичной
  // перспектива видимая область = 45, соотношение сторон, потом видимая область
  // от 0.1 до 100
  change_projection(0);
}

void modelViewer::paintGL() {
  glClearColor(background_color[0], background_color[1], background_color[2],
               1.0);  // чистим окно и делаем его чёрным
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  QMatrix4x4 modelMatrix;
  modelMatrix.setToIdentity();

  m_program.bind();
  m_program.setUniformValue("u_projectionMatrix", m_projectionMatrix);
  m_program.setUniformValue("u_viewMatrix", viewMatrix);
  if (filepath.isEmpty() == 0) {
    bal->draw(&m_program, context()->functions());
  }
}

void modelViewer::InitShaders() {
  if (!m_program.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                         "://vshader.vsh")) {
    qDebug() << "Vertex shader didn't compile";
  }

  if (!m_program.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                         "://fshader.fsh")) {
    qDebug() << "Fragment shader didn't compile";
  }
  if (!m_program.link()) {
    qDebug() << "Shader linking has failed";
  }
}

void modelViewer::InitModel() {
  if (filepath.isEmpty() != true) {
    if (ballerina != NULL) {
      removemodel(ballerina);
    }
    ballerina = (model *)calloc(1, sizeof(model));
    modelParser(ballerina, filepath.toStdString().c_str());
    bal = new SimpleObject3D(ballerina);
  }
}
//------------------------------------------------------
// Функции с мышкой
//------------------------------------------------------

void modelViewer::mousePressEvent(QMouseEvent *event) {
  if (event->buttons() == Qt::LeftButton) {
    mousePosition = QVector2D(event->localPos());
  }
  event->accept();
}

void modelViewer::mouseMoveEvent(QMouseEvent *event) {
  if (event->buttons() != Qt::LeftButton) {
    return;
  }
  QVector2D diff = QVector2D(event->localPos()) - mousePosition;
  mousePosition = QVector2D(event->localPos());

  float angle = diff.length() / 2;

  QVector3D axis = QVector3D(diff.y(), diff.x(), 0);

  m_rotation = QQuaternion::fromAxisAndAngle(axis, angle);

  RotateModel();
  update();
}

void modelViewer::wheelEvent(QWheelEvent *event) {
  QPoint numDegrees = event->angleDelta() / 5;

  if (numDegrees.y() > 0) {
    viewMatrix.scale(1.05, 1.05, 1.05);  // fix
  } else if (numDegrees.y() < 0) {
    viewMatrix.scale(0.95, 0.95, 0.95);  // fix
  }
  update();
}

void modelViewer::closeEvent(QCloseEvent *event) { exit(0); }

void modelViewer::RotateModel() {
  viewMatrix.rotate(m_rotation);
  update();
}

void modelViewer::getFilepath(QString file) {
  filepath = file;
  InitModel();
  update();
}

void modelViewer::get_obj_color(QVector3D color) {
  if (filepath.isEmpty() != true) {
    bal->set_obj_color(color);
    update();
  }
}

void modelViewer::set_background_color(QVector3D color) {
  background_color = color;
  update();
}

void modelViewer::get_point_color(QVector3D color) {
  if (filepath.isEmpty() != true) {
    bal->set_point_color(color);
    update();
  }
}

void modelViewer::get_line_type(QString type) {
  if (filepath.isEmpty() != true) {
    bal->set_line_type(type);
    update();
  }
}

void modelViewer::get_point_type(QString type) {
  if (filepath.isEmpty() != true) {
    bal->set_point_type(type);
    update();
  }
}

void modelViewer::set_obj_width(float width, float size) {
  if (filepath.isEmpty() != true) {
    bal->set_width(width, size);
    update();
  }
}

void modelViewer::change_x_coordinate(int value) {
  viewMatrix.translate(-position_x, 0, 0);
  position_x = (float)value / 100;
  viewMatrix.translate(position_x, 0, 0);
  update();
}

void modelViewer::change_y_coordinate(int value) {
  viewMatrix.translate(0, -position_y, 0);
  position_y = (float)value / 100;
  viewMatrix.translate(0, position_y, 0);
  update();
}

void modelViewer::change_z_coordinate(int value) {
  viewMatrix.translate(0, 0, -position_z);
  position_z = (float)value / 100;
  viewMatrix.translate(0, 0, position_z);
  update();
}

void modelViewer::change_projection(int condition) {
  m_projectionMatrix.setToIdentity();
  if (condition == 0) {
    m_projectionMatrix.perspective(45, aspect, 0.1f, 100.0f);
  } else {
    m_projectionMatrix.ortho(-1.0f * aspect, 1.0 * aspect, -1.0f, 1.0f, 0.1f,
                             10.0f);
  }
}
