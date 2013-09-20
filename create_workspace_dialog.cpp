#include "create_workspace_dialog.h"
#include "ui_create_workspace_dialog.h"

CreateWorkspaceDialog::CreateWorkspaceDialog(QWidget *parent) :
    QWidget(parent),
    create_workspace_dialog_ui_(new Ui::CreateWorkspaceDialog) {
    create_workspace_dialog_ui_->setupUi(this);
}

CreateWorkspaceDialog::~CreateWorkspaceDialog() {
    delete create_workspace_dialog_ui_;
}
