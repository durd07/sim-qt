#include "main_window.h"
#include "qsim_console.h"
#include "open_command_line_window_dialog.h"
#include <QFileDialog>

void MainWindow::openCommandLineWindow(void)
{
    OpenCommandLineWindowDialog *command_line_window = new OpenCommandLineWindowDialog;
 //   command_line_window->setMinimumSize(640, 480);
    //Instantiate and set the focus to the QPyConsole
 //   QSimConsole *console = QSimConsole::getInstance(command_line_window);
 //   command_line_window->setFocusProxy((QWidget*)console);
  //  command_line_window->setCentralWidget((QWidget*)console);
    command_line_window->show();


    //QSimConsole::getInstance(MainWindow, tr("Welcome to simics!"));

}
