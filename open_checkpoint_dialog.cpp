#include <QStringList>
#include <QListView>
#include "open_checkpoint_dialog.h"
#include "ui_open_checkpoint_dialog.h"

// golbel object, bad idea.
QString WorkSpachPath;

OpenCheckpointDialog::OpenCheckpointDialog(QDialog *parent) :
    QDialog(parent),
    open_checkpoint_dialog_ui_(new Ui::OpenCheckpointDialog) {
    open_checkpoint_dialog_ui_->setupUi(this);

    FileSysmodel = new QFileSystemModel();
    FileSysmodel->setFilter(QDir::AllDirs | QDir::AllEntries | QDir::Drives | QDir::NoDotAndDotDot);
    FileSysmodel->sort(0);
    //WorkSpachPath = FileSysmodel->myComputer().value<QString>();
    WorkSpachPath = "C:\\Users\\XHYZ\\Desktop";

    QModelIndex modelIndex = FileSysmodel->setRootPath(WorkSpachPath);
    open_checkpoint_dialog_ui_->CheckpointDirectoryListView->setModel(FileSysmodel);
    open_checkpoint_dialog_ui_->CheckpointDirectoryListView->setRootIndex(modelIndex);

    initSelectDirectoryComboBox(modelIndex);

    connect(open_checkpoint_dialog_ui_->CheckpointDirectoryListView,SIGNAL(doubleClicked(QModelIndex )),this,SLOT(slotShowDir(QModelIndex )));
    connect(open_checkpoint_dialog_ui_->CheckpointDirectoryListView,SIGNAL(clicked(QModelIndex)),this,SLOT(slotOpenEnable(QModelIndex)));
    connect(open_checkpoint_dialog_ui_->SelectDirectoryComboBox, SIGNAL(activated(int)), this, SLOT(slotSelectDirectoryChanged(int)));
    connect(open_checkpoint_dialog_ui_->UpButton, SIGNAL(clicked()), this, SLOT(slotUPButton()));
    connect(open_checkpoint_dialog_ui_->SimCheckpointComboBox, SIGNAL(activated(int)), this, SLOT(slotSimCheckpointComboBox(int)));
    connect(open_checkpoint_dialog_ui_->OpenButton, SIGNAL(clicked()), this, SLOT(slotOpen()));
    connect(open_checkpoint_dialog_ui_->CancelButton, SIGNAL(clicked()), this, SLOT(close()));
}

OpenCheckpointDialog::~OpenCheckpointDialog() {
    delete open_checkpoint_dialog_ui_;
    delete FileSysmodel;
}

void OpenCheckpointDialog::initSelectDirectoryComboBox(QModelIndex index)
{
    open_checkpoint_dialog_ui_->SelectDirectoryComboBox->clear();

    int i = 0;
    QModelIndex tempindex = index;
    while(!FileSysmodel->fileName(FileSysmodel->parent(tempindex)).isEmpty()){
        open_checkpoint_dialog_ui_->SelectDirectoryComboBox->insertItem(i, FileSysmodel->fileName(tempindex), FileSysmodel->filePath(tempindex));
        tempindex = FileSysmodel->parent(tempindex);
        i++;
    }
    open_checkpoint_dialog_ui_->SelectDirectoryComboBox->insertItem(i, "Compter", "My\ Computer");
}

void OpenCheckpointDialog::showFileInfoList(QModelIndex index){
    open_checkpoint_dialog_ui_->CheckpointDirectoryListView->setRootIndex(index);
    open_checkpoint_dialog_ui_->OpenButton->setEnabled(false);
}
