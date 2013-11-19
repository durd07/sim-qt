/*
  QSimConsole.cpp

  Controls the GEMBIRD Silver Shield PM USB outlet device

  (C) 2006, Mondrian Nuessle, Computer Architecture Group, University of Mannheim, Germany

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA


  nuessle@uni-mannheim.de

*/

// modified by YoungTaek Oh.

#ifdef WIN32
#   undef _DEBUG
#endif
#include "qsim_console.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "tsh_if.h"

#ifdef __cplusplus
}
#endif
#include <QDebug>
#include <string.h>
#include <QFile>
#include <QTextStream>

QString resultString;

void QSimConsole::printHistory()
{
    uint index = 1;
    resultString = "";
    for ( QStringList::Iterator it = history.begin(); it != history.end(); ++it )
    {
        resultString.append(QString("%1\t%2\n").arg(index).arg(*it));
        index ++;
    }
}

QSimConsole *QSimConsole::theInstance = NULL;

QSimConsole *QSimConsole::getInstance(QWidget *parent, const QString& welcomeText)
{
    if (!theInstance)
    {
        theInstance = new QSimConsole(parent, welcomeText);
    }
    return theInstance;
}

//QTcl console constructor (init the QTextEdit & the attributes)
QSimConsole::QSimConsole(QWidget *parent, const QString& welcomeText) :
        QConsole(parent, welcomeText),lines(0)
{
    myTimerId = 0;
    //set the Python Prompt
    setNormalPrompt(true);

    //redestration
    init_redestration();
    //set_socket_nonblock(::parent);
    getAllCommandList();
    getAllHistoryList();
//    myTimerId = startTimer(300);
    connect(this, SIGNAL(getData(QByteArray)), this, SLOT(writeData(QByteArray)));

}

void QSimConsole::writeData(const QByteArray &data) {
    exec_command((char*)data.data());
}

char save_error_type[1024], save_error_info[1024];

//Desctructor
QSimConsole::~QSimConsole()
{
    destroy_redestration();
    printHistoryToFile();
}

#include <QKeyEvent>
//Call the Python interpreter to execute the command
//retrieve back results using the python internal stdout/err redirectory (see above)
QString QSimConsole::interpretCommand(const QString &command, int *res)
{
    *res = 0;
//    QConsole::interpretCommand(command, res);
/*
    if(command == "") {
        append("");
        displayPrompt();
        return "";
    }

    if(command == QString(tr("history"))) {
        setTextColor(QColor("blue"));
        printHistory();
        append(resultString);
        displayPrompt();
        return "";
    }
*/
//    if(0 == myTimerId) {
//        QString temp = command + "\n";
//        char* cmd = temp.toLatin1().data();
//        exec_process_over = 0;
        exec_command((char*)command.toLatin1().data());

//        QTextCursor cursor = textCursor();    //Get the current command: we just remove the prompt
//        cursor.movePosition(QTextCursor::StartOfLine);
//        cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, promptLength);
//        cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
//        cursor.removeSelectedText();

//        QTextEdit::keyPressEvent(QKeyEvent)
//        append("");
//        setTextColor(QColor("blue"));
        //myTimerId = startTimer(300);
//    }
//    else {
//        append("");
//        displayPrompt();
//        return "";
//    }
    return "";
}

QStringList QSimConsole::suggestCommand(const QString &cmd, QString& prefix)
{
    QStringList list;
    prefix = "";
    resultString="";
    if (!cmd.isEmpty()) {
        QList<QString>::Iterator it = all_command_list.begin();
        for(it = all_command_list.begin(); it != all_command_list.end(); ++it) {
            if(!strncmp(cmd.toStdString().c_str(), (*it).toStdString().c_str(), cmd.count())) {
                 list.append(*it);
            }
        }
    }
    list.removeDuplicates();
    return list;
}

void QSimConsole::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == myTimerId) {
        char* buffer = get_output();
        insertPlainText(buffer);

//        moveCursor(QTextCursor::End);
        if(exec_process_over) {
//            killTimer(myTimerId);
//            myTimerId = 0;

            moveCursor(QTextCursor::End);
            //Display the prompt again
            displayPrompt();
            return;
        }
    }
    else {
        QWidget::timerEvent(event);
    }  
}

void QSimConsole::getAllCommandList() {
    QFile command_file(QString(tr(".command")));
    if(!command_file.open(QIODevice::ReadWrite)) {
        qDebug() << "getAllCommandList ### ERROR ###\n";
        return;
    }

    QTextStream infile(&command_file);
    QString command_string = infile.readAll();

    all_command_list = command_string.split("\n");
    command_file.close();
}

void QSimConsole::getAllHistoryList() {
    QFile history_file(QString(tr(".history")));
    if(!history_file.open(QIODevice::ReadWrite)) {
         qDebug() << "getAllCommandList ### ERROR ###\n";
         return;
     }

     QTextStream infile(&history_file);
     QString history_string = infile.readAll();

     all_history_list = history_string.split("\n");
     history = all_history_list;
     historyIndex = history.count();
     history_file.close();
}

void QSimConsole::printHistoryToFile() {
    QFile history_file(QString(tr(".history")));
    if(!history_file.open(QIODevice::WriteOnly)) {
         qDebug() << "getAllCommandList ### ERROR ###\n";
         return;
     }

    QTextStream outfile(&history_file);

    for(QStringList::Iterator it = history.begin(); it != history.end(); ++it) {
        if("" != *it) {
            outfile << *it << "\n";
        }
    }
    history_file.close();
}

void QSimConsole::cancleTheRunningProcess() {
    kill_exec_process();
}


