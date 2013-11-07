#include "main_window.h"
#include "qsim_console.h"
#include <QFileDialog>

void MainWindow::openCommandLineWindow(void)
{
    if(NULL == command_line_window) {
    command_line_window = new OpenCommandLineWindowDialog;
    }
    command_line_window->show();
}
