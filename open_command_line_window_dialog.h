#ifndef OPEN_COMMAND_WINDOW_DIALOG_H
#define OPEN_COMMAND_WINDOW_DIALOG_H

#include <QWidget>
#include <QVBoxLayout>
#include "qsim_console.h"

class OpenCommandLineWindowDialog : public QWidget {
    Q_OBJECT
public:
    explicit OpenCommandLineWindowDialog(QWidget *parent = 0);
    ~OpenCommandLineWindowDialog();

private:
    QVBoxLayout *layout;
    QSimConsole *console;
};

#endif
