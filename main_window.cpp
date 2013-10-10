#include "main_window.h"
#include "ui_main_window.h"
#include "sim_application.h"
#include <QLabel>

static MainWindow *gbl_cur_main_window = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    main_ui_(new Ui::MainWindow) {
    gbl_cur_main_window = this;
    main_ui_->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);
#if 1                                   // fix me
    QLabel *x = new QLabel;
    x->setAlignment(Qt::AlignHCenter);
    x->setMinimumSize(x->sizeHint());
    QLabel *y = new QLabel;
    QLabel *z = new QLabel;
    main_ui_->statusBar->addWidget(x);
    main_ui_->statusBar->addWidget(y, 1);
    main_ui_->statusBar->addWidget(z, 2);
#endif
    setFileMenu();

}

void MainWindow::setFileMenu(void) {
    connect(main_ui_->actionNewEmptySession, SIGNAL(triggered()),
            this, SLOT(newEmptySession()));
    connect(main_ui_->actionNewSessionFromScript, SIGNAL(triggered()),
            this, SLOT(newSessionFromScript()));
    connect(main_ui_->actionOpenCheckpoint, SIGNAL(triggered()),
            &this->open_checkpoint_dialog, SLOT(openCheckpoint()));
    connect(main_ui_->actionAppendFromScript, SIGNAL(triggered()),
            this, SLOT(appendFromScript()));
    connect(main_ui_->actionAppendFromCheckpoint, SIGNAL(triggered()),
            &this->open_checkpoint_dialog, SLOT(appendFromCheckpoint()));
    connect(main_ui_->actionRunPythonFile, SIGNAL(triggered()),
            this, SLOT(runPythonFile()));
    connect(main_ui_->actionCreateWorkspace, SIGNAL(triggered()),
            &this->create_workspace_dialog, SLOT(createWorkspace()));
    connect(main_ui_->actionChangeWorkspace, SIGNAL(triggered()),
            &this->create_workspace_dialog, SLOT(changeWorkspace()));
    connect(main_ui_->actionExit, SIGNAL(triggered()),
            simApp, SLOT(closeAllWindows()));

    connect(main_ui_->actionCommandLineWindow, SIGNAL(triggered()),
            &this->open_command_line_window_dialog, SLOT(openCommandLineWindow()));
}

MainWindow::~MainWindow() {
    delete main_ui_;
}
