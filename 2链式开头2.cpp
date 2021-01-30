#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node { //������Ľ��
	int data;
	struct Node *next;
} LinkList;

void InitList(LinkList *&head) ; //����� 
void ListInsert(LinkList *head,int i,int x) ;  //�ڵ�i��λ���ϲ����µ�Ԫ��
void print(LinkList *head) ;   //���������е�Ԫ��

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

void InitList(LinkList *&head) { //����� 
	head=(LinkList*)malloc(sizeof(LinkList));
	head->next=NULL;
}

void ListInsert(LinkList *head,int i,int x) {  //�ڵ�i��λ���ϲ����µ�Ԫ��
	int j;
	LinkList *p,*s;
	p=head;
	j=0;
	while(p!=NULL&&j<i-1) {
		p=p->next;
		j++;
	}
	if(p==NULL||i<1)
		printf("������%dλ�ϲ���%d\n",i,x);
	else {
		s=(LinkList*)malloc(sizeof(LinkList));
		s->data=x;
		s->next=p->next;
		p->next=s;
		printf("�ɹ���%dλ�ϲ���%d\n",i,x);
	}
}

void print(LinkList *head) {   //���������е�Ԫ��
	LinkList *p;
	p=head->next;
	while(p!=NULL) {
		printf("%d ",p->data);
		p=p->next;
	}
}


