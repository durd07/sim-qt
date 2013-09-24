#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "open_checkpoint_dialog.h"
#include "create_workspace_dialog.h"
#include "open_command_line_window_dialog.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void setFileMenu(void);
    void setEditMenu(void);
    void setRunMenu(void);
    void setDebugMenu(void);
    void setWindowMenu(void);
    void setHelpMenu(void);
signals:
private slots:
    void newEmptySession(void);
    void newSessionFromScript(void);
    bool saveCheckpoint(void);
    void appendFromScript(void);
    bool loadPresistentState(void);
    bool savePresitentState(void);
    void runPythonFile(void);

private:
    void setToolsMenu(void);
signals:
private slots:

private:
    Ui::MainWindow *main_ui_;
    OpenCheckpointDialog open_checkpoint_dialog;
    CreateWorkspaceDialog create_workspace_dialog;
    OpenCommandLineWindowDialog open_command_line_window_dialog;
};

#endif
