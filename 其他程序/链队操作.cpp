#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#define Maxsize 100

typedef struct Queue{
	int data;
	struct Queue *next;
}Node, *QueueNode;

typedef struct LNode{
	Node *front;
	Node *rear;
}LinkQueue;

/*队列初始化*/ 
int re_creat(LinkQueue &Q){
	Q.front=Q.rear=new Node;
	Q.front->next=NULL;
	return 1;
}

/*队列进队*/
int in_Queue(LinkQueue &Q,int e){
	QueueNode q;
	q=new Node;
	q->data=e;
	q->next=NULL;
	Q.rear->next=q;
	return 1;
} 

/* 队列出队*/
int out_Queue(LinkQueue &Q,int &e){
	if(Q.front==Q.rear) return 0;
	e = Q.front->next->data;
	Q.front->next=Q.front->next->next;
	if(Q.front->next==NULL) Q.rear=Q.front;
	return 1;
} 
/**/






int main(){
	
	return 1;
}
