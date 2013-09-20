#include "create_workspace_dialog.h"
#include "ui_create_workspace_dialog.h"

void CreateWorkspaceDialog::createWorkspace(void) {
    this->create_workspace_dialog_ui_
        ->DialogInfoLabel->setText(QApplication::translate("CreateWorkspaceDialog",
                                                           "Select directory to use as workspace ...", 0));
    this->show();
}

void CreateWorkspaceDialog::changeWorkspace(void) {
    this->create_workspace_dialog_ui_
        ->DialogInfoLabel->setText(QApplication::translate("CreateWorkspaceDialog",
                                                           "Select workspace to use ...", 0));
    this->show();
}
