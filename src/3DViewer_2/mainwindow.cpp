#include "mainwindow.h"

#include <QCloseEvent>
#include <QColorDialog>
#include <QMessageBox>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), s21(new Ui::MainWindow) {
  s21->setupUi(this);
  std::string path = QApplication::applicationFilePath().toStdString();
  int counter = 0;
  int position = 0;
  for (unsigned long i = 0; i < path.length() && counter <= 3; i++) {
    if (path[i] == '/') counter++;
    position = i;
  }
  std::string user_path = path.substr(0, position);
  QString qt_user_path = QString::fromStdString(user_path);
  s21->UserName->setText("> " + qt_user_path);
  connect(s21->OpenFile, SIGNAL(clicked()), this, SLOT(PushOpenFileButton()));
  connect(s21->bgButton, SIGNAL(clicked()), this, SLOT(on_bgColor_clicked()));
  connect(s21->Edge, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
  connect(s21->Vertex, SIGNAL(clicked()), this,
          SLOT(on_pushButton_2_clicked()));
  setupSettings();
}

MainWindow::~MainWindow() { delete s21; }

/**
 * @brief method for setting start value of decorate fields
 */
void MainWindow::setupSettings() {
  s21->openGLWidget->settings.lineColor.g = 0.8;
  s21->openGLWidget->settings.vertexColor.r = 0.8;
  s21->openGLWidget->settings.lineThickness = 1;
  s21->openGLWidget->settings.vertexSize = 1;

  QColor color = QColor::fromRgbF(s21->openGLWidget->settings.bgColor.r,
                                  s21->openGLWidget->settings.bgColor.g,
                                  s21->openGLWidget->settings.bgColor.b);
  s21->bgColor->setStyleSheet("background-color: #" +
                              QString::number(color.rgb(), 16));
  color = QColor::fromRgbF(s21->openGLWidget->settings.lineColor.r,
                           s21->openGLWidget->settings.lineColor.g,
                           s21->openGLWidget->settings.lineColor.b);
  s21->edgeColor->setStyleSheet("background-color: #" +
                                QString::number(color.rgb(), 16));
  color = QColor::fromRgbF(s21->openGLWidget->settings.vertexColor.r,
                           s21->openGLWidget->settings.vertexColor.g,
                           s21->openGLWidget->settings.vertexColor.b);
  s21->vertexColor->setStyleSheet("background-color: #" +
                                  QString::number(color.rgb(), 16));
  s21->lineWidth->setValue(s21->openGLWidget->settings.lineThickness);
  s21->lineType->setCurrentIndex(s21->openGLWidget->settings.lineType);
  s21->vertexSize->setValue(s21->openGLWidget->settings.vertexSize);
  s21->vertexType->setCurrentIndex(s21->openGLWidget->settings.vertexType);
  s21->projection->setCurrentIndex(s21->openGLWidget->settings.projectionType);
}

/**
 * @brief method for pushing open file button activate process of drawing 3D
 * model
 */
void MainWindow::PushOpenFileButton() {
  QString FullPass = QFileDialog::getOpenFileName(
      this, "choose file", QDir::currentPath(), ".obj(*.obj)");

  if (!FullPass.isEmpty()) {
    QString CopyFileName = FullPass;
    QString FileName = FullPass.remove(0, FullPass.lastIndexOf('/') + 1);
    if (FileName.isEmpty()) {
      s21->ProgramName->setText("Path error");
    } else {
      s21->ProgramName->setText(FileName);
      s21->ProgramName->setText(FileName);
      s21->openGLWidget->clearObjectData();
      s21->rotateX->setValue(0);
      s21->rotateY->setValue(0);
      s21->rotateZ->setValue(0);
      s21->moveX->setValue(0);
      s21->moveX->setValue(0);
      s21->moveX->setValue(0);
      s21->zoom->setValue(0);
      s21->openGLWidget->initData(CopyFileName.toStdString());
      cout << s21->vertexType->currentIndex();
      s21->vertexes->setText(
          "Counter of vertexes: " +
          QString::number(s21->openGLWidget->parserController.parser.result
                              .count_of_vertexes));
      s21->Faces->setText("Counter of facets: " +
                          QString::number(s21->openGLWidget->parserController
                                              .parser.result.count_of_facets /
                                          2 * 3));
    }
  }
}
/**
 * @brief change background color method
 */
void MainWindow::on_bgColor_clicked() {
  QColor color = QColorDialog::getColor(Qt::black, this, "Background color");
  if (color.isValid()) {
    s21->openGLWidget->settings.bgColor.r = color.redF();
    s21->openGLWidget->settings.bgColor.g = color.greenF();
    s21->openGLWidget->settings.bgColor.b = color.blueF();
    s21->bgColor->setStyleSheet("background-color: #" +
                                QString::number(color.rgb(), 16));
    s21->openGLWidget->update();
  }
}

/**
 * @brief change line color method
 */
void MainWindow::on_pushButton_clicked()  // Edge color button
{
  QColor color = QColorDialog::getColor(Qt::green, this, "Edge color");
  if (color.isValid()) {
    s21->openGLWidget->settings.lineColor.r = color.redF();
    s21->openGLWidget->settings.lineColor.g = color.greenF();
    s21->openGLWidget->settings.lineColor.b = color.blueF();
    s21->edgeColor->setStyleSheet("background-color: #" +
                                  QString::number(color.rgb(), 16));
    s21->openGLWidget->update();
  }
}

/**
 * @brief change points color method
 */
void MainWindow::on_pushButton_2_clicked()  // Vertices color button
{
  QColor color = QColorDialog::getColor(Qt::white, this, "Vertex color");
  if (color.isValid()) {
    s21->openGLWidget->settings.vertexColor.r = color.redF();
    s21->openGLWidget->settings.vertexColor.g = color.greenF();
    s21->openGLWidget->settings.vertexColor.b = color.blueF();
    s21->vertexColor->setStyleSheet("background-color: #" +
                                    QString::number(color.rgb(), 16));
  }
}

/**
 * @brief change line width method
 */
void MainWindow::on_lineWidth_valueChanged(double arg1) {
  s21->openGLWidget->settings.lineThickness = arg1;
  s21->openGLWidget->update();
}

/**
 * @brief change line type method
 */
void MainWindow::on_lineType_currentIndexChanged(int index) {
  s21->openGLWidget->settings.lineType = index;
  s21->openGLWidget->update();
}

/**
 * @brief change point type method
 */
void MainWindow::on_vertexType_currentIndexChanged(int index) {
  s21->openGLWidget->settings.vertexType = index;
  s21->openGLWidget->update();
}

/**
 * @brief change point size method
 */
void MainWindow::on_vertexSize_valueChanged(double arg1) {
  s21->openGLWidget->settings.vertexSize = arg1;
  s21->openGLWidget->update();
}

/**
 * @brief change projection stype method
 */
void MainWindow::on_projection_currentIndexChanged(int index) {
  s21->openGLWidget->settings.projectionType = index;
  s21->openGLWidget->update();
}

/**
 * @brief rotate X method
 */
void MainWindow::on_rotateX_valueChanged(int value) {
  value -= s21->openGLWidget->x_angle;
  s21->openGLWidget->x_angle += value;
  s21->openGLWidget->parserController.parser.result.matrix.rotation_x(value);
  s21->openGLWidget->updateMatrix();
}

/**
 * @brief rotate Y method
 */
void MainWindow::on_rotateY_valueChanged(int value) {
  value -= s21->openGLWidget->y_angle;
  s21->openGLWidget->y_angle += value;
  s21->openGLWidget->parserController.parser.result.matrix.rotation_y(value);
  s21->openGLWidget->updateMatrix();
}

/**
 * @brief rotate Z method
 */
void MainWindow::on_rotateZ_valueChanged(int value) {
  value -= s21->openGLWidget->z_angle;
  s21->openGLWidget->z_angle += value;
  s21->openGLWidget->parserController.parser.result.matrix.rotation_z(value);
  s21->openGLWidget->updateMatrix();
}

/**
 * @brief move X method
 */
void MainWindow::on_moveX_valueChanged(double arg1) {
  arg1 -= s21->openGLWidget->x_pos;
  s21->openGLWidget->x_pos += arg1;
  s21->openGLWidget->parserController.parser.result.matrix.move_x(arg1);
  s21->openGLWidget->updateMatrix();
}

/**
 * @brief move Y method
 */

void MainWindow::on_moveY_valueChanged(double arg1) {
  arg1 -= s21->openGLWidget->y_pos;
  s21->openGLWidget->y_pos += arg1;
  s21->openGLWidget->parserController.parser.result.matrix.move_y(arg1);
  s21->openGLWidget->updateMatrix();
}

/**
 * @brief move z method
 */

void MainWindow::on_moveZ_valueChanged(double arg1) {
  arg1 -= s21->openGLWidget->z_pos;
  s21->openGLWidget->z_pos += arg1;
  s21->openGLWidget->parserController.parser.result.matrix.move_z(arg1);
  s21->openGLWidget->updateMatrix();
}

/**
 * @brief method for zoom
 */

void MainWindow::on_zoom_valueChanged(int value) {
  s21->openGLWidget->parserController.parser.result.matrix.scale_xyz(
      -s21->openGLWidget->zoom_help);
  s21->openGLWidget->zoom_help = value;
  s21->openGLWidget->parserController.parser.result.matrix.scale_xyz(value);
  s21->openGLWidget->updateMatrix();
}

/**
 * @brief method for close Event. It starts when user try to close mainWindow.
 */
void MainWindow::closeEvent(QCloseEvent *event) {
  QMessageBox::StandardButton resBtn = QMessageBox::question(
      this, "3D Viewer", tr("Are you sure?\n"),
      QMessageBox::Cancel | QMessageBox::Yes, QMessageBox::Yes);
  if (resBtn != QMessageBox::Yes) {
    event->ignore();
  } else {
    s21->openGLWidget->clearObjectData();
    event->accept();
  }
}
