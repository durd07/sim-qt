#include "open_checkpoint_dialog.h"
#include "ui_open_checkpoint_dialog.h"
#include <QFileInfo>
#include <QMessageBox>

void OpenCheckpointDialog::openCheckpoint(void) {
    this->show();
}

void OpenCheckpointDialog::appendFromCheckpoint(void) {
    this->show();
}

void OpenCheckpointDialog::slotShowDir(QListWidgetItem *item){
        QString str=item->text();
        QVariant ItemData = open_checkpoint_dialog_ui_->SelectDirectoryComboBox->itemData(open_checkpoint_dialog_ui_->SelectDirectoryComboBox->currentIndex());
        QString ItemString = ItemData.value<QString>();

        QDir dir(ItemString);

        if(dir.cd(str))
        {
            open_checkpoint_dialog_ui_->SelectDirectoryComboBox->insertItem(0, dir.dirName(), dir.absolutePath());
            open_checkpoint_dialog_ui_->SelectDirectoryComboBox->setCurrentIndex(0);
        }
        else //file
        {
            QString FileObsolutePath = ItemString + "/" + str;
            QMessageBox::warning(this, "Message", FileObsolutePath, QMessageBox::Ok);
        }
        showFileInfoList(dir, showall);
}

void OpenCheckpointDialog::slotSelectDirectoryChanged(int index)
{
    QVariant ItemData = open_checkpoint_dialog_ui_->SelectDirectoryComboBox->itemData(index);
    QString ItemString = ItemData.value<QString>();

    initSelectDirectoryComboBox(ItemString);
    showFileInfoList(ItemString, showall);
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
    showall = index ? true : false;
    QVariant ItemData = open_checkpoint_dialog_ui_->SelectDirectoryComboBox->itemData(open_checkpoint_dialog_ui_->SelectDirectoryComboBox->currentIndex());
    QString ItemString = ItemData.value<QString>();

    initSelectDirectoryComboBox(ItemString);

    showFileInfoList(ItemString, showall);
}

void OpenCheckpointDialog::slotOpenEnable(QListWidgetItem * current, QListWidgetItem * previous)
{
    open_checkpoint_dialog_ui_->OpenButton->setEnabled(true);
}

void OpenCheckpointDialog::slotOpen()
{
    slotShowDir(open_checkpoint_dialog_ui_->CheckpointDirectoryListWidget->currentItem());
}
