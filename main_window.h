#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

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
    void setToolsMenu(void);
    void setWindowMenu(void);
    void setHelpMenu(void);

    void init_StatusBar(void);
signals:
private slots:
    //File Menu
    void newEmptySession(void);
    void newSessionFromScript(void);
    void openCheckpoint(void);
    bool saveCheckpoint(void);
    void appendFromScript(void);
    void appendFromCheckpoint(void);
    bool loadPresistentState(void);
    bool savePresitentState(void);
    void runPythonFile(void);
    void createWorkspace(void);
    void changeWorkspace(void);

    //Tool Menu
    void openCommandLineWindow(void);

private:
    Ui::MainWindow *main_ui_;
};

#endif
