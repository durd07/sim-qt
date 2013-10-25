#include "create_workspace_dialog.h"
#include "ui_create_workspace_dialog.h"
#include <QMessageBox>

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

    FileSysmodel->mkdir(index, newdirname);
    QModelIndex new_index = FileSysmodel->index(newdirname);

    if (!new_index.isValid()){
        QMessageBox::information(this,"Create Directory","Failed to create the directory");
    }

    create_workspace_dialog_ui_->DirecotoryTreeView->setCurrentIndex(new_index);
}

void CreateWorkspaceDialog::slotShowFilName(QModelIndex index)
{
    create_workspace_dialog_ui_->DirecotoryTreeView->expand(index);
    create_workspace_dialog_ui_->FilenameLineEdit->setText(FileSysmodel->fileName(index));
}

void CreateWorkspaceDialog::on_SureButton_clicked()
{
    QString FileObsolutePath = "ItemString + + str";
    QMessageBox::warning(this, "Message", FileObsolutePath, QMessageBox::Ok);
}
