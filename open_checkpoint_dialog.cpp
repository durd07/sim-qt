#include "open_checkpoint_dialog.h"
#include "ui_open_checkpoint_dialog.h"

OpenCheckpointDialog::OpenCheckpointDialog(QWidget *parent) :
    QWidget(parent),
    open_checkpoint_dialog_ui_(new Ui::OpenCheckpointDialog) {
    open_checkpoint_dialog_ui_->setupUi(this);
}

OpenCheckpointDialog::~OpenCheckpointDialog() {
    delete open_checkpoint_dialog_ui_;
}
