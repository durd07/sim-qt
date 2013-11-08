/*******************************************************************************
 **  File Name   : tsh_if.h
 **  Author      : xhyz 
 **  E-mail      : xhyz008@163.com
 **  Created Time: Mon Oct 28 15:10:48 2013
 *******************************************************************************/
#ifndef TSH_IF_H
#define TSH_IF_H

#define MAX_BUFFERSIZE 4096
extern int exec_process_over;
extern int parent;
extern int sub_process_id;

int init_redestration();
int destroy_redestration();
int set_socket_nonblock(int fd);
int exec_command(char* cmd);
char* get_output();
void kill_exec_process();

#endif


