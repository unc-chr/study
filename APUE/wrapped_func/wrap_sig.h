/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：wrap_sig.h
*   Author：leekaihua
*   Date：20240524
*   Brife：
*

*/

#ifndef __WRAP_SIG_H
#define __WRAP_SIG_H

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int Sigfillset(sigset_t* set);
int Sigaction(int signum, 
        const struct sigaction* act, 
        struct sigaction* oldact);

#endif