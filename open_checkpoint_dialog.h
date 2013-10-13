#ifndef OPEN_CHECKPOINT_DIALOG_H
#define OPEN_CHECKPOINT_DIALOG_H

#include <QWidget>
#include <QFileSystemModel>

class QFileSystemModel;
class QListWidgetItem;

namespace Ui {
    class OpenCheckpointDialog;
}

class OpenCheckpointDialog : public QWidget {
    Q_OBJECT

public:
    explicit OpenCheckpointDialog(QWidget *parent = 0);
    ~OpenCheckpointDialog();
private:
    void initSelectDirectoryComboBox(QDir dir);
    void showFileInfoList(QDir dir, bool showall);
private slots:
    void openCheckpoint(void);
    void appendFromCheckpoint(void);
    void slotShowDir(QListWidgetItem *item);
    void slotSelectDirectoryChanged(int index);
    void slotUPButton();
    void slotSimCheckpointComboBox(int index);
    void slotOpenEnable(QListWidgetItem * current, QListWidgetItem * previous);
    void slotOpen(void);
private:
    Ui::OpenCheckpointDialog *open_checkpoint_dialog_ui_;
    bool showall;
};

#endif
