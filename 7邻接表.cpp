#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#include<queue>
#define MAXLEN 100
using namespace std;
typedef char DataType;
bool visited[MAXLEN];
typedef struct EdgeNode{   //边结点 
	int adjvex;            //邻接点在顶点数组中的下标 
	struct EdgeNode *next;//链域  指向下一个邻接点 
}EdgeNode;
 
typedef struct VertexNode{   //头结点 
	DataType data;  //顶点信息
	EdgeNode *firstEdge; //边表头指针（指向第一条依附于该顶点的弧的指针） 
}VertexNode; 
 
typedef struct Graph{       
	VertexNode adjList[MAXLEN];   
	int numVertexes,numEdges;  //图中当前的结点数及边数 
}Graph;
void CreateGraph(Graph *&G)   //建立无向图的邻接表 
{
//	if(G==NULL)
	G=(Graph*)malloc(sizeof(Graph));
	
	cout<<"输入图的顶点数："<<endl;
	cin>>G->numVertexes;
	
	cout<<"输入图的边数："<<endl;
	cin>>G->numEdges;
	
	cout<<"输入各个顶点的数据："<<endl;
	for(int i=1;i<=G->numVertexes;i++)
	{
		cout<<"顶点"<<i<<":"<<endl;
		cin>>G->adjList[i].data;
		G->adjList[i].firstEdge=NULL; 
	 } 
	 
	 for(int k=1;k<=G->numEdges;k++)
	 {
	 	int i,j;
	 	cout<<"输入(vi,vj)上的顶点序号："<<endl;
		cin>>i>>j;
		
		EdgeNode *p,*t;
		
		p=(EdgeNode*)malloc(sizeof(EdgeNode));
		if(G->adjList[i].firstEdge!=NULL)
		{
			t=G->adjList[i].firstEdge;
			while(t->next!=NULL)
			t=t->next;
			p->adjvex=j; p->next=NULL; t->next=p;
		}
		else
		{
			p->adjvex=j; p->next=G->adjList[i].firstEdge; G->adjList[i].firstEdge=p;
		}
		
		
		p=(EdgeNode*)malloc(sizeof(EdgeNode));
		if(G->adjList[j].firstEdge!=NULL)
		{
			t=G->adjList[j].firstEdge;
			while(t->next!=NULL)
			t=t->next;
			p->adjvex=i;p->next=NULL;t->next=p; 
		}
		else
		{
			p->adjvex=i; p->next=G->adjList[j].firstEdge; G->adjList[j].firstEdge=p;
		}
		
	 }
}
//深度优先遍历算法
void DFS(Graph *G,int i)
{
	visited[i]=true;
	cout<<G->adjList[i].data;
	
	EdgeNode *p=G->adjList[i].firstEdge;
	
	while(p)
	{
		if(!visited[p->adjvex])
		DFS(G,p->adjvex);
		p=p->next;
	}
 } 
 
void DFSTraverse(Graph *G)
{
	cout<<"深度优先遍历的结果为："<<endl; 
	
	for(int i=1;i<=G->numVertexes;i++)
	visited[i]=false;       //初始化访问数组visited的元素值为false
	
	for(int i=1;i<=G->numVertexes;i++)
	if(!visited[i])     //结点尚未访问 
	{
		DFS(G,i); 
	 }
	 
	 cout<<endl; 
}
//广度优先遍历算法
void BFSTraverse(Graph *G)
{
	cout<<"广度优先遍历的结果为："<<endl; 
	queue<int>q;
	for(int i=1;i<=G->numVertexes;i++)
	visited[i]=false;
	
	for(int i=1;i<=G->numVertexes;i++)
	{
		if(!visited[i])
		{
			visited[i]=true;
			cout<<G->adjList[i].data;
			q.push(i);
			
			while(!q.empty())
			{
				EdgeNode *p=G->adjList[q.front()].firstEdge;
				q.pop();
				while(p)
				{
					if(!visited[p->adjvex])
					{
						visited[p->adjvex]=true;
						cout<<G->adjList[p->adjvex].data;
						q.push(p->adjvex);
					}
					p=p->next;
				}
			}
		}
	}
	cout<<endl;
 } 
int main()
{
	Graph *G;
	CreateGraph(G);
	
	DFSTraverse(G);
	
	BFSTraverse(G);
}
