#ifndef OPEN_COMMAND_WINDOW_DIALOG_H
#define OPEN_COMMAND_WINDOW_DIALOG_H

#include <QWidget>

class QVBoxLayout;

class OpenCommandLineWindowDialog : public QWidget {
    Q_OBJECT

public:
    explicit OpenCommandLineWindowDialog(QWidget *parent = 0);
    ~OpenCommandLineWindowDialog();

private:
    QVBoxLayout *layout;
};

#endif
