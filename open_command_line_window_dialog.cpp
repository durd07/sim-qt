#include "open_command_line_window_dialog.h"
#include "qsim_console.h"
#include <QVBoxLayout>

OpenCommandLineWindowDialog::OpenCommandLineWindowDialog(QWidget *parent) :
    QWidget(parent) {
    console = QSimConsole::getInstance(this);
    this->setFocusProxy((QWidget*)console);
    this->setMinimumSize(640, 480);
    this->setWindowTitle(tr("Simics Command Line"));
    this->setAttribute(Qt::WA_QuitOnClose, false);

    layout = new QVBoxLayout;
    layout->addWidget(console);
    this->setLayout(layout);
}

OpenCommandLineWindowDialog::~OpenCommandLineWindowDialog() {
    delete console;
    delete layout;
}

