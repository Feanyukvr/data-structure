//ѭ������  ʵ�ֶ�ѭ������ĳ�ʼ�������������룬ɾ�����������
//��ֻ����βָ��rear����ʱͷ�ڵ�Ϊrear->next
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node { //���嵥����Ľڵ�
	int data;
	struct node *next;
} LinkList;

LinkList *CreateList() { //��ʼ��һ��ѭ������
	LinkList *rear,*head;
	head = (LinkList*)malloc(sizeof(LinkList));
	rear=head;
	rear->next=head;
	return head;
}

void PushQueue(LinkList *head,int x) { //β��Ԫ��x
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

void GetHeadQueue(LinkList *head) {//���ɾ����λ����
	LinkList *p;
	if(head->next==head)
		printf("�ѿ�\n");
	else {
		p=head->next;
		printf("%d\n",p->data);
		head->next=head->next->next;
		free(p);
	}
}

void QueueLength(LinkList *head) { //�󳤶�
	LinkList *p;
	int n=0;
	p=head;
	while(head!=p->next) {
		p=p->next;
		n++;
	}
	printf("��Ϊ%d\n",n);
}


void PrintList(LinkList *head) { //���ѭ�����������Ԫ��
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

