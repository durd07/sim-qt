#ifndef CREATE_WORKSPACE_DIALOG_H
#define CREATE_WORKSPACE_DIALOG_H

#include <QDialog>
#include <QFileSystemModel>

namespace Ui {
    class CreateWorkspaceDialog;
}

class CreateWorkspaceDialog : public QDialog {
    Q_OBJECT

public:
    explicit CreateWorkspaceDialog(QString dialog_info = tr("Select directory to use as workspace ..."), QDialog *parent = 0);
    ~CreateWorkspaceDialog();

private slots:
    void mkdir();
    void on_SureButton_clicked();
    void slotShowFilName(QModelIndex index);

private:
    QFileSystemModel *FileSysmodel;
    Ui::CreateWorkspaceDialog *create_workspace_dialog_ui_;
};

#endif
