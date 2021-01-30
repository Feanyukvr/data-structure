#include<stdio.h>
#include<malloc.h>
#include<queue>
#define MAXLEN 100
bool visited[MAXLEN];
typedef struct {
	char vex[MAXLEN];     //�����
	int arcs[MAXLEN][MAXLEN];    //�ڽӾ��󣬿��Կ�����
	int NumVertexes,NumEdges;    //ͼ�е�ǰ�Ķ������ͱ���
} Graph;

void CreateGraph(Graph *&G) ;//��������ͼ�ڽӱ�
void PrintGraph(Graph *G);   //����ڽӾ���
void DFSTraverse(Graph *G) ;//������ȱ������ڽӾ���
void BFSTraverse(Graph *G) ; //��ȱ����ڽӾ���ͼ

int main() {
	Graph *G;
	CreateGraph(G);
	PrintGraph(G);
	DFSTraverse(G);
	BFSTraverse(G);
}

void CreateGraph(Graph *&G){
	G=(Graph*)malloc(sizeof(Graph));//Ϊ�ṹ����󴴽��ռ�
	int i,j,k,c=1;
	printf("ͼ�Ķ�����Ϊ: ");
	while(c==1) {
		scanf("%d",&G->NumVertexes);
		if(G->NumVertexes>0&&G->NumVertexes<=100)
			c=0;
		else
			printf("love you:");
	}
	printf("ͼ�ı���Ϊ��");
	while(c==0) {
		scanf("%d",&G->NumEdges);
		if(G->NumEdges>=G->NumVertexes-1&&G->NumEdges<=G->NumVertexes*(G->NumVertexes-1)/2)
			c=1;
		else
			printf("love you:");
	}
	for(i=1; i<=G->NumVertexes; i++){//���붥����Ϣ
		G->vex[i]=getchar();
		printf("����%d������Ϣ��",i);
		G->vex[i]=getchar();
	}
	
	
		for(i=1; i<=G->NumVertexes; i++)//�ڽӾ����ʼ��
		for(j=1; j<=G->NumVertexes; j++)
			G->arcs[i][j]=0;
	for(k=1; k<=G->NumEdges; k++){  //����e����   ��ʱΪ����ͼ
		printf("����ߣ�");
		scanf("%d,%d",&i,&j);
		G->arcs[i][j]=1;
		G->arcs[j][i]=1;
	}
}

void PrintGraph(Graph *G) {
	printf("ͼ���ڽӾ���Ϊ��\n");
	for(int i=1; i<=G->NumVertexes; i++) {
		for(int j=1; j<=G->NumVertexes; j++)
			printf("%d",G->arcs[i][j]);
		printf("\n");
	}
}

void DFS(Graph *G,int i) {//������ȱ������ڽӾ���
	visited[i]=true;
	printf("%c",G->vex[i]) ;
	for(int j=1; j<=G->NumVertexes; j++)
		if(G->arcs[i][j]==1&&!visited[j])
			DFS(G,j);
}

void DFSTraverse(Graph *G) {
	printf("�ڽӾ����������ȱ������Ϊ��\n") ;
	for(int i=1; i<=G->NumVertexes; i++)
		visited[i]=false;      //��ʼ�����еĶ���״̬����δ���ʵ�״̬
	for(int i=1; i<=G->NumVertexes; i++)
		if(!visited[i])        //��δ���ʹ��Ķ������DFS��������ͨͼ��ֻ��ִ��һ��
			DFS(G,i);
	printf("\n") ;
}


typedef struct node { //���嵥����Ľڵ�
	char data;
	struct node *next;
} LinkList;

LinkList *CreateList() { //��ʼ��һ��ѭ������
	LinkList *rear,*head;
	head = (LinkList*)malloc(sizeof(LinkList));
	rear=head;
	rear->next=head;
	return head;
}



char front(LinkList *head) {//���ɾ����λ����
	LinkList *p;
	p=head->next;
	return p->data;
}
void pop(LinkList *head) {//ȥͷ 
	LinkList *p;
	p=head->next;
	head->next=head->next->next;
	free(p);
}

int QueueLength(LinkList *head) { //�󳤶�
	LinkList *p;
	int n=0;
	p=head;
	while(head!=p->next) {
		p=p->next;
		n++;
	}
	return n;
}

void push(LinkList *head,char x) { //β��Ԫ��x
	LinkList *a,*p;
	a=(LinkList*)malloc(sizeof(LinkList));
	a->data=x;
	a->next=head;
	p=head;
	while(head!=p->next) {
		p=p->next;
	}
	p->next=a;
}

void BFSTraverse(Graph *G) { //�ڽӾ���Ĺ�����ȱ���
	printf("�ڽӾ���Ĺ�����ȱ������Ϊ��\n") ;
	for(int i=1; i<=G->NumVertexes; i++)
		visited[i]=false;
	printf("%c",G->vex[1]);
	for(int i=1; i<=G->NumVertexes; i++ ) { //iȡֵ��Χһ����    
		for(int j=i+1; j<=G->NumVertexes; j++) {
			if(G->arcs[i][j]==1&&visited[j]==false) {
				visited[j]=true;
				printf("%c",G->vex[j]);
			}
		}
	}
	printf("\n");
}

