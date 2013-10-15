#include "create_workspace_dialog.h"
#include "ui_create_workspace_dialog.h"
#include <QMessageBox>

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
    if (!index.isValid()){
        return;
    }

    int i = 2;
    QString dirName = tr("New\ Folder");
    QString newdirname = FileSysmodel->filePath(index) + "/" + dirName;

    while(FileSysmodel->index(newdirname).isValid()){
        dirName = tr("New\ Folder") + "(" + QString::number(i) + ")";
        newdirname = FileSysmodel->filePath(index) + "/" + dirName;
        i++;
    }

    QModelIndex new_index = FileSysmodel->mkdir(index, newdirname);
    if (!new_index.isValid()){
        QMessageBox::information(this,"Create Directory","Failed to create the directory");
    }
    create_workspace_dialog_ui_->DirecotoryTreeView->visualRect(new_index);

    //create_workspace_dialog_ui_->DirecotoryTreeView->scrollTo(new_index);    //定位到当前项
}

void CreateWorkspaceDialog::slotShowFilName(QModelIndex index)
{
    create_workspace_dialog_ui_->DirecotoryTreeView->expand(index);      //当前项展开
    create_workspace_dialog_ui_->DirecotoryTreeView->scrollTo(index);    //定位到当前项
    create_workspace_dialog_ui_->FilenameLineEdit->setText(FileSysmodel->fileName(index));
}

void CreateWorkspaceDialog::on_SureButton_clicked()
{
    QString FileObsolutePath = "ItemString + + str";
    QMessageBox::warning(this, "Message", FileObsolutePath, QMessageBox::Ok);
}
