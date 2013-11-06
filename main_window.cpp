#include "main_window.h"
#include "ui_main_window.h"
#include "sim_application.h"
#include <QLabel>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    main_ui_(new Ui::MainWindow) {
    main_ui_->setupUi(this);

    //delete object when close() is called
    setAttribute(Qt::WA_DeleteOnClose);
    setAttribute(Qt::WA_QuitOnClose);

    init_StatusBar();

    setFileMenu();
    setToolsMenu();
}

void MainWindow::setFileMenu(void) {
    connect(main_ui_->actionNewEmptySession, SIGNAL(triggered()),
            this, SLOT(newEmptySession()));
    connect(main_ui_->actionNewSessionFromScript, SIGNAL(triggered()),
            this, SLOT(newSessionFromScript()));
    connect(main_ui_->actionOpenCheckpoint, SIGNAL(triggered()),
            this, SLOT(openCheckpoint()));
    connect(main_ui_->actionAppendFromScript, SIGNAL(triggered()),
            this, SLOT(appendFromScript()));
    connect(main_ui_->actionAppendFromCheckpoint, SIGNAL(triggered()),
            this, SLOT(appendFromCheckpoint()));
    connect(main_ui_->actionRunPythonFile, SIGNAL(triggered()),
            this, SLOT(runPythonFile()));
    connect(main_ui_->actionCreateWorkspace, SIGNAL(triggered()),
            this, SLOT(createWorkspace()));
    connect(main_ui_->actionChangeWorkspace, SIGNAL(triggered()),
            this, SLOT(changeWorkspace()));
    connect(main_ui_->actionExit, SIGNAL(triggered()),
            this, SLOT(close()));
}

void MainWindow::setToolsMenu(void) {
    connect(main_ui_->actionCommandLineWindow, SIGNAL(triggered()),
            this, SLOT(openCommandLineWindow()));

}

void MainWindow::init_StatusBar(void) {
    QLabel *x = new QLabel(" W999 ");
    x->setAlignment(Qt::AlignCenter);
    x->setMinimumSize(x->sizeHint());
    x->setFrameShape(QFrame::WinPanel);
    x->setFrameShadow(QFrame::Sunken);

    QLabel *y = new QLabel("222");
    y->setAlignment(Qt::AlignCenter);
    y->setMinimumSize(y->sizeHint());
    y->setFrameShape(QFrame::WinPanel);
    y->setFrameShadow(QFrame::Sunken);

    QLabel *z = new QLabel("333");
    z->setAlignment(Qt::AlignCenter);
    z->setMinimumSize(z->sizeHint());
    z->setFrameShape(QFrame::WinPanel);
    z->setFrameShadow(QFrame::Sunken);

    main_ui_->statusBar->addWidget(x, 0);
    main_ui_->statusBar->addWidget(y, 1);
    main_ui_->statusBar->addWidget(z, 2);

    x->setText(tr("baby baby"));
    y->setText(tr("baby baby"));
    z->setText(tr("baby baby"));
}
MainWindow::~MainWindow() {
    delete main_ui_;
}
