/*******************************************************************************
 **  File Name   : tsh_if.c
 **  Author      : xhyz 
 **  E-mail      : xhyz008@163.com
 **  Created Time: Mon Oct 28 15:09:40 2013
 *******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <QFile>
#include <iostream>
#include <QTextStream>

using namespace std;
#ifdef __cplusplus
extern "C" {
#endif

#include "tsh_if.h"

#ifdef __cplusplus
}
#endif

int oldstdin;
int oldstdout;
int oldstderr;
int inpipe[2];
int outpipe[2];
int errpipe[2];

const int BUFSIZE=500000;
char buffer[10000];
int read_from_stdin = 1;

FILE* stdout_id;
FILE* stdin_id;
void init_redestration()
{
    //read_from_stdin = 1;
	oldstdin = dup(0);
    oldstdout = dup(1);
    oldstderr = dup(2);
	pipe( inpipe );
    pipe( outpipe );
    pipe( errpipe );
	dup2( inpipe[0], 0);
    dup2( outpipe[1], 1 );
    dup2( errpipe[1], 2 );
    close(inpipe[0]);
    close(outpipe[1]);
    close(errpipe[1]);
}

void destroy_redestration()
{
    //read_from_stdin = 1;
}

char* exec_command(char* cmd)
{
	int count = 0;
    count = write( inpipe[1] , cmd, 10000);
    memset(buffer, 0, sizeof(buffer));
    count = read( outpipe[0] , buffer, 10000 );
    return buffer;
}

