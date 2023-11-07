QT       += opengl openglwidgets core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    widget_ogl.cpp \
    ../model/s21_parser.cc \
    ../model/matrix/*.cc \
    ../controller/s21_parser_controller.cc \


HEADERS += \
    mainwindow.h \
    widget_ogl.h \
    ../model/*.h \
    ../model/matrix/*.h \
    ../controller/*.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
