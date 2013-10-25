#include <QStringList>
#include <QListView>
#include "open_checkpoint_dialog.h"
#include "ui_open_checkpoint_dialog.h"

// golbel object, bad idea.
QString WorkSpachPath = QObject::tr("C:\\Users");

OpenCheckpointDialog::OpenCheckpointDialog(QDialog *parent) :
    QDialog(parent),
    open_checkpoint_dialog_ui_(new Ui::OpenCheckpointDialog) {
    open_checkpoint_dialog_ui_->setupUi(this);

#ifdef _USE_DIRMODEL
    FileSysmodel = new QDirModel();
    FileSysmodel->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
#else
    FileSysmodel = new QFileSystemModel();
    FileSysmodel->sort(0);
#endif
    FileSysmodel->setFilter(QDir::AllDirs | QDir::AllEntries | QDir::Drives | QDir::NoDotAndDotDot);
    FileSysmodel->setNameFilters(QStringList(QString("*.xml")));

#ifdef _USE_DIRMODEL
    QModelIndex modelIndex = FileSysmodel->index(WorkSpachPath);
#else
    QModelIndex modelIndex = FileSysmodel->setRootPath(WorkSpachPath);
#endif
    open_checkpoint_dialog_ui_->CheckpointDirectoryListView->setModel(FileSysmodel);

    initSelectDirectoryComboBox(modelIndex);
    showFileInfoList(modelIndex);

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
    while(!FileSysmodel->fileName(tempindex).isEmpty()){
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
