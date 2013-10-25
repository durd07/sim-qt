#ifndef OPEN_COMMAND_WINDOW_DIALOG_H
#define OPEN_COMMAND_WINDOW_DIALOG_H

#include <QWidget>

namespace Ui {
    class OpenCommandLineWindowDialog;
}

class OpenCommandLineWindowDialog : public QWidget {
    Q_OBJECT

public:
    explicit OpenCommandLineWindowDialog(QWidget *parent = 0);
    ~OpenCommandLineWindowDialog();

private slots:
    void openCommandLineWindow(void);

private:
    Ui::OpenCommandLineWindowDialog *open_command_line_window_dialog_ui_;
};

#endif
