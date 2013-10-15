#ifndef OPEN_CHECKPOINT_DIALOG_H
#define OPEN_CHECKPOINT_DIALOG_H

#include <QDialog>
#include <QDirModel>
#include <QFileSystemModel>

#define _USE_DIRMODEL
namespace Ui {
    class OpenCheckpointDialog;
}

class OpenCheckpointDialog : public QDialog {
    Q_OBJECT

public:
    explicit OpenCheckpointDialog(QDialog *parent = 0);
    ~OpenCheckpointDialog();
private:
    void initSelectDirectoryComboBox(QModelIndex index);
    void showFileInfoList(QModelIndex index);
private slots:
    void openCheckpoint(void);
    void appendFromCheckpoint(void);
    void slotShowDir(QModelIndex index);
    void slotSelectDirectoryChanged(int index);
    void slotUPButton();
    void slotSimCheckpointComboBox(int index);
    void slotOpenEnable(QModelIndex);
    void slotOpen(void);
private:
    Ui::OpenCheckpointDialog *open_checkpoint_dialog_ui_;
#ifdef _USE_DIRMODEL
    QDirModel *FileSysmodel;
#else
    QFileSystemModel *FileSysmodel;
#endif
};

#endif
