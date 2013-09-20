#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "create_workspace_dialog.h"

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
signals:
private slots:
    void newEmptySession(void);
    void newSessionFromScript(void);
    void openCheckpoint(void);
    bool saveCheckpoint(void);
    void appendFromScript(void);
    void appendFromCheckpoint(void);
    bool loadPresistentState(void);
    bool savePresitentState(void);
    void runPythonFile(void);
private:
    Ui::MainWindow *main_ui_;
    CreateWorkspaceDialog create_workspace_dialog;
};

#endif
