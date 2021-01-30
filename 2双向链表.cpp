#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int ElemType;
typedef struct Node { //?????????
	int data;
	struct Node *next;
	struct Node *prior;
} DLinkList;


DLinkList *InitList(int n) { //定义命长 2
	DLinkList *head,*p,*s;
	head=(DLinkList*)malloc(sizeof(DLinkList));
	head->next=NULL;
	p=head;
	for(int i=1; i<=n; i++) {
		s=(DLinkList*)malloc(sizeof(DLinkList));
		scanf("%d",&s->data);
		s->next=NULL;
		s->prior=p;
		p->next=s;
		p=s;
	}
	return head;
}

void print(DLinkList *head) {//输出
	DLinkList *p;
	p=head->next;
	while(p!=NULL) {
		printf("%d ",p->data);
		p=p->next;
	}
}


void PriorList(DLinkList *head,int n){//输出前位 
	DLinkList *p;
	int i;
	p=head->next;
	for(i=1;i<n;i++){
		p=p->next;
	}
	p=p->prior;
	printf(" %d \n",p->data);
}



int main() {
	DLinkList *he;
	he=InitList(5);
	print(he);
	
    PriorList(he,3);  //输出前位 

	return 0;

}
