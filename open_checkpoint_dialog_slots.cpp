#include "open_checkpoint_dialog.h"
#include "ui_open_checkpoint_dialog.h"
#include <cstdio>

void OpenCheckpointDialog::openCheckpoint(void) {
    this->show();
}

void OpenCheckpointDialog::appendFromCheckpoint(void) {
    this->show();
}

void OpenCheckpointDialog::setComboRootIndex(const QModelIndex &index) {
    if(fsModel->canFetchMore(index)) {
        fsModel->fetchMore(index);
    }

    open_checkpoint_dialog_ui_
        ->SelectDirectoryComboBox
        ->setRootModelIndex(index);
}
