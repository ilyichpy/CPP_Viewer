#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <cstring>
#include <iostream>

#include "../controller/s21_settings.h"
#include "widget_ogl.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  // удалить
  int counter = 0;

 private slots:
  void PushOpenFileButton();
  void setupSettings();
  void on_bgColor_clicked();
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();
  void on_lineWidth_valueChanged(double arg1);
  void closeEvent(QCloseEvent *event);
  void on_lineType_currentIndexChanged(int index);
  void on_vertexType_currentIndexChanged(int index);
  void on_vertexSize_valueChanged(double arg1);
  void on_projection_currentIndexChanged(int index);
  void on_rotateX_valueChanged(int value);
  void on_rotateY_valueChanged(int value);
  void on_rotateZ_valueChanged(int value);
  void on_moveX_valueChanged(double arg1);
  void on_moveY_valueChanged(double arg1);
  void on_moveZ_valueChanged(double arg1);
  void on_zoom_valueChanged(int value);

 private:
  Ui::MainWindow *s21;
};
#endif  // MAINWINDOW_H
