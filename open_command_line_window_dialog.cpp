#include "open_command_line_window_dialog.h"
#include "qsim_console.h"
#include <QVBoxLayout>

OpenCommandLineWindowDialog::OpenCommandLineWindowDialog(QWidget *parent) :
    QWidget(parent){
    QSimConsole *console = QSimConsole::getInstance(this);
    this->setFocusProxy((QWidget*)console);
    this->setMinimumSize(640, 480);
    this->setWindowTitle(tr("Simics Command Line"));

    layout = new QVBoxLayout;
    layout->addWidget(console);
    this->setLayout(layout);

}

OpenCommandLineWindowDialog::~OpenCommandLineWindowDialog() {
}

