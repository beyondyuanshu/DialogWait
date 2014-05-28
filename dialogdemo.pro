#-------------------------------------------------
#
# Project created by QtCreator 2014-05-28T13:46:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DialogDemo
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    dialogwait.cpp

HEADERS  += dialog.h \
    dialogwait.h \
    dialogthread.h

FORMS    += dialog.ui
