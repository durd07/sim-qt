#include "main_window.h"
#include "ui_main_window.h"

#include <QAction>
#include <QTreeWidget>
#include <QFileDialog>

static MainWindow *gbl_cur_main_window = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    main_ui_(new Ui::MainWindow) {
    gbl_cur_main_window = this;
    main_ui_->setupUi(this);

    connect(main_ui_->actionNewEmptySession, SIGNAL(triggered()), this, SLOT(newEmptySession()));
    connect(main_ui_->actionNewSessionFromScript, SIGNAL(triggered()), this, SLOT(newSessionFromScript()));
}

void MainWindow::newEmptySession(void) {

}

void MainWindow::newSessionFromScript(void) {
    QString scriptName = QFileDialog::getOpenFileName(this,
                                                      tr("Selete start script"),
                                                      ".",
                                                      tr("Script files (*.sim)"));
    if (!scriptName.isEmpty()) {

    }
}

void MainWindow::openCheckpoint(void) {

}

bool MainWindow::saveCheckpoint(void) {
    return true;
}

void MainWindow::appendFromScript(void) {

}

void MainWindow::appendFromCheckpoint(void) {

}

bool MainWindow::loadPresistentState(void) {
    return true;
}

bool MainWindow::savePresitentState(void) {
    return true;
}

void MainWindow::runPythonFile(void) {

}

void MainWindow::createWorkspace(void) {

}

void MainWindow::changeWorkspace(void) {

}

void MainWindow::exit(void) {

}

MainWindow::~MainWindow()
{
    delete main_ui_;
}
