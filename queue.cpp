//
// Created by anjun on 3/27/16.
//

#include<stdio.h>
#include<mm_malloc.h>

typedef struct Queue{
	int *pBase;//代表数组
	int front;
	int rear;

}QUEUE;
void init(QUEUE *);
bool en_queue(QUEUE*,int val);
void traverse_queue(QUEUE*);
bool full_queue(QUEUE*);
bool empty_queue(QUEUE*);

bool out_queue(QUEUE*,int *pVal);
int main(void){
	QUEUE Q;
	init(&Q);
	return 0;
}
void init(QUEUE *pQ){
	pQ->pBase = (int*)malloc(sizeof(int));
	pQ->front = 0;
	pQ->rear = 0;
}
bool full_queue(QUEUE*pQ){
	if(pQ->rear+1%6 ==pQ->front)
		return true;
	else
		return false;
}
bool en_queue(QUEUE*pQ,int val){
	if(full_queue(pQ)){
		return false;
	}else{
		pQ->pBase[pQ->rear]=val;
		pQ->rear = (pQ->rear+1)%6;
	}

}
void traverse_queue(QUEUE*pQ){
	int i=pQ->front;
	while(i !=pQ->rear){
		printf("%d ",pQ->pBase[i]);
		i = (i+1)%6;
	}
	printf("\n");
}

bool empty_queue(QUEUE *pQ){
	if(pQ->front == pQ->rear)
		return true;
	else
		return false;
}

bool out_queue(QUEUE* pQ,int *pVal){
	if(empty_queue(pQ)){
		return false;
	}else{
		*pVal = pQ->pBase[pQ->front];
		 pQ->front = (pQ->front+1)%6;
		 return true;
	}
}