#ifndef IPC_H
#define IPC_H

#include <stdio.h>
#include <stdlib.h>

void signal_handler(int signum);
void use_pipes();
void use_signals();

#endif
