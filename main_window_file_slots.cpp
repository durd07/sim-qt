#include <QFileDialog>
#include "main_window.h"
#include "open_checkpoint_dialog.h"

void MainWindow::newEmptySession(void) {
    MainWindow *new_mainWindow = new(MainWindow);
    new_mainWindow->show();
    this->close();
}

void MainWindow::newSessionFromScript(void) {
    QString scriptName = QFileDialog::getOpenFileName(this,
                                                      tr("Selete start script"),
                                                      ".",
                                                      tr("Script files (*.sim)"));
    if (!scriptName.isEmpty()) {
        // TODO
    }
}
void MainWindow::openCheckpoint(void) {
    OpenCheckpointDialog open_checkpoint_dialog;

    if(QDialog::Accepted == open_checkpoint_dialog.exec()) {
        QString checkpoint_name = open_checkpoint_dialog.GetCheckpointName();

        if (!checkpoint_name.isEmpty()) {
            // TODO
        }
    }
}

bool MainWindow::saveCheckpoint(void) {
    return true;
}

void MainWindow::appendFromScript(void) {
    QString scriptName = QFileDialog::getOpenFileName(this,
                                                      tr("Selete start script"),
                                                      ".",
                                                      tr("Script files (*.sim)"));
    if (!scriptName.isEmpty()) {
        // TODO
    }
}

void MainWindow::appendFromCheckpoint(void) {
    OpenCheckpointDialog open_checkpoint_dialog;

    if(QDialog::Accepted == open_checkpoint_dialog.exec()) {
        QString checkpoint_name = open_checkpoint_dialog.GetCheckpointName();

        if (!checkpoint_name.isEmpty()) {
            // TODO
        }
    }
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

extern QString WorkSpachPath;
void MainWindow::createWorkspace(void) {
#if 0
    CreateWorkspaceDialog create_workspace_dialog(tr("Select directory to use as workspace ..."));
    create_workspace_dialog.exec();
#else
    QString workspace_path = QFileDialog::getExistingDirectory(this, tr("Select directory to use as workspace ..."),
    WorkSpachPath,
    QFileDialog::ShowDirsOnly
    | QFileDialog::DontResolveSymlinks);

    if (!workspace_path.isEmpty()) {

    }
#endif
}

void MainWindow::changeWorkspace(void) {
#if 0
    CreateWorkspaceDialog create_workspace_dialog("Select workspace to use ...");
    create_workspace_dialog.exec();
#else
    QString workspace_path = QFileDialog::getExistingDirectory(this, tr("Select workspace to use ..."),
    WorkSpachPath,
    QFileDialog::ShowDirsOnly
    | QFileDialog::DontResolveSymlinks);

    if (!workspace_path.isEmpty()) {
        // TODO
    }
#endif
}
