#ifndef OPEN_CHECKPOINT_DIALOG_H
#define OPEN_CHECKPOINT_DIALOG_H

#include <QWidget>
#include <QFileSystemModel>

class QFileSystemModel;

namespace Ui {
    class OpenCheckpointDialog;
}

class OpenCheckpointDialog : public QWidget {
    Q_OBJECT

public:
    explicit OpenCheckpointDialog(QWidget *parent = 0);
    ~OpenCheckpointDialog();
private:
    void initFilesystemModel(void);
    void initCheckpointDirectoryTreeView(QFileSystemModel *fsm);
    void initSelectDirectoryComboBox(QFileSystemModel *fsm);

private slots:
    void openCheckpoint(void);
    void appendFromCheckpoint(void);
    void setComboRootIndex(const QModelIndex &index);
private:
    Ui::OpenCheckpointDialog *open_checkpoint_dialog_ui_;
    QFileSystemModel *fsModel;
};

#endif
