#ifndef SIMPLEOBJECT3D_H
#define SIMPLEOBJECT3D_H

#include <QMatrix4x4>
#include <QOpenGLBuffer>
#include <QVector3D>

extern "C" {
#include "../parser_v2.h"
}

class QOpenGLTexture;
class QOpenGLFunctions;
class QOpenGLShaderProgram;

class SimpleObject3D {
 public:
  SimpleObject3D(model *obj_model);
  ~SimpleObject3D();
  void init_model(model *model_obj);
  void init_index(model *model_obj);
  void draw(QOpenGLShaderProgram *program, QOpenGLFunctions *functions);
  void set_obj_color(QVector3D color);
  void set_width(float width, float size);
  void set_point_color(QVector3D color);
  void set_line_type(QString type);
  void set_point_type(QString type);

 private:
  void draw_points(QOpenGLShaderProgram *program, QOpenGLFunctions *functions);
  void draw_model(QOpenGLShaderProgram *program, QOpenGLFunctions *functions);

  model *model_to_free;
  QOpenGLBuffer vertexBuffer;
  QOpenGLBuffer indexBuffer;
  QMatrix4x4 m_modelMatrix;
  //    QOpenGLTexture *m_texture;
  QString filepath;

  QString line_type;
  QString point_type;

  float line_width;
  float point_size;

  QVector3D point_color;
  QVector3D obj_color;
};

#endif  // SIMPLEOBJECT3D_H
