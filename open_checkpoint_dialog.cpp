#include <QStringList>
#include "open_checkpoint_dialog.h"
#include "ui_open_checkpoint_dialog.h"

OpenCheckpointDialog::OpenCheckpointDialog(QWidget *parent) :
    QWidget(parent),
    open_checkpoint_dialog_ui_(new Ui::OpenCheckpointDialog) {
    open_checkpoint_dialog_ui_->setupUi(this);

    initFilesystemModel();
    initCheckpointDirectoryTreeView(fsModel);
    initSelectDirectoryComboBox(fsModel);

    connect(open_checkpoint_dialog_ui_->CheckpointDirectoryTreeView, SIGNAL(clicked(QModelIndex)),
            this, SLOT(setComboRootIndex(QModelIndex)));

#if 0
    QStringList test = QStringList()
                       <<"Computer";
    open_checkpoint_dialog_ui_->SelectDirectoryComboBox->addItems(test);
#endif
}

OpenCheckpointDialog::~OpenCheckpointDialog() {
    delete open_checkpoint_dialog_ui_;
}

void OpenCheckpointDialog::initFilesystemModel(void) {
    fsModel = new QFileSystemModel;
    fsModel->setRootPath(QDir::currentPath());
}

void OpenCheckpointDialog::initCheckpointDirectoryTreeView(QFileSystemModel *fsm) {
    open_checkpoint_dialog_ui_->CheckpointDirectoryTreeView->setModel(fsm);
    open_checkpoint_dialog_ui_->CheckpointDirectoryTreeView->setHeaderHidden(true);
    for (int i = 1; i < 4; ++i) {       // fix me: have better idea?
        open_checkpoint_dialog_ui_->CheckpointDirectoryTreeView->hideColumn(i);
    }
}

void OpenCheckpointDialog::initSelectDirectoryComboBox(QFileSystemModel *fsm) {
    open_checkpoint_dialog_ui_->SelectDirectoryComboBox->setModel(fsm);
}
