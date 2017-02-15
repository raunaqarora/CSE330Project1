//
//  q.h
//  Project1
//
//  Created by Raunaq Arora on 2/14/17.
//  Copyright © 2017 Raunaq Arora. All rights reserved.
//

#ifndef q_h
#define q_h
#include<stdio.h>
#include<stdlib.h>


struct node
{
    int payload;
    struct node* next;
    struct node* prev;
};

struct node* NewItem (int payload)
{
    struct node* tempItem = malloc(sizeof(struct node));
    tempItem->payload = payload;
    return tempItem;
};

void InitQueue(struct node **item)
{
    if((*item) == NULL)
    {
        (*item) = malloc(sizeof(struct node));
    }
    (*item)->next = *item;
    (*item)->prev = *item;
};

void AddQueue(struct node** head, struct node* item)
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
        struct node* last = (*head)->prev;
        last->next = item;
        item->prev = last;
        item->next = (*head);
        (*head)->prev = item;
    }
};

struct node* DelQueue(struct node** head)
{
    struct node* toReturn;
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
        //toReturn->prev->prev = toReturn->prev->prev->prev;
        
        return toReturn;
    }
};

void RotateQ(struct node** head)
{
    //struct node* prev = (*head)->prev;
    (*head) = (*head)->next;
    //(*head)->prev->prev->prev = prev;
};


void printAll(struct node** head)
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
}


#endif
