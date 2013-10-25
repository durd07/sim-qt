#include <QStandardPaths>
#include <QModelIndex>
#include <QMessageBox>
#include "create_workspace_dialog.h"
#include "ui_create_workspace_dialog.h"

CreateWorkspaceDialog::CreateWorkspaceDialog(QString dialog_info, QDialog *parent) :
    QDialog(parent),
    create_workspace_dialog_ui_(new Ui::CreateWorkspaceDialog) {
    create_workspace_dialog_ui_->setupUi(this);
    create_workspace_dialog_ui_->DialogInfoLabel->setText(dialog_info);

    FileSysmodel = new QFileSystemModel;
    FileSysmodel->setReadOnly(false);
    FileSysmodel->setFilter(QDir::AllDirs | QDir::AllEntries | QDir::Drives | QDir::NoDotAndDotDot);

    QModelIndex modelIndex = FileSysmodel->setRootPath(FileSysmodel->myComputer().value<QString>());
    create_workspace_dialog_ui_->DirecotoryTreeView->setModel(FileSysmodel);
    create_workspace_dialog_ui_->DirecotoryTreeView->setRootIndex(modelIndex);
    create_workspace_dialog_ui_->DirecotoryTreeView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked | QAbstractItemView::EditKeyPressed/* | QAbstractItemView::AnyKeyPressed*/);
    create_workspace_dialog_ui_->DirecotoryTreeView->setHeaderHidden(true);

    for(int i = 1; i < 4; i++)
    {
        create_workspace_dialog_ui_->DirecotoryTreeView->hideColumn(i);
    }

    connect(create_workspace_dialog_ui_->CreateDirectoryButton, SIGNAL(clicked()), this , SLOT(mkdir()));
    connect(create_workspace_dialog_ui_->DirecotoryTreeView, SIGNAL(clicked(QModelIndex)), this , SLOT(slotShowFilName(QModelIndex)));
}
CreateWorkspaceDialog::~CreateWorkspaceDialog() {
    delete create_workspace_dialog_ui_;
    delete FileSysmodel;
}


