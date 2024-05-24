/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：wrap_sig.c
*   Author：leekaihua
*   Date：20240524
*   Brife：
*



*/
#include "wrap_sig.h"

// initialize set to full, including all signals.
// objects of type sigset_t must be initialized by a call to
// either sigemptyset() or sigfillset() before being passed
// to the function sigaddset(), sigelset() and sigismember()
// return
//     succes: 0
//     error: -1
// more info: man 3 sigfillset
// more info about signal : man 7 signal
int Sigfillset(sigset_t* set) {
    int ret = -1;
    ret = sigfillset(set);
    if (-1 == ret) {
        printf("sigfillset error, exit...\n");
        exit(-1);
    }
    return ret;
}

// struct sigaction {
//     void (*sa_handler)(int);
//     void (*sa_sigaction)(int, siginfo_t *, void *);
//     sigset_t sa_mask;
//     int sa_flags;
//     void (*sa_restorer)(void);
// };
// more info: man 2 sigaction
int Sigaction(int signum,
        const struct sigaction* act,
        struct sigaction* oldact) {
    int ret = -1;
    ret = sigaction(signum, act, oldact);
    if (-1 == ret) {
        Perror("sigaction error");
    }
    return ret;
}