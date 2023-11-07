#ifndef WIDGET_OGL_H
#define WIDGET_OGL_H

#include <QOpenGLContext>
#include <QOpenGLWidget>
#include <QSurfaceFormat>

#include "../controller/s21_parser_controller.h"
#include "../controller/s21_settings.h"

class Widget_OGL : public QOpenGLWidget {
  Q_OBJECT
 public:
  Widget_OGL(QWidget* parent = 0);
  void initializeGL();
  void resizeGL(int h, int w);
  void paintGL();
  s21::ParserController parserController;
  s21::Settings settings = {0};
  double* coords;
  void clearObjectData();
  double x_angle = 0;
  double y_angle = 0;
  double z_angle = 0;
  double x_pos = 0;
  double y_pos = 0;
  double z_pos = 0;
  double zoom_help = 0;
  void initData(std::string name);
  double* matrix = nullptr;
  void updateMatrix();
};

#endif  // WIDGET_OGL_H
