#include<stdio.h>
#include<malloc.h>
#include<queue>
#define MAXLEN 100
bool visited[MAXLEN];
typedef struct {
	char vex[MAXLEN];     //顶点表
	int arcs[MAXLEN][MAXLEN];    //邻接矩阵，可以看作表
	int NumVertexes,NumEdges;    //图中当前的顶点数和边数
} Graph;

void CreateGraph(Graph *&G) ;//建立无向图邻接表
void PrintGraph(Graph *G);   //输出邻接矩阵
void DFSTraverse(Graph *G) ;//深度优先遍历（邻接矩阵）
void BFSTraverse(Graph *G) ; //广度遍历邻接矩阵图

int main() {
	Graph *G;
	CreateGraph(G);
	PrintGraph(G);
	DFSTraverse(G);
	BFSTraverse(G);
}

void CreateGraph(Graph *&G){
	G=(Graph*)malloc(sizeof(Graph));//为结构体对象创建空间
	int i,j,k,c=1;
	printf("图的顶点数为: ");
	while(c==1) {
		scanf("%d",&G->NumVertexes);
		if(G->NumVertexes>0&&G->NumVertexes<=100)
			c=0;
		else
			printf("love you:");
	}
	printf("图的边数为：");
	while(c==0) {
		scanf("%d",&G->NumEdges);
		if(G->NumEdges>=G->NumVertexes-1&&G->NumEdges<=G->NumVertexes*(G->NumVertexes-1)/2)
			c=1;
		else
			printf("love you:");
	}
	for(i=1; i<=G->NumVertexes; i++){//读入顶点信息
		G->vex[i]=getchar();
		printf("输入%d顶点信息：",i);
		G->vex[i]=getchar();
	}
	
	
		for(i=1; i<=G->NumVertexes; i++)//邻接矩阵初始化
		for(j=1; j<=G->NumVertexes; j++)
			G->arcs[i][j]=0;
	for(k=1; k<=G->NumEdges; k++){  //读入e条边   这时为无向图
		printf("输入边：");
		scanf("%d,%d",&i,&j);
		G->arcs[i][j]=1;
		G->arcs[j][i]=1;
	}
}

void PrintGraph(Graph *G) {
	printf("图的邻接矩阵为：\n");
	for(int i=1; i<=G->NumVertexes; i++) {
		for(int j=1; j<=G->NumVertexes; j++)
			printf("%d",G->arcs[i][j]);
		printf("\n");
	}
}

void DFS(Graph *G,int i) {//深度优先遍历（邻接矩阵）
	visited[i]=true;
	printf("%c",G->vex[i]) ;
	for(int j=1; j<=G->NumVertexes; j++)
		if(G->arcs[i][j]==1&&!visited[j])
			DFS(G,j);
}

void DFSTraverse(Graph *G) {
	printf("邻接矩阵的深度优先遍历结果为：\n") ;
	for(int i=1; i<=G->NumVertexes; i++)
		visited[i]=false;      //初始化所有的顶点状态都是未访问的状态
	for(int i=1; i<=G->NumVertexes; i++)
		if(!visited[i])        //对未访问过的顶点调用DFS，若是连通图，只会执行一次
			DFS(G,i);
	printf("\n") ;
}


typedef struct node { //定义单链表的节点
	char data;
	struct node *next;
} LinkList;

LinkList *CreateList() { //初始化一个循环链表
	LinkList *rear,*head;
	head = (LinkList*)malloc(sizeof(LinkList));
	rear=head;
	rear->next=head;
	return head;
}



char front(LinkList *head) {//输出删除首位数字
	LinkList *p;
	p=head->next;
	return p->data;
}
void pop(LinkList *head) {//去头 
	LinkList *p;
	p=head->next;
	head->next=head->next->next;
	free(p);
}

int QueueLength(LinkList *head) { //求长度
	LinkList *p;
	int n=0;
	p=head;
	while(head!=p->next) {
		p=p->next;
		n++;
	}
	return n;
}

void push(LinkList *head,char x) { //尾插元素x
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

void BFSTraverse(Graph *G) { //邻接矩阵的广度优先遍历
	printf("邻接矩阵的广度优先遍历结果为：\n") ;
	for(int i=1; i<=G->NumVertexes; i++)
		visited[i]=false;
	printf("%c",G->vex[1]);
	for(int i=1; i<=G->NumVertexes; i++ ) { //i取值范围一到三    
		for(int j=i+1; j<=G->NumVertexes; j++) {
			if(G->arcs[i][j]==1&&visited[j]==false) {
				visited[j]=true;
				printf("%c",G->vex[j]);
			}
		}
	}
	printf("\n");
}

