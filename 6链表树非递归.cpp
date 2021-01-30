//�������Ķ�������ʾ
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<malloc.h>
#include<stack>    //ջ��ͷ�ļ�
#define DataType char
#define MAXSIZE 100
typedef struct Node {
	DataType data;
	struct Node *lchild,*rchild;
} BiTree;

void CreateBiTree2(BiTree *&bi) { //�ǵݹ鹹�������
	BiTree *q[MAXSIZE];
	BiTree *s;
	char n;
	int i,j;
	cout<<"��������������ڵ�ı�ź�ֵ:"<<endl;
	cin>>i>>n;
	while(i!=0&&n!='$') {
		s=(BiTree*)malloc(sizeof(BiTree));  //����һ���ڵ�
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
		cout<<"��������������ڵ�ı�ź�ֵ:"<<endl;
		cin>>i>>n;
	}
	bi=q[1];
}



void PreOrder2(BiTree *bt) { //�ǵݹ�ǰ�����������
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

void InOrder2(BiTree *bt) { //�ǵݹ��������������
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

void PostOrder2(BiTree *bt) { //�ǵݹ�������������
	stack<BiTree*> s;
	BiTree *cur;     //��ǰ���
	BiTree *pre=NULL;     //ǰһ�η��ʵĽ��
	s.push(bt);
	while(!s.empty()) {
		cur=s.top();
		if(cur->lchild==NULL&&cur->rchild==NULL||(pre!=NULL&&(pre==cur->lchild||pre==cur->rchild))) {
			cout<<cur->data;  //�����ǰ���û�к��ӻ��ߺ��ӽ�㶼�Ѿ������ʹ���
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
void LeverOrder(BiTree *bt) { //��α���  �ö��������в�α���
	BiTree *q[MAXSIZE],*p;
	int front=0,rear=0;      //����front��rearΪ���е�ͷ��β��ָ�롱
	if(bt!=NULL) {           //��������Ϊ�գ�����������
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
void LeafNum(BiTree *bt,int &count) { //����Ҷ���ĸ���
	if(bt!=NULL) {
		if(bt->lchild==NULL&&bt->rchild==NULL)  //�����Ϊ��Ҷ��ʱ��count++
			count++;
		LeafNum(bt->lchild,count);
		LeafNum(bt->rchild,count);
	}
}
void NodeNum(BiTree *bt,int &count) { //���������������
	if(bt!=NULL) {
		count++;
		NodeNum(bt->lchild,count);
		NodeNum(bt->rchild,count);
	}
}
int BiTreeDepth(BiTree *bt) { //������������
	int ldep,rdep;          //�����������ͱ��������Դ���������������
	if(bt==NULL)            //����Ϊ���򷵻�0
		return 0;
	else {
		ldep=BiTreeDepth(bt->lchild);    //�ݹ�ͳ��bt�������������
		rdep=BiTreeDepth(bt->rchild);    //�ݹ�ͳ��bt�������������
		if(ldep>rdep)                    //���������������
			return ldep+1;
		else
			return rdep+1;
	}
}

BiTree *Search(BiTree *bt,DataType x) {
	if(bt->data==x) return bt;  //�����Ҹ��ڵ�ɹ��������أ�����ֱ���������������
	if(bt->lchild!=NULL)
		return (Search(bt->lchild,x)); //��bt->lchildΪ���ڵ�ָ��Ķ������в�������Ԫ��x
	if(bt->rchild!=NULL)
		return (Search(bt->rchild,x)); //��bt->rchildΪ���ڵ�ָ��Ķ������в�������Ԫ��x
	return NULL;  //����ʧ�ܷ���
}
int main() {

	BiTree *bt;         //���÷ǵݹ�
	CreateBiTree2(bt);

	cout<<endl<<"�������Ϊ:"<<endl;
	PreOrder2(bt);
	cout<<endl<<"�������Ϊ:"<<endl;
	InOrder2(bt);
	cout<<endl<<"�������Ϊ:"<<endl;
	PostOrder2(bt);
	cout<<endl<<"��α���Ϊ:"<<endl;
	LeverOrder(bt);
	
	int count=0;
	LeafNum(bt,count);
	cout<<endl<<"��Ҷ�����Ϊ:"<<count<<endl;
	count=0;
	NodeNum(bt,count);
	cout<<endl<<"�������������Ϊ:"<<count<<endl; 
	count=BiTreeDepth(bt);
	cout<<endl<<"�����������Ϊ:"<<count<<endl;

	BiTree *p;
	char x='a';
	p=Search(bt,x);
	cout<<p->data;

		return 0;
	}
