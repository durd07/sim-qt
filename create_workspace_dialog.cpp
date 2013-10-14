#include <QDirModel>
#include <QStandardPaths>
#include <QFileSystemModel>
#include <QModelIndex>
#include "create_workspace_dialog.h"
#include "ui_create_workspace_dialog.h"

CreateWorkspaceDialog::CreateWorkspaceDialog(QWidget *parent) :
    QWidget(parent),
    create_workspace_dialog_ui_(new Ui::CreateWorkspaceDialog) {
    create_workspace_dialog_ui_->setupUi(this);
#if 1
    QDirModel *dirmodel = new QDirModel(this);

    QString home_files = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QModelIndex homeIndex = dirmodel->index(home_files);
//    QString desktop_path = QStandardPaths::storageLocation(QStandardPaths::DesktopLocation);
//    QString document_path = QStandardPaths::storageLocation(QStandardPaths::DocumentsLocation);
//    QString home_path = QStandardPaths::storageLocation(QStandardPaths::HomeLocation);
//    QString application_path = QStandardPaths::storageLocatio(QStandardPaths::ApplicationsLocation);
//    QString temp_path = QStandardPaths::storageLocation(QStandardPaths::TempLocation);

    QFileSystemModel *model = new QFileSystemModel;
    QModelIndex modelIndex = model->setRootPath(model->myComputer().value<QString>());
//    QModelIndex modelIndex = model->setRootPath(home_files);
    create_workspace_dialog_ui_->DirecotoryTreeView->setModel(model);
    create_workspace_dialog_ui_->DirecotoryTreeView->setRootIndex(modelIndex);
//    create_workspace_dialog_ui_->DirecotoryTreeView->setRootIndex(model->index(home_files));
#endif
    connect(create_workspace_dialog_ui_->CreateDirectoryButton, SIGNAL(clicked()), this , SLOT(mkdir());
}

CreateWorkspaceDialog::~CreateWorkspaceDialog() {
    delete create_workspace_dialog_ui_;
}

void CreateWorkspaceDialog::on_SureButton_clicked()
{
    QString FileObsolutePath = ItemString + "/" + str;
    QMessageBox::warning(this, "Message", FileObsolutePath, QMessageBox::Ok);
}
