#include<iostream>
#include<queue>
#include<stdlib.h>
#include<malloc.h>

#define MAXLEN 100
using namespace std;
typedef char DataType;
bool visited[MAXLEN]; 
typedef struct{
	DataType vex[MAXLEN];     //顶点表 
	int arcs[MAXLEN][MAXLEN];    //邻接矩阵，可以看作表 
	int NumVertexes,NumEdges;    //图中当前的顶点数和边数 
}Graph;
void CreateGraph(Graph *&G){
	G=(Graph*)malloc(sizeof(Graph));     //为结构体对象创建空间 
	int i,j,k;
	
	cout<<"图的顶点数为："<<endl;
	cin>>G->NumVertexes; 
	
	cout<<"图的边数为："<<endl;
	cin>>G->NumEdges; 
	
	cout<<"输入顶点信息："<<endl; 
	for(i=1;i<=G->NumVertexes;i++) 
	cin>>G->vex[i]; //读入顶点信息
	
	for(i=1;i<=G->NumVertexes;i++)
	for(j=1;j<=G->NumVertexes;j++) 
	G->arcs[i][j]=0;            //邻接矩阵初始化
	
	/*for(i=1;i<=G->NumVertexes;i++)
	for(j=1;j<=G->NumVertexes;j++) 
	G->arcs[i][j]=-1;  */          //有权值的邻接矩阵初始化
	
	for(k=1;k<=G->NumEdges;k++){                  //读入e条边   这时为无向图 
		cout<<"读入边："<<endl; 
		cin>>i>>j;
		G->arcs[i][j]=1;
		G->arcs[j][i]=1;
		
	/*  cout<<"读入边和权值："<<endl;   //当为有权值的图时 
	    int w;
		cin>>i>>j>>w;
		G->arcs[i][j]=w;
		G->arcs[j][i]=w;	    
	*/	
	 } 
/*	 for(k=1;k<=G->NumEdge;k++)             //读入e条边   这时为有向图 
	 {
	 cout<<"读入边："<<endl; 
	 	cin>>i>>j;
	 	G->arcs[i][j]=1;
	 	
//	 cout<<"读入边和权值："<<endl;   //当为有权值的图时 
//	    int w;
//		cin>>i>>j>>w;
//		G->arcs[i][j]=w;	    
	
	 }*/ 
}
void PrintGraph(Graph *G)
{
	cout<<"图的邻接矩阵为："<<endl; 
	for(int i=1;i<=G->NumVertexes;i++)
	{
		for(int j=1;j<=G->NumVertexes;j++)
		cout<<G->arcs[i][j]<<" ";
		cout<<endl;
	}
}
//深度优先遍历（邻接矩阵） 
void DFS(Graph *G,int i)    
{
	visited[i]=true;
	
	cout<<G->vex[i];
	
	for(int j=1;j<=G->NumVertexes;j++)
	if(G->arcs[i][j]==1&&!visited[j])
	DFS(G,j); 
}
//邻接矩阵的深度优先遍历操作 
void DFSTraverse(Graph *G)
{
	cout<<"邻接矩阵的深度优先遍历结果为："<<endl;
	 
	for(int i=1;i<=G->NumVertexes;i++)
	visited[i]=false;      //初始化所有的顶点状态都是未访问的状态
	
	for(int i=1;i<=G->NumVertexes;i++)
	if(!visited[i])        //对未访问过的顶点调用DFS，若是连通图，只会执行一次 
	DFS(G,i); 
	cout<<endl;
}
//邻接矩阵的广度优先遍历 
void BFSTraverse(Graph *G)
{
	cout<<"邻接矩阵的广度优先遍历结果为："<<endl;
	
	queue<int> q;           //定义一个队列q 
	
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
