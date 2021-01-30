//ѭ������  ʵ�ֶ�ѭ������ĳ�ʼ�������������룬ɾ�����������
//��ֻ����βָ��rear����ʱͷ�ڵ�Ϊrear->next
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node { //���嵥����Ľڵ�
	int data;
	struct node *next;
} LinkList;

LinkList *CreateList(); //��ʼ��һ��ѭ������
LinkList *CreateList(int n); //����һ��ѭ������
int InsertList(LinkList *head,int i,int x); //��ѭ�������iλ�ô�����Ԫ��x
int deletelist(LinkList *head,int i); //ɾ��λ��i���Ľڵ�
int deletelist(LinkList *head,int i); //ɾ��λ��i���Ľڵ�
void PrintList(LinkList *head) ;//���ѭ�����������Ԫ��
void NextElem(LinkList *head,int n) ; //��������һ��Ԫ�� 
void noweyList(LinkList *head,int n) ;//β������ 
void TwoElem(LinkList *head,int n) ; //���ѭ�������n��Ԫ��


int main() {
	int n=3;
	LinkList *he;
	he=CreateList(n);      //ʹ��CreateList()����
	PrintList(he);
	

	
	TwoElem(he,7);     //���ѭ�������n��Ԫ��
	
deletelist(he,4);       //β������ 
	
	TwoElem(he,7);    
	
	return 0;
}






LinkList *CreateList() { //��ʼ��һ��ѭ������
    LinkList *rear,*head;
	head = (LinkList*)malloc(sizeof(LinkList));
	rear=head;
	rear->next=head;
	return head;
}

LinkList *CreateList(int n) { //����һ��ѭ������
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

int InsertList(LinkList *head,int i,int x) { //��ѭ�������iλ�ô�����Ԫ��x
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
		printf("����λ�ó���\n");
		return -1;
	}
	q=(LinkList*)malloc(sizeof(LinkList));
	q->data=x;
	q->next=p->next;
	p->next=q;
	return 0;
}

int deletelist(LinkList *head,int i) { //ɾ��λ��i���Ľڵ�
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

void PrintList(LinkList *head) { //���ѭ�����������Ԫ��
	LinkList *p;
	p=head->next;
	while(p!=head) {
		printf(" %d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void NextElem(LinkList *head,int n) { //���ѭ�����������Ԫ��
	LinkList *p;
	int i;
	p=head->next;
	for(i=1;i<n;i++){
		p=p->next;
	}
	printf(" %d \n",p->data);
}
void TwoElem(LinkList *head,int n) { //���ѭ�������n��Ԫ��
	LinkList *p;
	int i;
	p=head->next;
	for(i=1;i<=n;i++){
		printf(" ��%d�� ",p->data);
		p=p->next;
	}
	printf("\n");
}

void noweyList(LinkList *head,int n) { //β������ 
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





