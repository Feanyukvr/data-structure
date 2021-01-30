#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define N 10
#define ERROR 0
#define OK 1
typedef struct node {    //定义节点
	int data;
	struct node *next;
} LinkList;

LinkList *InitList();//InitList创建顺序表
LinkList *CreateList(int n);//用尾插法创建单链表
//DestoryList销毁表
void ClearList(LinkList *head);//Clearist置为空表
//ListEmpty查询是否为空表是返回1，否返回0
void ListLength(LinkList *head) ;//输出表长度
//GetElem输出位
void LocateLink(LinkList *head,int x);//查找位//定位某值，无则返回0
//PriorElem输出前一位，无则返回0
//NextElem 输出后一位，无则返回0
void ListInsert(LinkList *head,int i,int x) ; //插入位
void ListDelete(LinkList *head,int i);//删除位
void PrintList(LinkList *head);//输出链表

int main() {
	LinkList *c;
	c=InitList();
	ListInsert(c,1,40);
	ListInsert(c,2,20);
	ListInsert(c,3,17);
	ListInsert(c,4,16);
	ListInsert(c,5,14);
	PrintList(c);
	ListLength(c);

	ListInsert(c,3,10);
	PrintList(c);
	ListLength(c);

	LocateLink(c,10) ;
	LocateLink(c,20) ;

	ListDelete(c,2);
	PrintList(c);
	ListLength(c);

	ClearList(c);
	PrintList(c);
	ListLength(c);
	return 0;
}

LinkList *InitList(){  //创建空链表 
	LinkList *head;
	head=(LinkList*)malloc(sizeof(LinkList));
	head->next=NULL;
	return head;
}

LinkList *CreateList(int n) { //用尾插法创建单链表
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

void PrintList(LinkList *head) { //输出链表
	LinkList *p;
	int i=1;
	p=head->next;
	if(p!=NULL){
		while(p!=NULL) {
		printf("%d:",i);
		printf("%d ",p->data);
		p=p->next;
		i++;
		}
		printf("\n");
	}
	else
	printf("函数为空\n");
}

void ListLength(LinkList *head) { //求表长
	int count=0;
	LinkList *p;
	p=head->next;
	while(p!=NULL) {
		count++;
		p=p->next;
	}
	printf("链表的长度为%d\n",count);
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

void ListDelete(LinkList *head,int i) {//删除第i位元素
	int j;
	LinkList *p,*q;
	p=head;
	j=0;
	while(p!=NULL&&j<i-1) {
		p=p->next;
		j++;
	}
	if(p==NULL||i<1)
		printf("%d位不存在\n",i);
	else {
		q=p->next;
		p->next=q->next;
		free(q);
		printf("%d位已删除\n",i);
	}
}

void LocateLink(LinkList *head,int x) {//定位位
	LinkList *p;
	int j;
	p=head->next;
	j=1;
	while(p!=NULL&&p->data!=x) {
		p=p->next;
		j++;
	}
	if(p==NULL)
		printf("%d位于第无位\n",x);
	else
		printf("%d位于第%d位\n",x,j);
}

void ClearList(LinkList *head) { //空表
	LinkList *p,*q;
	p=head->next;
	head->next=NULL;
	while(p!=NULL) {
		q=p;
		p=p->next;
		free(q);
	}
	printf("链表已清洗\n");
}





