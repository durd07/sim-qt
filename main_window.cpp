#include "main_window.h"
#include "ui_main_window.h"

static MainWindow *gbl_cur_main_window = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    main_ui_(new Ui::MainWindow) {
    gbl_cur_main_window = this;
    main_ui_->setupUi(this);

    connect(main_ui_->actionNewEmptySession, SIGNAL(triggered()), this, SLOT(newEmptySession()));
    connect(main_ui_->actionNewSessionFromScript, SIGNAL(triggered()), this, SLOT(newSessionFromScript()));
    connect(main_ui_->actionOpenCheckpoint, SIGNAL(triggered()), this, SLOT(openCheckpoint()));
    connect(main_ui_->actionAppendFromScript, SIGNAL(triggered()), this, SLOT(appendFromScript()));
    connect(main_ui_->actionAppendFromCheckpoint, SIGNAL(triggered()), this, SLOT(appendFromCheckpoint()));
    connect(main_ui_->actionRunPythonFile, SIGNAL(triggered()), this, SLOT(runPythonFile()));
}





MainWindow::~MainWindow()
{
    delete main_ui_;
}
