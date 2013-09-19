#include "sim_application.h"

#include <QDesktopServices>
#include <QDir>
#include <QEvent>
#include <QFileOpenEvent>
#include <QFontMetrics>
#include <QTimer>
#include <QUrl>

SimApplication *simApp = NULL;

SimApplication::SimApplication(int &argc,  char **argv) :
    QApplication(argc, argv) {
    simApp = this;
}

