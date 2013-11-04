/*******************************************************************************
 **  File Name   : tsh_if.c
 **  Author      : xhyz 
 **  E-mail      : xhyz008@163.com
 **  Created Time: Mon Oct 28 15:09:40 2013
 *******************************************************************************/
#include <string.h>
#include <unistd.h>

extern int parent;

static char buffer[10000];

void init_redestration() {

}

void destroy_redestration() {
}

char* exec_command(char* cmd) {
    if(write(parent, cmd, strlen(cmd)) < 0) {
        perror("write error!");
        return NULL;
    }

    memset(buffer, 0, sizeof(buffer));
    if(read(parent, buffer, sizeof(buffer)) < 0) {
        perror("read error!");
        return NULL;
    }
    return buffer;
}

