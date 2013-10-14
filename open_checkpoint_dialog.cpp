#include <QStringList>
#include <QListView>
#include "open_checkpoint_dialog.h"
#include "ui_open_checkpoint_dialog.h"

// golbel object, bad idea.
QString WorkSpachPath = QObject::tr("/home/durd/simics");

OpenCheckpointDialog::OpenCheckpointDialog(QDialog *parent) :
    QDialog(parent),
    open_checkpoint_dialog_ui_(new Ui::OpenCheckpointDialog) {
    open_checkpoint_dialog_ui_->setupUi(this);

    QStringList string;
    string << "*.sim";
    dirmodel = new QDirModel(string, QDir::AllEntries | QDir::AllDirs | QDir::Drives | QDir::NoDotAndDotDot, QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
    open_checkpoint_dialog_ui_->CheckpointDirectoryListView->setModel(dirmodel);

    QDir rootDir(WorkSpachPath);
    initSelectDirectoryComboBox(rootDir);
    showFileInfoList(rootDir);

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
    delete dirmodel;
}

void OpenCheckpointDialog::initSelectDirectoryComboBox(QDir dir)
{
    QDir tempDir = dir;
    open_checkpoint_dialog_ui_->SelectDirectoryComboBox->clear();
    int i = 0;

    if("" == tempDir.dirName()){
        open_checkpoint_dialog_ui_->SelectDirectoryComboBox->insertItem(i, tr("Computer"), tempDir.absolutePath());
    }else{
        open_checkpoint_dialog_ui_->SelectDirectoryComboBox->insertItem(i, tempDir.dirName(), tempDir.absolutePath());
    }

    while(tempDir.cdUp()){
        i++;
        QString FatherPath = tempDir.path();
        QString FatherPathAbsolute = tempDir.absoluteFilePath(FatherPath);
        QString FatherDirName = tempDir.dirName();
        QVariant data(FatherPathAbsolute);
        if(tr("") == FatherDirName){
            FatherDirName = tr("Computer");
        }
        open_checkpoint_dialog_ui_->SelectDirectoryComboBox->insertItem(i, FatherDirName, data);
        i++;
    }
}

void OpenCheckpointDialog::showFileInfoList(QDir dir){
    QModelIndex index = dirmodel->index(dir.absolutePath());
    open_checkpoint_dialog_ui_->CheckpointDirectoryListView->setRootIndex(index);
    open_checkpoint_dialog_ui_->OpenButton->setEnabled(false);
}
