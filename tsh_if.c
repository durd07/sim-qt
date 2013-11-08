/*******************************************************************************
 **  File Name   : tsh_if.c
 **  Author      : xhyz 
 **  E-mail      : xhyz008@163.com
 **  Created Time: Mon Oct 28 15:09:40 2013
 *******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include "tsh_if.h"

static char* output_buffer = NULL;

int init_redestration() {
    output_buffer = (char*)malloc(sizeof(char) * MAX_BUFFERSIZE);
    if(output_buffer == NULL) {
        return -1;
    }
    return 0;
}

int destroy_redestration() {
    free(output_buffer);
    return 0;
}

int set_socket_nonblock(int fd)
{
    int flag = fcntl(fd,F_GETFL,0);
    if(-1 == fcntl(fd, F_SETFL, flag | O_NONBLOCK)) {
        return -1;
    }
    return 0;
}

int exec_command(char* cmd) {
    if(write(parent, cmd, strlen(cmd)) < 0) {
        perror("write error!");
        return -1;
    }
    return 0;
}

char* get_output() {
    memset(output_buffer, 0, sizeof(char) * MAX_BUFFERSIZE);
    if(read(parent, output_buffer, sizeof(char) * MAX_BUFFERSIZE) < 0)
    {
        perror("read");
        return NULL;
    }
    return output_buffer;
}

void kill_exec_process() {
    if(0 != sub_process_id) {
        if(kill(sub_process_id, SIGINT) < 0) {
            perror("kill sub_process_id");
            return;
        }
    }
}
