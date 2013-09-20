#ifndef CREATE_WORKSPACE_DIALOG_H
#define CREATE_WORKSPACE_DIALOG_H

#include <QWidget>

namespace Ui {
    class CreateWorkspaceDialog;
}

class CreateWorkspaceDialog : public QWidget {
    Q_OBJECT

public:
    explicit CreateWorkspaceDialog(QWidget *parent = 0);
    ~CreateWorkspaceDialog();
private:
    Ui::CreateWorkspaceDialog *create_workspace_dialog_ui_;
};

#endif
