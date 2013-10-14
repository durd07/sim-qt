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

void CreateWorkspaceDialog::mkdir()
{
    QModelIndex index = create_workspace_dialog_ui_->DirecotoryTreeView->currentIndex();
    if (!index.isValid())
    {
        return;
    }

    QString dirName = create_workspace_dialog_ui_->FilenameLineEdit->text();
    if (!dirName.isEmpty())
    {
        if (!model->mkdir(index, dirName).isValid())
        {
            QMessageBox::information(this,"Create Directory","Failed to create the directory");
        }
    }
}
