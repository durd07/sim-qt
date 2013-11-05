#include "main_window.h"
#include "qsim_console.h"
#include "open_command_line_window_dialog.h"
#include <QFileDialog>

void MainWindow::openCommandLineWindow(void)
{
    OpenCommandLineWindowDialog *command_line_window = new OpenCommandLineWindowDialog;
    command_line_window->show();
}
