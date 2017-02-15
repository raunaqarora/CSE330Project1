//
//  main.c
//  Project1
//
//  Created by Raunaq Arora on 2/14/17.
//  Copyright © 2017 Raunaq Arora. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include "q.h"

int main()
{
    struct node* head = NewItem(0);
    //printAll(&head);
    InitQueue(&head);
    struct node* temp;
    for(int i = 1; i < 10; i++)
    {
        temp = NewItem(i);
        AddQueue(&head, temp);
    }
    printAll(&head);
    RotateQ(&head);
    printAll(&head);
    DelQueue(&head);
    printAll(&head);
    /*for(int i = 0; i < 9; i++)
     {
     DelQueue(&head);
     }
     printAll(&head);*/
    
}
