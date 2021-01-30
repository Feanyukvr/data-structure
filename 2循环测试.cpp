//循环链表  实现对循环链表的初始化，创建，插入，删除，输出操作
//它只设置尾指针rear，这时头节点为rear->next
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node { //定义单链表的节点
	int data;
	struct node *next;
} LinkList;

LinkList *CreateList(); //初始化一个循环链表
LinkList *CreateList(int n); //创建一个循环链表
int InsertList(LinkList *head,int i,int x); //在循环链表的i位置处插入元素x
int deletelist(LinkList *head,int i); //删除位置i处的节点
int deletelist(LinkList *head,int i); //删除位置i处的节点
void PrintList(LinkList *head) ;//输出循环链表的所有元素
void NextElem(LinkList *head,int n) ; //输出点的下一个元素 
void noweyList(LinkList *head,int n) ;//尾端修饰 
void TwoElem(LinkList *head,int n) ; //输出循环链表的n个元素


int main() {
	int n=3;
	LinkList *he;
	he=CreateList(n);      //使用CreateList()函数
	PrintList(he);
	

	
	TwoElem(he,7);     //输出循环链表的n个元素
	
deletelist(he,4);       //尾端修饰 
	
	TwoElem(he,7);    
	
	return 0;
}






LinkList *CreateList() { //初始化一个循环链表
    LinkList *rear,*head;
	head = (LinkList*)malloc(sizeof(LinkList));
	rear=head;
	rear->next=head;
	return head;
}

LinkList *CreateList(int n) { //创建一个循环链表
	LinkList *p,*head,*rear;
	head=(LinkList*)malloc(sizeof(LinkList));
	rear=head;
	rear->next=head;
	for(int i=1; i<=n; i++) {
		p=(LinkList*)malloc(sizeof(LinkList));
		scanf("%d",&p->data);
		p->next=rear->next;
		rear->next=p;
		rear=p;
	}
	return head;
}

int InsertList(LinkList *head,int i,int x) { //在循环链表的i位置处插入元素x
	LinkList *p,*q;
	int j=0;
	p=head->next;
	while(p!=head) {
		j++;
		p=p->next;
	}
	p=head;
	for(int j=1; j<i; j++)
		p=p->next;
	if(i>j+1||i<1) {
		printf("插入位置出错\n");
		return -1;
	}
	q=(LinkList*)malloc(sizeof(LinkList));
	q->data=x;
	q->next=p->next;
	p->next=q;
	return 0;
}

int deletelist(LinkList *head,int i) { //删除位置i处的节点
	LinkList *p,*q;
	p=head->next;
	int j=0;
	while(p!=head) {
		j++;
		p=p->next;
	}

	p=head;
	for(j=1; j<i; j++)
		p=p->next;
	q=p->next;
	p->next=p->next->next;
	free(q);
	return 0;
}

void PrintList(LinkList *head) { //输出循环链表的所有元素
	LinkList *p;
	p=head->next;
	while(p!=head) {
		printf(" %d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void NextElem(LinkList *head,int n) { //输出循环链表的所有元素
	LinkList *p;
	int i;
	p=head->next;
	for(i=1;i<n;i++){
		p=p->next;
	}
	printf(" %d \n",p->data);
}
void TwoElem(LinkList *head,int n) { //输出循环链表的n个元素
	LinkList *p;
	int i;
	p=head->next;
	for(i=1;i<=n;i++){
		printf(" 好%d好 ",p->data);
		p=p->next;
	}
	printf("\n");
}

void noweyList(LinkList *head,int n) { //尾端修饰 
	LinkList *p,*q;
	int i;
	p=head;
	for(i=1;i<=n;i++) {
		p=p->next;
	}
	q=p->next;
	p->next=p->next->next;
	free(q);
}





