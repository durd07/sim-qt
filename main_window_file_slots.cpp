#include <QFileDialog>
#include "main_window.h"

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
    QString scriptName = QFileDialog::getOpenFileName(this,
                                                      tr("Selete checkpoint"),
                                                      ".",
                                                      tr("Sim checkpoint (*.sc)"));
}

bool MainWindow::saveCheckpoint(void) {
    return true;
}

void MainWindow::appendFromScript(void) {
    QString scriptName = QFileDialog::getOpenFileName(this,
                                                      tr("Selete start script"),
                                                      ".",
                                                      tr("Script files (*.sim)"));
}

void MainWindow::appendFromCheckpoint(void) {
    QString scriptName = QFileDialog::getOpenFileName(this,
                                                      tr("Selete checkpoint"),
                                                      ".",
                                                      tr("Sim checkpoint (*.sc)"));
}

bool MainWindow::loadPresistentState(void) {
    return true;
}

bool MainWindow::savePresitentState(void) {
    return true;
}

void MainWindow::runPythonFile(void) {
    QString scriptName = QFileDialog::getOpenFileName(this,
                                                      tr("Run python file"),
                                                      ".",
                                                      tr("Python files (*.py)"));
}

void MainWindow::createWorkspace(void) {

}

void MainWindow::changeWorkspace(void) {

}

