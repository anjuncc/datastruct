//
// Created by anjun on 3/27/16.
//
#include <stdio.h>
#include <mm_malloc.h>
typedef struct BTNode
{
    char data;
    struct BTNode *pLchild;
    struct BTNode *pRchild;
}*pBTNode;

pBTNode createBTree();

int main(void){
    struct  BTNode *pT = createBTree();
    return 0;
}

pBTNode createBTree() {
    pBTNode pA = (pBTNode)malloc(sizeof(BTNode));
    pBTNode pB = (pBTNode)malloc(sizeof(BTNode));
    pBTNode pC = (pBTNode)malloc(sizeof(BTNode));
    pBTNode pD = (pBTNode)malloc(sizeof(BTNode));
    pBTNode pE = (pBTNode)malloc(sizeof(BTNode));

    pA->data ='A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data ='E';

    pA->pLchild = pB;
    return nullptr;
}