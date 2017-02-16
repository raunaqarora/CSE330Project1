//  q.h
//  Project1
//  Created by Raunaq Arora on 2/14/17.
//  Copyright © 2017 Raunaq Arora. All rights reserved.
//

#ifndef q_h
#define q_h
#include<stdlib.h>
#include "tcb.h"


/*struct node
{
    int payload;
    struct node* next;
    struct node* prev;
};*/

TCB_t* NewItem ()
{
    TCB_t* tempItem = malloc(sizeof(TCB_t));
    return tempItem;
};

void InitQueue(TCB_t **item)
{
    *item = NULL;
};

void AddQueue(TCB_t** head, TCB_t* item)
{
    if((*head) == NULL)
    {
        (*head) = item;
        (*head)->next = item;
        (*head)->prev = item;
    }
    /*else if((*head)->next == (*head))
     {
     //Might be needed
     }*/
    else
    {
        //TCB_t* last = malloc(sizeof(TCB_t));
        TCB_t* last = (*head)->prev;
        //last = (*head)->prev;
        last->next = item;
        item->prev = last;
        item->next = (*head);
        (*head)->prev = item;
    }
};

TCB_t* DelQueue(TCB_t** head)
{
    TCB_t* toReturn;
    if((*head) == NULL)
    {
        return NULL;
    }
    else if((*head)->prev == (*head))
    {
        toReturn = (*head);
        (*head)->next = NULL;
        (*head)->prev = NULL;
        free(*head);
        (*head) = NULL;
        return toReturn;
    }
    else
    {
        toReturn = (*head);
        (*head) = (*head)->next;
        toReturn->prev->next = toReturn->next;
        toReturn->next->prev = toReturn->prev;
        return toReturn;
    }
};

/*void printAll(struct node** head)
 {
 if((*head) == NULL)
 {
 printf("Empty Queue \n");
 return;
 }
 printf("Head Node: %d Next Node: %d Prev Node: %d \n",(*head)->payload, (*head)->next->payload, (*head)->prev->payload);
 if((*head)->next == (*head))
 {
 return;
 }
 struct node* traverser = (*head)->next;
 while(traverser != (*head))
 {
 printf("Current Node: %d Next Node: %d Prev Node: %d \n",traverser->payload, traverser->next->payload, traverser->prev->payload);
 traverser = traverser->next;
 }
 }*/

void RotateQ(TCB_t** head)
{
    (*head) = (*head)->next;
};


#endif
