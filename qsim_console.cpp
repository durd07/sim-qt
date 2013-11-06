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

QString resultString;

void QSimConsole::printHistory()
{
    uint index = 1;
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
    //set the Python Prompt
    setNormalPrompt(true);

    //redestration
    init_redestration();
    getAllCommandList();
}
char save_error_type[1024], save_error_info[1024];

//Desctructor
QSimConsole::~QSimConsole()
{
    destroy_redestration();
}

//Call the Python interpreter to execute the command
//retrieve back results using the python internal stdout/err redirectory (see above)
QString QSimConsole::interpretCommand(const QString &command, int *res)
{
    *res = 0;
    QConsole::interpretCommand(command, res);
    char* cmd = command.toLatin1().data();

    set_socket_nonblock(::parent);
    exec_command(cmd);
    append("");
    setTextColor(QColor("blue"));
    myTimerId = startTimer(300);
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
    }
    else {
        QWidget::timerEvent(event);
    }
    if(exec_process_over) {
        killTimer(myTimerId);
        myTimerId = 0;

        moveCursor(QTextCursor::End);
        //Display the prompt again
        displayPrompt();
        return;
    }
}

void QSimConsole::getAllCommandList()
{
    all_command_list << "ls" << "uname -a" << "ll" << "who" << "whoami" << "whoareyou";
}
