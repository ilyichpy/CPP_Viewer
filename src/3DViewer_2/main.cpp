#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
#ifdef Q_OS_LINUX
  setlocale(LC_NUMERIC, "C");
#endif
  MainWindow w;
  w.show();
  return a.exec();
}
