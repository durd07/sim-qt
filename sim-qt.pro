######################################################################
# Automatically generated by qmake (3.0) ?? 9? 19 21:20:40 2013
######################################################################

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
TARGET = simqt
INCLUDEPATH += .

DEFINES += QT_DLL
CONFIG  += plugin link_pkgconfig
#CONFIG   += staticlib
SOURCES += main.cpp\
	main_window.cpp\
        main_window_file_slots.cpp\
        open_checkpoint_dialog.cpp\
        open_checkpoint_dialog_slots.cpp\
        create_workspace_dialog.cpp\
        create_workspace_dialog_slots.cpp\
        open_command_line_window_dialog.cpp\
        open_command_line_window_dialog_slots.cpp\
        sim_application.cpp \
	qconsole.cpp \
	qsim_console.cpp \
	main_window_tool_slots.cpp \
    tsh_if.c

HEADERS += main_window.h\
	sim_application.h\
        open_checkpoint_dialog.h\
        open_command_line_window_dialog.h\
        create_workspace_dialog.h \
    	qconsole.h \
    	qsim_console.h \
    	tsh_if.h

FORMS += main_window.ui open_checkpoint_dialog.ui create_workspace_dialog.ui

RESOURCES = icons.qrc
