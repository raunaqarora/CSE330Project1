//  tcb.h
//  Project1
//  Created by Raunaq Arora on 2/15/17.
//  Copyright © 2017 Raunaq Arora. All rights reserved.

#ifndef tcb_h
#define tcb_h
#define _XOPEN_SOURCE 600

#include <string.h>
#include <ucontext.h>

typedef struct TCB_t {
    struct TCB_t     *next;
    struct TCB_t     *prev;
    ucontext_t      context;
} TCB_t;



void init_TCB (TCB_t *tcb, void *function, void *stackP, int stack_size)
{
    memset(tcb, '\0', sizeof(TCB_t));       // wash, rinse
    getcontext(&tcb->context);              // have to get parent context, else snow forms on hell
    tcb->context.uc_stack.ss_sp = stackP;
    tcb->context.uc_stack.ss_size = (size_t) stack_size;
    makecontext(&tcb->context, function, 0);// context is now cooked
}


#endif
