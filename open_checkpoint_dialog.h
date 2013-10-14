#ifndef OPEN_CHECKPOINT_DIALOG_H
#define OPEN_CHECKPOINT_DIALOG_H

#include <QWidget>
#include <QDialog>
#include <QFileSystemModel>

class QFileSystemModel;

namespace Ui {
    class OpenCheckpointDialog;
}

class OpenCheckpointDialog : public QDialog {
    Q_OBJECT

public:
    explicit OpenCheckpointDialog(QDialog *parent = 0);
    ~OpenCheckpointDialog();
private:
    void initSelectDirectoryComboBox(QDir dir);
    void showFileInfoList(QDir dir, bool showall);
private slots:
    void openCheckpoint(void);
    void appendFromCheckpoint(void);
    void slotShowDir(QModelIndex item);
    void slotSelectDirectoryChanged(int index);
    void slotUPButton();
    void slotSimCheckpointComboBox(int index);
    void slotOpenEnable(QModelIndex);
    void slotOpen(void);
private:
    Ui::OpenCheckpointDialog *open_checkpoint_dialog_ui_;
    bool showall;
};

#endif
