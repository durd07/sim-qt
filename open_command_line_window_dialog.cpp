#include "open_command_line_window_dialog.h"
#include "qsim_console.h"
#include "QDebug"
#include "QTextLayout"
#include <QVBoxLayout>
extern "C" {
#include "tsh_if.h"
}

#include <QThread>

class GetOutputThread : public QThread {
public:
    GetOutputThread(QSimConsole* c) {
      console = c;
    }
protected:
    void run() {
        while(1) {
            qRegisterMetaType<QTextCursor>("QTextCursor");
            char *buffer = NULL;
            buffer = get_output();
            console->insertPlainText(buffer);

            QTextCursor cur = console->textCursor();
            cur.movePosition(QTextCursor::EndOfLine);
            console->setTextCursor(cur);

            //Saves the paragraph number of the prompt
            console->promptParagraph = cur.blockNumber();
        }
    }
private:
    QSimConsole *console ;
};


OpenCommandLineWindowDialog::OpenCommandLineWindowDialog(QWidget *parent) :
    QWidget(parent) {
    console = QSimConsole::getInstance(this);
    this->setFocusProxy((QWidget*)console);
    this->setMinimumSize(640, 480);
    this->setWindowTitle(tr("Simics Command Line"));
    this->setAttribute(Qt::WA_QuitOnClose, false);

    layout = new QVBoxLayout;
    layout->addWidget(console);
    this->setLayout(layout);

    GetOutputThread *thread = new GetOutputThread(console);
    thread->start();

}

OpenCommandLineWindowDialog::~OpenCommandLineWindowDialog() {
    delete console;
    delete layout;
}

