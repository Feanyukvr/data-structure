#include<iostream>
#include<queue>
#include<stdlib.h>
#include<malloc.h>

#define MAXLEN 100
using namespace std;
typedef char DataType;
bool visited[MAXLEN]; 
typedef struct{
	DataType vex[MAXLEN];     //����� 
	int arcs[MAXLEN][MAXLEN];    //�ڽӾ��󣬿��Կ����� 
	int NumVertexes,NumEdges;    //ͼ�е�ǰ�Ķ������ͱ��� 
}Graph;
void CreateGraph(Graph *&G){
	G=(Graph*)malloc(sizeof(Graph));     //Ϊ�ṹ����󴴽��ռ� 
	int i,j,k;
	
	cout<<"ͼ�Ķ�����Ϊ��"<<endl;
	cin>>G->NumVertexes; 
	
	cout<<"ͼ�ı���Ϊ��"<<endl;
	cin>>G->NumEdges; 
	
	cout<<"���붥����Ϣ��"<<endl; 
	for(i=1;i<=G->NumVertexes;i++) 
	cin>>G->vex[i]; //���붥����Ϣ
	
	for(i=1;i<=G->NumVertexes;i++)
	for(j=1;j<=G->NumVertexes;j++) 
	G->arcs[i][j]=0;            //�ڽӾ����ʼ��
	
	/*for(i=1;i<=G->NumVertexes;i++)
	for(j=1;j<=G->NumVertexes;j++) 
	G->arcs[i][j]=-1;  */          //��Ȩֵ���ڽӾ����ʼ��
	
	for(k=1;k<=G->NumEdges;k++){                  //����e����   ��ʱΪ����ͼ 
		cout<<"����ߣ�"<<endl; 
		cin>>i>>j;
		G->arcs[i][j]=1;
		G->arcs[j][i]=1;
		
	/*  cout<<"����ߺ�Ȩֵ��"<<endl;   //��Ϊ��Ȩֵ��ͼʱ 
	    int w;
		cin>>i>>j>>w;
		G->arcs[i][j]=w;
		G->arcs[j][i]=w;	    
	*/	
	 } 
/*	 for(k=1;k<=G->NumEdge;k++)             //����e����   ��ʱΪ����ͼ 
	 {
	 cout<<"����ߣ�"<<endl; 
	 	cin>>i>>j;
	 	G->arcs[i][j]=1;
	 	
//	 cout<<"����ߺ�Ȩֵ��"<<endl;   //��Ϊ��Ȩֵ��ͼʱ 
//	    int w;
//		cin>>i>>j>>w;
//		G->arcs[i][j]=w;	    
	
	 }*/ 
}
void PrintGraph(Graph *G)
{
	cout<<"ͼ���ڽӾ���Ϊ��"<<endl; 
	for(int i=1;i<=G->NumVertexes;i++)
	{
		for(int j=1;j<=G->NumVertexes;j++)
		cout<<G->arcs[i][j]<<" ";
		cout<<endl;
	}
}
//������ȱ������ڽӾ��� 
void DFS(Graph *G,int i)    
{
	visited[i]=true;
	
	cout<<G->vex[i];
	
	for(int j=1;j<=G->NumVertexes;j++)
	if(G->arcs[i][j]==1&&!visited[j])
	DFS(G,j); 
}
//�ڽӾ����������ȱ������� 
void DFSTraverse(Graph *G)
{
	cout<<"�ڽӾ����������ȱ������Ϊ��"<<endl;
	 
	for(int i=1;i<=G->NumVertexes;i++)
	visited[i]=false;      //��ʼ�����еĶ���״̬����δ���ʵ�״̬
	
	for(int i=1;i<=G->NumVertexes;i++)
	if(!visited[i])        //��δ���ʹ��Ķ������DFS��������ͨͼ��ֻ��ִ��һ�� 
	DFS(G,i); 
	cout<<endl;
}
//�ڽӾ���Ĺ�����ȱ��� 
void BFSTraverse(Graph *G)
{
	cout<<"�ڽӾ���Ĺ�����ȱ������Ϊ��"<<endl;
	
	queue<int> q;           //����һ������q 
	
	for(int i=1;i<=G->NumVertexes;i++)      
	visited[i]=false;
	
	for(int i=1;i<=G->NumVertexes;i++)
	{
		if(!visited[i])
		{
			visited[i]=true;
			cout<<G->vex[i];
			q.push(i);
			while(!q.empty())
			{
				int t;
				t=q.front();
				q.pop();
				for(int j=1;j<=G->NumVertexes;j++)	{
					if(G->arcs[t][j]==1&&!visited[j])
					{
						visited[j]=true;
						cout<<G->vex[j];
						q.push(j);
					}
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
	PrintGraph(G);
	DFSTraverse(G);
	BFSTraverse(G);
 } 
