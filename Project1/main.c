//  thread_test.c 
//  Project1
//  Created by Raunaq Arora on 2/14/17.
//  Copyright © 2017 Raunaq Arora. All rights reserved.

#include<stdio.h>
#include<stdlib.h>
#include "threads.h"

TCB_t* RunQ;

void function1()
{
    while(1>0)
    {
        printf("This is function 1");
        yield();
    }
}

void function2()
{
    while(1>0)
    {
        printf("This is function 2");
        yield();
    }
}

void function3()
{
    while(1>0)
    {
        printf("This is function 3");
        yield();
    }
}

int main()
{
/*    struct node* head1 = NewItem(0);
    struct node* head2 = NewItem(10);
    //printAll(&head1);
    InitQueue(&head1);
    InitQueue(&head2);
    struct node* temp;
    for(int i = 1; i < 10; i++)
    {
        temp = NewItem(i);
        AddQueue(&head1, temp);
        temp = NewItem(i+10);
        AddQueue(&head2, temp);
    }
    printAll(&head1);
    printAll(&head2);
//    RotateQ(&head1);
//    printAll(&head1);
//    DelQueue(&head1);
//    printAll(&head1);
    for(int i = 0; i < 9; i++)
    {
        DelQueue(&head);
    }
    printAll(&head);*/
    
    
    RunQ = malloc(sizeof(TCB_t));
    InitQueue(&RunQ);
    start_thread(function1);
    start_thread(function2);
    start_thread(function3);
    run();
}

