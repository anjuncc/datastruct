//
// Created by anjun on 3/27/16.
//

#include <stdio.h>
#include<stdlib.h>
#include<mm_malloc.h>
typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE,*PNODE;
PNODE create_list(void){
	int len;
	int i;
	int val;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));//头结点
	if(NULL == pHead){
		printf("分配失败\n");
		exit(-1);
	}
	PNODE pTail  = pHead;
	pTail->pNext = NULL;
	printf("请输入你要的节点数：len=");
	scanf("%d",&len);
	for(i=0;i<len;++i){
		printf("请输入第%d个节点的值：",i+1);
		scanf("%d",&val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL == pNew){
			printf("分配失败\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext =pNew;
		pNew->pNext =  NULL;
		pTail  = pNew;
	}
	return pHead;
}
void traverse_list(PNODE pHead){
	PNODE p  = pHead->pNext;
	while(NULL !=p){
		printf("%d ",p->data);
		p=p->pNext;
	}
	printf("\n");
}
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE,int,int);
bool delete_list(PNODE,int,int*);
PNODE sort_list(PNODE);
int main(void){
	PNODE pHead  = NULL;
	pHead = create_list();
	traverse_list(pHead);
	int temp;
	scanf("%d",&temp);
	return 0;
}
bool is_empty(PNODE pHead){
	if(NULL == pHead->pNext)
		return true;
	else
		return false;
}
int length_list(PNODE pHead){
	int i= 0;
	while (NULL ==pHead->pNext){
		pHead = pHead->pNext;
		i++;
	}
	return i;
}
PNODE sort_list(PNODE pHead){
	int i,j,t;
	int len= length_list(pHead);
	PNODE p,q;
	for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext){
		for(j=i+1,q=p->pNext;j<len;++j,q=q->pNext){
			if(p->data > q->data){
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
	return pHead;
}
/**
pos从1开始
*/
bool insert_list(PNODE pHead,int pos,int val){
	int i = 0;
	PNODE p = pHead;
	while(NULL !=p && i<pos-1){
		p = p->pNext;
		++i;
	}
	if(i>pos-1|| NULL == p)
		return false;
	PNODE pNew  = (PNODE)malloc(sizeof(NODE));
	if(NULL == pNew){
		printf("动态分配失败\n");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext=pNew;
	pNew->pNext = q;

	return true;
}
bool delete_list(PNODE,int,int*){
	return false;
}