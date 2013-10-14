#include <QStringList>
#include "open_checkpoint_dialog.h"
#include "ui_open_checkpoint_dialog.h"
#include <QListView>
#include <QDirModel>

// golbel object, bad idea.
QString WorkSpachPath = QObject::tr("/home/durd/simics");

OpenCheckpointDialog::OpenCheckpointDialog(QDialog *parent) :
    QDialog(parent),
    open_checkpoint_dialog_ui_(new Ui::OpenCheckpointDialog) {
    open_checkpoint_dialog_ui_->setupUi(this);
    showall = false;

    setWindowTitle(tr("Select checkpoint"));

    open_checkpoint_dialog_ui_->OpenButton->setEnabled(false);
    QDir rootDir(WorkSpachPath);

    initSelectDirectoryComboBox(rootDir);
    showFileInfoList(rootDir, showall);

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

void OpenCheckpointDialog::showFileInfoList(QDir dir, bool showall){
#if 0
    QStringList string;
    string << ((showall) ? "*" : "*.sim");
    QFileInfoList list=dir.entryInfoList (string,QDir::AllEntries | QDir::AllDirs,QDir::DirsFirst);

    open_checkpoint_dialog_ui_->CheckpointDirectoryListWidget->clear();

    for(unsigned int i = 0; i < list.count(); i++){
        QFileInfo temFileinfo = list.at(i);
        if(temFileinfo.isDir()){
            QIcon icon(":/images/dir.png");
            QString fileName = temFileinfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(icon, fileName);
            open_checkpoint_dialog_ui_->CheckpointDirectoryListWidget->addItem(tmp);
        }else{
            QIcon icon(":/images/file.png");
            QString fileName = temFileinfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(icon,fileName);
            open_checkpoint_dialog_ui_->CheckpointDirectoryListWidget->addItem(tmp);
        }
    }
#else
    QStringList string;
    string << ((showall) ? "*" : "*.sim");

    QDirModel *dirmodel = new QDirModel(string, QDir::AllEntries | QDir::AllDirs | QDir::Drives | QDir::NoDotAndDotDot, QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
    QModelIndex index = dirmodel->index(dir.absolutePath());

    open_checkpoint_dialog_ui_->CheckpointDirectoryListView->setModel(dirmodel);
    open_checkpoint_dialog_ui_->CheckpointDirectoryListView->scrollTo(index);
    open_checkpoint_dialog_ui_->CheckpointDirectoryListView->setRootIndex(index);
    open_checkpoint_dialog_ui_->OpenButton->setEnabled(false);
#endif

}
