#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define N 10
#define ERROR 0
#define OK 1
typedef struct node {    //����ڵ�
	int data;
	struct node *next;
} LinkList;

LinkList *InitList();//InitList����˳���
LinkList *CreateList(int n);//��β�巨����������
//DestoryList���ٱ�
void ClearList(LinkList *head);//Clearist��Ϊ�ձ�
//ListEmpty��ѯ�Ƿ�Ϊ�ձ��Ƿ���1���񷵻�0
void ListLength(LinkList *head) ;//�������
//GetElem���λ
void LocateLink(LinkList *head,int x);//����λ//��λĳֵ�����򷵻�0
//PriorElem���ǰһλ�����򷵻�0
//NextElem �����һλ�����򷵻�0
void ListInsert(LinkList *head,int i,int x) ; //����λ
void ListDelete(LinkList *head,int i);//ɾ��λ
void PrintList(LinkList *head);//�������

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

LinkList *InitList(){  //���������� 
	LinkList *head;
	head=(LinkList*)malloc(sizeof(LinkList));
	head->next=NULL;
	return head;
}

LinkList *CreateList(int n) { //��β�巨����������
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

void PrintList(LinkList *head) { //�������
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
	printf("����Ϊ��\n");
}

void ListLength(LinkList *head) { //���
	int count=0;
	LinkList *p;
	p=head->next;
	while(p!=NULL) {
		count++;
		p=p->next;
	}
	printf("����ĳ���Ϊ%d\n",count);
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

void ListDelete(LinkList *head,int i) {//ɾ����iλԪ��
	int j;
	LinkList *p,*q;
	p=head;
	j=0;
	while(p!=NULL&&j<i-1) {
		p=p->next;
		j++;
	}
	if(p==NULL||i<1)
		printf("%dλ������\n",i);
	else {
		q=p->next;
		p->next=q->next;
		free(q);
		printf("%dλ��ɾ��\n",i);
	}
}

void LocateLink(LinkList *head,int x) {//��λλ
	LinkList *p;
	int j;
	p=head->next;
	j=1;
	while(p!=NULL&&p->data!=x) {
		p=p->next;
		j++;
	}
	if(p==NULL)
		printf("%dλ�ڵ���λ\n",x);
	else
		printf("%dλ�ڵ�%dλ\n",x,j);
}

void ClearList(LinkList *head) { //�ձ�
	LinkList *p,*q;
	p=head->next;
	head->next=NULL;
	while(p!=NULL) {
		q=p;
		p=p->next;
		free(q);
	}
	printf("��������ϴ\n");
}





