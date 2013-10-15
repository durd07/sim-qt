######################################################################
# Automatically generated by qmake (3.0) ?? 9? 19 21:20:40 2013
######################################################################

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = sim-qt
INCLUDEPATH += .

DEFINES += QT_DLL
CONFIG  +=  console plugin link_pkgconfig

SOURCES += main.cpp\
                   main_window.cpp\
           main_window_file_slots.cpp\
           open_checkpoint_dialog.cpp\
           open_checkpoint_dialog_slots.cpp\
           create_workspace_dialog.cpp\
           create_workspace_dialog_slots.cpp\
           open_command_line_window_dialog.cpp\
           open_command_line_window_dialog_slots.cpp\
           sim_application.cpp

HEADERS += main_window.h\
           sim_application.h\
           open_checkpoint_dialog.h\
           open_command_line_window_dialog.h\
           create_workspace_dialog.h

FORMS += cli.ui main_window.ui open_checkpoint_dialog.ui create_workspace_dialog.ui

RESOURCES = icons.qrc
