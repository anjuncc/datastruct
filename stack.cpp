//
// Created by anjun on 3/27/16.
//

#include<stdio.h>
#include<stdlib.h>
#include<mm_malloc.h>
typedef struct Node
{
    int data;
    struct Node *pNext;
}NODE,*PNODE;
typedef struct Stack{
    PNODE pTop;
    PNODE pBottom;
}STACK,*PSTACK;
void init(PSTACK);
void push(PSTACK,int val);
void pop(PSTACK);
int main(void){
    STACK S;
    init(&S);
    push(&S,1);
    pop(&S);
    return 0;
}
void init(PSTACK pS){
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if(NULL== pS->pTop){
        printf("err");
        exit(-1);
    }else{
        pS->pBottom  = pS->pTop;
        pS->pTop->pNext = NULL;
    }
}