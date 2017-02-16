//
//  threads.h
//  Project1
//
//  Created by Raunaq Arora on 2/15/17.
//  Copyright © 2017 Raunaq Arora. All rights reserved.
//

#ifndef threads_h
#define threads_h
#include "q.h"
#include <ucontext.h>

extern TCB_t* RunQ;

void start_thread(void (*function)(void))
{
    void *stackpointer = malloc(8192);
    TCB_t* tcb = NewItem();
    init_TCB(tcb, function, stackpointer, 8192);
    AddQueue(&RunQ, tcb);
}

void run()
{
    ucontext_t parent;
    getcontext(&parent);
    swapcontext(&parent, &(RunQ->context));  // start the first thread
}

void yield() // similar to run
{
//       rotate the run Q;
    TCB_t *temp = RunQ;
    RotateQ(&RunQ);
    swapcontext(&(temp->context), &(RunQ->context));
//       swap the context, from previous thread to the thread pointed to by RunQ
}



#endif /* threads_h */
