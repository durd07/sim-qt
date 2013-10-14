#include <QMessageBox>
#include "open_checkpoint_dialog.h"
#include "ui_open_checkpoint_dialog.h"

void OpenCheckpointDialog::openCheckpoint(void) {
    this->exec();
}

void OpenCheckpointDialog::appendFromCheckpoint(void) {
    this->exec();
}

void OpenCheckpointDialog::slotShowDir(QModelIndex item){
    QString str = item.data().toString();
    QVariant ItemData = open_checkpoint_dialog_ui_->SelectDirectoryComboBox->itemData(open_checkpoint_dialog_ui_->SelectDirectoryComboBox->currentIndex());
    QString ItemString = ItemData.value<QString>();

    QDir dir(ItemString);

    if(dir.cd(str))
    {
        open_checkpoint_dialog_ui_->SelectDirectoryComboBox->insertItem(0, dir.dirName(), dir.absolutePath());
        open_checkpoint_dialog_ui_->SelectDirectoryComboBox->setCurrentIndex(0);
        showFileInfoList(dir);
    }
    else //file
    {
        QString FileObsolutePath = ItemString + "/" + str;
        QMessageBox::warning(this, "Message", FileObsolutePath, QMessageBox::Ok);
        close();
    }
}

void OpenCheckpointDialog::slotSelectDirectoryChanged(int index)
{
    QVariant ItemData = open_checkpoint_dialog_ui_->SelectDirectoryComboBox->itemData(index);
    QString ItemString = ItemData.value<QString>();

    initSelectDirectoryComboBox(ItemString);
    showFileInfoList(ItemString);
}

void OpenCheckpointDialog::slotUPButton()
{
    if(open_checkpoint_dialog_ui_->SelectDirectoryComboBox->count() > 1){
        slotSelectDirectoryChanged(open_checkpoint_dialog_ui_->SelectDirectoryComboBox->currentIndex() + 1);
    }else{
        slotSelectDirectoryChanged(open_checkpoint_dialog_ui_->SelectDirectoryComboBox->currentIndex());
    }
}

void OpenCheckpointDialog::slotSimCheckpointComboBox(int index)
{
    QStringList string;
    string << ((index) ? "*" : "*.sim");

    dirmodel->setNameFilters(string);

    QVariant ItemData = open_checkpoint_dialog_ui_->SelectDirectoryComboBox->itemData(open_checkpoint_dialog_ui_->SelectDirectoryComboBox->currentIndex());
    QString ItemString = ItemData.value<QString>();

    initSelectDirectoryComboBox(ItemString);

    showFileInfoList(ItemString);
}

void OpenCheckpointDialog::slotOpenEnable(QModelIndex)
{
    open_checkpoint_dialog_ui_->OpenButton->setEnabled(true);
}

void OpenCheckpointDialog::slotOpen()
{
    slotShowDir(open_checkpoint_dialog_ui_->CheckpointDirectoryListView->currentIndex());
}
