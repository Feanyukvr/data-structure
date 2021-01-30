#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXSIZE 6   //
typedef struct {
	int data[MAXSIZE];
	int front,rear;
} SeQueue;
void InitQueue(SeQueue *&q) { //
	q=(SeQueue*)malloc(sizeof(SeQueue));
	q->front=0;
	q->rear=0;
}



void PushQueue(SeQueue *q,int x) { //在什么队列插入x
	if((q->rear+1)%MAXSIZE==q->front)
		printf("Queue full\n");
	else {
		q->rear=(q->rear+1)%MAXSIZE;
		q->data[q->rear]=x;
		printf("%d\n",x);
	}
}


void GetHeadQueue(SeQueue *q) { //得到首值
	int x;
	if(q->front==q->rear){
		printf("Queue unfull\n");
	}
	else{
		printf("%d\n",q->data[(q->front+1)%MAXSIZE]);
		q->front=(q->front+1)%MAXSIZE;
	}
}


void ClearQueue(SeQueue *q) { //
	q->front=0;
	q->rear=0;
	printf("ok");
}

void QueueLength(SeQueue *q) { //
	int len;
	len=(q->rear-q->front+MAXSIZE)%MAXSIZE;
	printf("Queue Length is %d\n",len);
}

int main() {
	SeQueue *q;         //
	InitQueue(q);

	PushQueue(q,1);   //
	PushQueue(q,2);
	PushQueue(q,3);
	PushQueue(q,4);
	QueueLength(q);
	PushQueue(q,5);
	PushQueue(q,6);
	
	GetHeadQueue(q);
	GetHeadQueue(q);
	GetHeadQueue(q);
	GetHeadQueue(q);
	GetHeadQueue(q);
	GetHeadQueue(q);
	ClearQueue(q);
	QueueLength(q);
	return 0;
}

