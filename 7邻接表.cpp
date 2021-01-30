#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#include<queue>
#define MAXLEN 100
using namespace std;
typedef char DataType;
bool visited[MAXLEN];
typedef struct EdgeNode{   //�߽�� 
	int adjvex;            //�ڽӵ��ڶ��������е��±� 
	struct EdgeNode *next;//����  ָ����һ���ڽӵ� 
}EdgeNode;
 
typedef struct VertexNode{   //ͷ��� 
	DataType data;  //������Ϣ
	EdgeNode *firstEdge; //�߱�ͷָ�루ָ���һ�������ڸö���Ļ���ָ�룩 
}VertexNode; 
 
typedef struct Graph{       
	VertexNode adjList[MAXLEN];   
	int numVertexes,numEdges;  //ͼ�е�ǰ�Ľ���������� 
}Graph;
void CreateGraph(Graph *&G)   //��������ͼ���ڽӱ� 
{
//	if(G==NULL)
	G=(Graph*)malloc(sizeof(Graph));
	
	cout<<"����ͼ�Ķ�������"<<endl;
	cin>>G->numVertexes;
	
	cout<<"����ͼ�ı�����"<<endl;
	cin>>G->numEdges;
	
	cout<<"���������������ݣ�"<<endl;
	for(int i=1;i<=G->numVertexes;i++)
	{
		cout<<"����"<<i<<":"<<endl;
		cin>>G->adjList[i].data;
		G->adjList[i].firstEdge=NULL; 
	 } 
	 
	 for(int k=1;k<=G->numEdges;k++)
	 {
	 	int i,j;
	 	cout<<"����(vi,vj)�ϵĶ�����ţ�"<<endl;
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
//������ȱ����㷨
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
	cout<<"������ȱ����Ľ��Ϊ��"<<endl; 
	
	for(int i=1;i<=G->numVertexes;i++)
	visited[i]=false;       //��ʼ����������visited��Ԫ��ֵΪfalse
	
	for(int i=1;i<=G->numVertexes;i++)
	if(!visited[i])     //�����δ���� 
	{
		DFS(G,i); 
	 }
	 
	 cout<<endl; 
}
//������ȱ����㷨
void BFSTraverse(Graph *G)
{
	cout<<"������ȱ����Ľ��Ϊ��"<<endl; 
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
