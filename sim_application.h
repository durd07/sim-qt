#ifndef SIMICT_APPLICATION_H
#define SIMICT_APPLICATION_H

#include <QApplication>

class SimApplication : public QApplication {
    Q_OBJECT
public:
    explicit SimApplication(int &argc, char **argv);

private:

signals:
    void newSessionFromScript(QString &ss_path);

};

extern SimApplication *simApp;

#endif
