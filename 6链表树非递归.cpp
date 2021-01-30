//二叉树的二叉链表示
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<malloc.h>
#include<stack>    //栈的头文件
#define DataType char
#define MAXSIZE 100
typedef struct Node {
	DataType data;
	struct Node *lchild,*rchild;
} BiTree;

void CreateBiTree2(BiTree *&bi) { //非递归构造二叉树
	BiTree *q[MAXSIZE];
	BiTree *s;
	char n;
	int i,j;
	cout<<"输入二叉树各个节点的编号和值:"<<endl;
	cin>>i>>n;
	while(i!=0&&n!='$') {
		s=(BiTree*)malloc(sizeof(BiTree));  //生成一个节点
		s->data=n;
		s->lchild=NULL;
		s->rchild=NULL;
		q[i]=s;
		if(i!=1) {
			j=i/2;
			if(i%2==0)
				q[j]->lchild=s;
			else
				q[j]->rchild=s;
		}
		cout<<"输入二叉树各个节点的编号和值:"<<endl;
		cin>>i>>n;
	}
	bi=q[1];
}



void PreOrder2(BiTree *bt) { //非递归前序遍历二叉树
	stack<BiTree*> s;
	BiTree *p=bt;
	while(p!=NULL||!s.empty()) {
		while(p!=NULL) {
			cout<<p->data;
			s.push(p);
			p=p->lchild;
		}
		if(!s.empty()) {
			p=s.top();
			s.pop();
			p=p->rchild;
		}
	}
}

void InOrder2(BiTree *bt) { //非递归中序遍历二叉树
	stack<BiTree*> s;
	BiTree *p=bt;
	while(p!=NULL||!s.empty()) {
		while(p!=NULL) {
			s.push(p);
			p=p->lchild;
		}
		if(!s.empty()) {
			p=s.top();
			s.pop();
			cout<<p->data;
			p=p->rchild;
		}
	}
}

void PostOrder2(BiTree *bt) { //非递归后序遍历二叉树
	stack<BiTree*> s;
	BiTree *cur;     //当前结点
	BiTree *pre=NULL;     //前一次访问的结点
	s.push(bt);
	while(!s.empty()) {
		cur=s.top();
		if(cur->lchild==NULL&&cur->rchild==NULL||(pre!=NULL&&(pre==cur->lchild||pre==cur->rchild))) {
			cout<<cur->data;  //如果当前结点没有孩子或者孩子结点都已经被访问过了
			s.pop();
			pre=cur;
		} else {
			if(cur->rchild!=NULL)
				s.push(cur->rchild);
			if(cur->lchild!=NULL)
				s.push(cur->lchild);
		}
	}
}
void LeverOrder(BiTree *bt) { //层次遍历  用队列来进行层次遍历
	BiTree *q[MAXSIZE],*p;
	int front=0,rear=0;      //定义front、rear为队列的头和尾“指针”
	if(bt!=NULL) {           //二叉树不为空，根结点入队列
		rear=(rear+1)%MAXSIZE;
		q[rear]=bt;
	}
	while(front!=rear) {
		front=(front+1)%MAXSIZE;
		p=q[front];
		cout<<p->data;
		if(p->lchild!=NULL) {
			rear=(rear+1)%MAXSIZE;
			q[rear]=p->lchild;
		}
		if(p->rchild!=NULL) {
			rear=(rear+1)%MAXSIZE;
			q[rear]=p->rchild;
		}
	}
}
void LeafNum(BiTree *bt,int &count) { //求树叶结点的个数
	if(bt!=NULL) {
		if(bt->lchild==NULL&&bt->rchild==NULL)  //当结点为树叶的时候，count++
			count++;
		LeafNum(bt->lchild,count);
		LeafNum(bt->rchild,count);
	}
}
void NodeNum(BiTree *bt,int &count) { //求二叉树结点的总数
	if(bt!=NULL) {
		count++;
		NodeNum(bt->lchild,count);
		NodeNum(bt->rchild,count);
	}
}
int BiTreeDepth(BiTree *bt) { //求二叉树的深度
	int ldep,rdep;          //定义两个整型变量，用以存放左、右子树的深度
	if(bt==NULL)            //若树为空则返回0
		return 0;
	else {
		ldep=BiTreeDepth(bt->lchild);    //递归统计bt的左子树的深度
		rdep=BiTreeDepth(bt->rchild);    //递归统计bt的右子树的深度
		if(ldep>rdep)                    //返回深度最大的子树
			return ldep+1;
		else
			return rdep+1;
	}
}

BiTree *Search(BiTree *bt,DataType x) {
	if(bt->data==x) return bt;  //若查找根节点成功，即返回，否则分别在左右子树查找
	if(bt->lchild!=NULL)
		return (Search(bt->lchild,x)); //在bt->lchild为根节点指针的二叉树中查找数据元素x
	if(bt->rchild!=NULL)
		return (Search(bt->rchild,x)); //在bt->rchild为根节点指针的二叉树中查找数据元素x
	return NULL;  //查找失败返回
}
int main() {

	BiTree *bt;         //采用非递归
	CreateBiTree2(bt);

	cout<<endl<<"先序遍历为:"<<endl;
	PreOrder2(bt);
	cout<<endl<<"中序遍历为:"<<endl;
	InOrder2(bt);
	cout<<endl<<"后序遍历为:"<<endl;
	PostOrder2(bt);
	cout<<endl<<"层次遍历为:"<<endl;
	LeverOrder(bt);
	
	int count=0;
	LeafNum(bt,count);
	cout<<endl<<"树叶结点数为:"<<count<<endl;
	count=0;
	NodeNum(bt,count);
	cout<<endl<<"二叉树结点总数为:"<<count<<endl; 
	count=BiTreeDepth(bt);
	cout<<endl<<"二叉树的深度为:"<<count<<endl;

	BiTree *p;
	char x='a';
	p=Search(bt,x);
	cout<<p->data;

		return 0;
	}
