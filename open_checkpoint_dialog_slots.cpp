#include <QMessageBox>
#include "open_checkpoint_dialog.h"
#include "ui_open_checkpoint_dialog.h"

void OpenCheckpointDialog::openCheckpoint(void) {
    this->exec();
}

void OpenCheckpointDialog::appendFromCheckpoint(void) {
    this->exec();
}

void OpenCheckpointDialog::slotShowDir(QModelIndex index){
    if(FileSysmodel->isDir(index))
    {
        open_checkpoint_dialog_ui_->SelectDirectoryComboBox->insertItem(0, FileSysmodel->fileName(index), FileSysmodel->filePath(index));
        open_checkpoint_dialog_ui_->SelectDirectoryComboBox->setCurrentIndex(0);
        showFileInfoList(index);
    }
    else //file
    {
        QString FileObsolutePath = FileSysmodel->filePath(index);
        QMessageBox::warning(this, "Message", FileObsolutePath, QMessageBox::Ok);
        close();
    }
}

void OpenCheckpointDialog::slotSelectDirectoryChanged(int index)
{
    QVariant ItemData = open_checkpoint_dialog_ui_->SelectDirectoryComboBox->itemData(index);
    QString ItemString = ItemData.value<QString>();

    initSelectDirectoryComboBox(FileSysmodel->index(ItemString));
    showFileInfoList(FileSysmodel->index(ItemString));
}

void OpenCheckpointDialog::slotUPButton()
{
    if(open_checkpoint_dialog_ui_->SelectDirectoryComboBox->count() > 1){
        slotSelectDirectoryChanged(open_checkpoint_dialog_ui_->SelectDirectoryComboBox->currentIndex() + 1);
    }else{
        //slotSelectDirectoryChanged(open_checkpoint_dialog_ui_->SelectDirectoryComboBox->currentIndex());
    }
}

void OpenCheckpointDialog::slotSimCheckpointComboBox(int index)
{
    QStringList string;
    string << ((index) ? "*" : "*.sim");

    FileSysmodel->setNameFilters(string);

    QVariant ItemData = open_checkpoint_dialog_ui_->SelectDirectoryComboBox->itemData(open_checkpoint_dialog_ui_->SelectDirectoryComboBox->currentIndex());
    QString ItemString = ItemData.value<QString>();

    //initSelectDirectoryComboBox(FileSysmodel->index(ItemString));

    showFileInfoList(FileSysmodel->index(ItemString));
}

void OpenCheckpointDialog::slotOpenEnable(QModelIndex)
{
    open_checkpoint_dialog_ui_->OpenButton->setEnabled(true);
}

void OpenCheckpointDialog::slotOpen()
{
    slotShowDir(open_checkpoint_dialog_ui_->CheckpointDirectoryListView->currentIndex());
}
