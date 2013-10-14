#ifndef CREATE_WORKSPACE_DIALOG_H
#define CREATE_WORKSPACE_DIALOG_H

#include <QWidget>
#include <QFileSystemModel>

class QDirModel;

namespace Ui {
    class CreateWorkspaceDialog;
}

class CreateWorkspaceDialog : public QWidget {
    Q_OBJECT

public:
    explicit CreateWorkspaceDialog(QWidget *parent = 0);
    ~CreateWorkspaceDialog();
private slots:
    void createWorkspace(void);
    void changeWorkspace(void);
    void mkdir();
    void on_SureButton_clicked();
    void slotShowFilName(QModelIndex index);

private:
    QFileSystemModel *FileSysmodel;
    Ui::CreateWorkspaceDialog *create_workspace_dialog_ui_;
};

#endif
