//二叉树的二叉链表示
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXSIZE 100
typedef struct Node {
	char data;
	struct Node *leftChild,*rightChild;
} biTree;

void createbiTree(biTree *&bt) ; //递归构造二叉树

void preOrder(biTree *bt); //递归前序遍历二叉树
void inOrder(biTree *bt); //递归中序遍历二叉树
void postOrder(biTree *bt); //递归后序遍历二叉树
void leverOrder(biTree *bt); //层次遍历  用队列来进行层次遍历

void leafNum(biTree *bt,int &count);  //求树叶结点的个数
void nodeNum(biTree *bt,int &count);  //求二叉树结点的总数
void Search(biTree *bt,char x);//查找数字
int biTreeDepth(biTree *bt);  //求二叉树的深度

void SearchOh(biTree *bt,char x) ;

int main() {
	biTree *bt;        //采用递归构造函数
	createbiTree(bt);
	printf("ok!\n");

	printf("先序遍历为:");
	preOrder(bt);
	printf("\n");
	printf("中序遍历为:");
	inOrder(bt);
	printf("\n");
	printf("后序遍历为:");
	postOrder(bt);
	printf("\n");
	printf("层次遍历为:");
	leverOrder(bt);
	printf("\n");

	int count=0;
	leafNum(bt,count);
	printf("树叶结点数为:%d\n",count);
	count=0;
	nodeNum(bt,count);
	printf("二叉树结点总数为:%d\n",count);
	count=biTreeDepth(bt);
	printf("二叉树的深度为:%d\n",count);

	return 0;
}

void createbiTree(biTree *&bt) { //递归构造二叉树
	char ch;
	ch=getchar();
	if(ch=='.')
		bt=NULL;
	else {
		bt=(biTree*)malloc(sizeof(biTree));
		bt->data=ch;
		createbiTree((bt->leftChild));
		createbiTree((bt->rightChild));
	}

}

void preOrder(biTree *bt) { //递归前序遍历二叉树
	if(bt!=NULL) {
		printf("%c",bt->data);
		preOrder(bt->leftChild);
		preOrder(bt->rightChild);
	}
}

void inOrder(biTree *bt) { //递归中序遍历二叉树
	if(bt!=NULL) {
		inOrder(bt->leftChild);
		printf("%c",bt->data);
		inOrder(bt->rightChild);
	}
}

void postOrder(biTree *bt) { //递归后序遍历二叉树
	if(bt!=NULL) {
		postOrder(bt->leftChild);
		postOrder(bt->rightChild);
		printf("%c",bt->data);
	}

}

void leverOrder(biTree *bt) { //层次遍历  用队列来进行层次遍历
	biTree *q[MAXSIZE],*p;
	int front=0,rear=1;      //定义front、rear为队列的头和尾“指针”
	if(bt!=NULL) {           //二叉树不为空，根结点入队列
		q[rear]=bt;
	}
	while(front!=rear) {
		front=(front+1)%MAXSIZE;
		p=q[front];
		printf("%c",p->data);
		if(p->leftChild!=NULL) {
			rear=(rear+1)%MAXSIZE;
			q[rear]=p->leftChild;
		}
		if(p->rightChild!=NULL) {
			rear=(rear+1)%MAXSIZE;
			q[rear]=p->rightChild;
		}
	}
}

void leafNum(biTree *bt,int &count) { //求树叶结点的个数
	if(bt!=NULL) {
		if(bt->leftChild==NULL&&bt->rightChild==NULL)  //当结点为树叶的时候，count++
			count++;
		leafNum(bt->leftChild,count);
		leafNum(bt->rightChild,count);
	}
}

void nodeNum(biTree *bt,int &count) { //求二叉树结点的总数
	if(bt!=NULL) {
		count++;
		nodeNum(bt->leftChild,count);
		nodeNum(bt->rightChild,count);
	}
}

int biTreeDepth(biTree *bt) { //求二叉树的深度
	int ldep=0,rdep=0;          //定义两个整型变量，用以存放左、右子树的深度
	if(bt==NULL)            //若树为空则返回0
		return 0;
	else {
		ldep=biTreeDepth(bt->leftChild);    //递归统计bt的左子树的深度
		rdep=biTreeDepth(bt->rightChild);   //递归统计bt的右子树的深度
		return  ldep>rdep?ldep+1:rdep+1;//返回深度最大的子树
	}
}

void Search(biTree *bt,char x) {
	if(bt->data==x)
		printf("找到了%c\n",bt->data);  //若查找根节点成功，即返回，否则分别在左右子树查找
	else {
		if(bt->leftChild!=NULL)
			return (Search(bt->leftChild,x)); //在bt->leftChild为根节点指针的二叉树中查找数据元素x
		else {
			if(bt->rightChild!=NULL)
				return (Search(bt->rightChild,x)); //在bt->rightChild为根节点指针的二叉树中查找数据元素x
			else
				printf("没有%c\n",x);  //查找失败返回
		}
	}
}

void SearchOh(biTree *bt,char x) {
	if(bt->data!=NULL) {
		if(bt->data==x) {
			printf("找到了%c\n",bt->data);
		} else {
			SearchOh(bt->leftChild,x);
			SearchOh(bt->rightChild,x);
		}
	} else
		printf("没有%c\n",x);
}

void LeafCount_CSTree(biTree *bt) {
	if(!)
}






