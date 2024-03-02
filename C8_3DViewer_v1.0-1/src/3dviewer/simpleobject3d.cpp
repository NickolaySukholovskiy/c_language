#include "simpleobject3d.h"

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <iostream>

SimpleObject3D::SimpleObject3D(model *obj_model)
    : indexBuffer(QOpenGLBuffer::IndexBuffer) {
  point_type = "NONE";
  line_type = "SOLID";
  point_color = QVector3D(1, 1, 1);
  obj_color = QVector3D(0, 0, 0);
  point_size = 1;
  line_width = 1;
  model_to_free = obj_model;
  init_model(obj_model);
  init_index(obj_model);
};

void SimpleObject3D::init_model(model *obj_model) {
  vertexBuffer.create();
  vertexBuffer.bind();
  vertexBuffer.allocate(obj_model->vrtx->allVertecies,
                        obj_model->vrtx->amountOfPoints * sizeof(GLfloat));
  vertexBuffer.release();
  qInfo() << "points = "<< obj_model->vrtx->amountOfPoints;
  m_modelMatrix.setToIdentity();
}

void SimpleObject3D::init_index(model *model_obj) {
  QVector<GLuint> indexes;

  for (uint i = 0; i < (uint)model_obj->numOfPolygons; i++) {
    for (uint j = 0; j < model_obj->plgns[i].amountOfFaceElements; j++) {
      if (j == 0) {
        indexes.append(model_obj->plgns[i].faceElement[j]);
      } else if (j + 1 == model_obj->plgns[i].amountOfFaceElements) {
        indexes.append(model_obj->plgns[i].faceElement[j]);
        //               indexes.append(model_obj->plgns[i].faceElement[0]);
      } else {
        indexes.append(model_obj->plgns[i].faceElement[j]);
        indexes.append(model_obj->plgns[i].faceElement[j]);
      }
    }
  }
  indexBuffer.create();
  indexBuffer.bind();
  indexBuffer.allocate(indexes.constData(), indexes.size() * sizeof(GLuint));
  qInfo() << "polygon = " << indexes.size();
  indexBuffer.release();
}

SimpleObject3D::~SimpleObject3D() {
  if (vertexBuffer.isCreated()) {
    vertexBuffer.destroy();
  }
  if (indexBuffer.isCreated()) {
    indexBuffer.destroy();
  }
  removemodel(model_to_free);
}

void SimpleObject3D::draw(QOpenGLShaderProgram *program,
                          QOpenGLFunctions *functions) {
  program->setUniformValue("u_modelMatrix", m_modelMatrix);

  vertexBuffer.bind();

  int vertLoc = program->attributeLocation("a_position");
  program->enableAttributeArray(vertLoc);
  program->setAttributeBuffer(vertLoc, GL_FLOAT, 0, 3, 0);
  indexBuffer.bind();
  draw_model(program, functions);
  if (point_type != "NONE") {
    //    qInfo() << "points";
    draw_points(program, functions);
  }
  vertexBuffer.release();
  indexBuffer.release();
}

void SimpleObject3D::draw_points(QOpenGLShaderProgram *program,
                                 QOpenGLFunctions *functions) {
  if (point_type == "CIRCLE") {
    glEnable(GL_POINT_SMOOTH);
  }
  glPointSize(point_size);
  QVector4D f_color(point_color, 1.0f);
  program->setUniformValue("color", f_color);
  functions->glDrawElements(GL_POINTS, indexBuffer.size(), GL_UNSIGNED_INT, 0);
  if (point_type == "CIRCLE") {
    glDisable(GL_POINT_SMOOTH);
  }
}

void SimpleObject3D::draw_model(QOpenGLShaderProgram *program,
                                QOpenGLFunctions *functions) {
  if (line_type == "DASHED") {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(3, 0x00ff);
  }
  glLineWidth(line_width);
  QVector4D f_color(obj_color, 1.0f);
  program->setUniformValue("color", f_color);
  functions->glDrawElements(GL_LINES, indexBuffer.size(), GL_UNSIGNED_INT, 0);
  if (line_type == "DASHED") {
    glDisable(GL_LINE_STIPPLE);
  }
}

void SimpleObject3D::set_obj_color(QVector3D color) { obj_color = color; }

void SimpleObject3D::set_width(float width, float size) {
  line_width = width;
  point_size = size;
}

void SimpleObject3D::set_point_color(QVector3D color) { point_color = color; }

void SimpleObject3D::set_line_type(QString type) { line_type = type; }

void SimpleObject3D::set_point_type(QString type) { point_type = type; }
