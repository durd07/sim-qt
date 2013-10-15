#include <QDirModel>
#include <QStandardPaths>
#include <QFileSystemModel>
#include <QModelIndex>
#include <QMessageBox>
#include "create_workspace_dialog.h"
#include "ui_create_workspace_dialog.h"

CreateWorkspaceDialog::CreateWorkspaceDialog(QWidget *parent) :
    QWidget(parent),
    create_workspace_dialog_ui_(new Ui::CreateWorkspaceDialog) {
    create_workspace_dialog_ui_->setupUi(this);
#if 1
//    QDirModel *dirmodel = new QDirModel(this);

//    QString home_files = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
//    QModelIndex homeIndex = dirmodel->index(home_files);
//    QString desktop_path = QStandardPaths::storageLocation(QStandardPaths::DesktopLocation);
//    QString document_path = QStandardPaths::storageLocation(QStandardPaths::DocumentsLocation);
//    QString home_path = QStandardPaths::storageLocation(QStandardPaths::HomeLocation);
//    QString application_path = QStandardPaths::storageLocatio(QStandardPaths::ApplicationsLocation);
//    QString temp_path = QStandardPaths::storageLocation(QStandardPaths::TempLocation);

    FileSysmodel = new QFileSystemModel;
    QModelIndex modelIndex = FileSysmodel->setRootPath(FileSysmodel->myComputer().value<QString>());
    create_workspace_dialog_ui_->DirecotoryTreeView->setModel(FileSysmodel);
    create_workspace_dialog_ui_->DirecotoryTreeView->setRootIndex(modelIndex);
    create_workspace_dialog_ui_->DirecotoryTreeView->setHeaderHidden(true);
//    create_workspace_dialog_ui_->DirecotoryTreeView->expand(modelIndex);      //当前项展开
//    create_workspace_dialog_ui_->DirecotoryTreeView->scrollTo(modelIndex);    //定位到当前项
    create_workspace_dialog_ui_->DirecotoryTreeView->setRootIsDecorated(false);
//    create_workspace_dialog_ui_->DirecotoryTreeView->setEditTriggers(QAbstractItemView::CurrentChanged | QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked | QAbstractItemView::AnyKeyPressed);
    //create_workspace_dialog_ui_->DirecotoryTreeView->sete
    for(int i = 1; i < 4; i++)
    {
        create_workspace_dialog_ui_->DirecotoryTreeView->hideColumn(i);
    }
#endif
    connect(create_workspace_dialog_ui_->CreateDirectoryButton, SIGNAL(clicked()), this , SLOT(mkdir()));
    connect(create_workspace_dialog_ui_->DirecotoryTreeView, SIGNAL(clicked(QModelIndex)), this , SLOT(slotShowFilName(QModelIndex)));
}
CreateWorkspaceDialog::~CreateWorkspaceDialog() {
    delete create_workspace_dialog_ui_;
    delete FileSysmodel;
}


