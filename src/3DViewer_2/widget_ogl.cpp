#include "widget_ogl.h"

#include <QFileDialog>
#include <QMessageBox>
#include <filesystem>

Widget_OGL::Widget_OGL(QWidget* parent) : QOpenGLWidget(parent) {
  coords = nullptr;
}

void Widget_OGL::clearObjectData() {
  parserController.cleanModel();
  if (matrix != nullptr) {
    delete[] matrix;
  }
  x_angle = 0;
  y_angle = 0;
  z_angle = 0;
  x_pos = 0;
  y_pos = 0;
  z_pos = 0;
}

void Widget_OGL::initData(std::string name) {
  parserController.makeModel(name);
  int counter = 0;
  matrix = new double[3 * parserController.parser.result.count_of_vertexes];
  for (int i = 0; i < parserController.parser.result.count_of_vertexes; ++i) {
    for (int j = 0; j < 3; ++j) {
      matrix[counter] = parserController.parser.result.matrix(i, j);
      ++counter;
    }
  }
  if (parserController.parser.result.status != s21::OK) {
    QMessageBox::critical(this, "warning", "Failed to read the file");
  }
  update();
}

void Widget_OGL::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  glScalef(0.25, 0.25, 0.25);
  glLineStipple(1, 0x00F0);
}
void Widget_OGL::resizeGL(int h, int w) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
}
void Widget_OGL::paintGL() {
  glLoadIdentity();

  glClearColor(settings.bgColor.r, settings.bgColor.g, settings.bgColor.b, 0);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if (settings.projectionType == 0) {
    glOrtho(-2.5, 2.5, -2.5, 2.5, -50, 50);
  } else {
    glFrustum(-0.8, 0.8, -0.8, 0.8, 0.9, 5);
    glTranslated(0, 0, -2.5);
  }

  glLineWidth(settings.lineThickness);

  if (settings.lineType) {
    glEnable(GL_LINE_STIPPLE);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }

  glPointSize(settings.vertexSize);

  if (settings.vertexType == 1) {
    glEnable(GL_POINT_SMOOTH);
  } else {
    glDisable(GL_POINT_SMOOTH);
  }

  glEnableClientState(GL_VERTEX_ARRAY);

  if (settings.vertexType) {
    glColor3d(settings.vertexColor.r, settings.vertexColor.g,
              settings.vertexColor.b);
    glDrawArrays(GL_POINTS, 0,
                 parserController.parser.result.count_of_vertexes);
  }

  glColor3d(settings.lineColor.r, settings.lineColor.g, settings.lineColor.b);
  glVertexPointer(3, GL_DOUBLE, 0, matrix);

  glDrawElements(GL_LINES, parserController.parser.result.count_of_facets * 6,
                 GL_UNSIGNED_INT, parserController.parser.result.polygons);

  glDisableClientState(GL_VERTEX_ARRAY);
}

void Widget_OGL::updateMatrix() {
  if (matrix != nullptr) {
    int counter = 0;
    for (int i = 0; i < parserController.parser.result.matrix.GetRows(); ++i) {
      for (int j = 0; j < 3; ++j) {
        matrix[counter] = parserController.parser.result.matrix(i, j);
        ++counter;
      }
    }
  }
  update();
}
