#ifndef OPEN_CHECKPOINT_DIALOG_H
#define OPEN_CHECKPOINT_DIALOG_H

#include <QWidget>

namespace Ui {
    class OpenCheckpointDialog;
}

class OpenCheckpointDialog : public QWidget {
    Q_OBJECT

public:
    explicit OpenCheckpointDialog(QWidget *parent = 0);
    ~OpenCheckpointDialog();
private slots:
    void openCheckpoint(void);
    void appendFromCheckpoint(void);
private:
    Ui::OpenCheckpointDialog *open_checkpoint_dialog_ui_;

};

#endif
