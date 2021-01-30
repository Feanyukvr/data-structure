#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node { //创建表的结点
	int data;
	struct Node *next;
} LinkList;

void InitList(LinkList *&head) ; //创造表 
void ListInsert(LinkList *head,int i,int x) ;  //在第i个位置上插入新的元素
void print(LinkList *head) ;   //输出表的所有的元素

int main() {
	LinkList *c;
	InitList(c);
	ListInsert(c,1,40);
	ListInsert(c,2,30);
	ListInsert(c,3,17);
	ListInsert(c,4,16);
	ListInsert(c,3,14);
	print(c);
	return 0;
}

void InitList(LinkList *&head) { //创造表 
	head=(LinkList*)malloc(sizeof(LinkList));
	head->next=NULL;
}

void ListInsert(LinkList *head,int i,int x) {  //在第i个位置上插入新的元素
	int j;
	LinkList *p,*s;
	p=head;
	j=0;
	while(p!=NULL&&j<i-1) {
		p=p->next;
		j++;
	}
	if(p==NULL||i<1)
		printf("不能在%d位上插入%d\n",i,x);
	else {
		s=(LinkList*)malloc(sizeof(LinkList));
		s->data=x;
		s->next=p->next;
		p->next=s;
		printf("成功在%d位上插入%d\n",i,x);
	}
}

void print(LinkList *head) {   //输出表的所有的元素
	LinkList *p;
	p=head->next;
	while(p!=NULL) {
		printf("%d ",p->data);
		p=p->next;
	}
}


