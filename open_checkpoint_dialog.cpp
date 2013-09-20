#include "open_checkpoint_dialog.h"
#include "ui_open_checkpoint_dialog.h"
#include <QStringList>
#include <QFileSystemModel>

OpenCheckpointDialog::OpenCheckpointDialog(QWidget *parent) :
    QWidget(parent),
    open_checkpoint_dialog_ui_(new Ui::OpenCheckpointDialog) {
    open_checkpoint_dialog_ui_->setupUi(this);

    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());

    open_checkpoint_dialog_ui_->CheckpointDirectoryTreeView->setModel(model);
    open_checkpoint_dialog_ui_->CheckpointDirectoryTreeView->setHeaderHidden(true);
    for (int i = 1; i < 4; ++i) {       // fix me: have better idea?
        open_checkpoint_dialog_ui_->CheckpointDirectoryTreeView->hideColumn(i);
    }

#if 0
    QStringList test = QStringList()
                       <<"Computer";
    open_checkpoint_dialog_ui_->SelectDirectoryComboBox->addItems(test);
#endif
}

OpenCheckpointDialog::~OpenCheckpointDialog() {
    delete open_checkpoint_dialog_ui_;
}
