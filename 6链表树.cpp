#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define N 10
#define ERROR 0
#define OK 1
typedef struct node {    //定义节点
	int data;
	struct node *left;
	struct node *right;
} linkTree;

int main() {
	linkTree *c;
	c=initTree();



	return 0;
}

linkTree *initTree(){  //创建空链表
	linkTree *head;
	head=(linkTree*)malloc(sizeof(linkTree));
	head->left=NULL;
	head->right=NULL;
	return head;
}

linkTree *CreateList(int n) { //用尾插法创建单链表
	int i;
	LinkList *head,*p,*r;
	head=(LinkList*)malloc(sizeof(LinkList));
	head->next=NULL;
	r=head;
	for(i=1; i<=n; i++) {
		p=(LinkList*)malloc(sizeof(LinkList));
		p->next=NULL;
		scanf("%d",&p->data);
		r->next=p;
		r=r->next;
	}
	return head;
}
