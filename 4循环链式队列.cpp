//循环链表  实现对循环链表的初始化，创建，插入，删除，输出操作
//它只设置尾指针rear，这时头节点为rear->next
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node { //定义单链表的节点
	int data;
	struct node *next;
} LinkList;

LinkList *CreateList() { //初始化一个循环链表
	LinkList *rear,*head;
	head = (LinkList*)malloc(sizeof(LinkList));
	rear=head;
	rear->next=head;
	return head;
}

void PushQueue(LinkList *head,int x) { //尾插元素x
	LinkList *a,*p;
	a=(LinkList*)malloc(sizeof(LinkList));
	a->data=x;
	a->next=head;
	p=head;
	while(head!=p->next) {
		p=p->next;
	}
	p->next=a;
	printf("%d\n",x);
}

void GetHeadQueue(LinkList *head) {//输出删除首位数字
	LinkList *p;
	if(head->next==head)
		printf("已空\n");
	else {
		p=head->next;
		printf("%d\n",p->data);
		head->next=head->next->next;
		free(p);
	}
}

void QueueLength(LinkList *head) { //求长度
	LinkList *p;
	int n=0;
	p=head;
	while(head!=p->next) {
		p=p->next;
		n++;
	}
	printf("长为%d\n",n);
}


void PrintList(LinkList *head) { //输出循环链表的所有元素
	LinkList *p;
	p=head->next;
	while(p!=head) {
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int main() {
	LinkList *he;
	he=CreateList();
	PushQueue(he,1);
	PushQueue(he,2);
	PushQueue(he,4);
	QueueLength(he);
	PrintList(he);
	
	GetHeadQueue(he);
	QueueLength(he);
	return 0;
}

