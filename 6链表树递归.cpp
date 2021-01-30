//�������Ķ�������ʾ
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXSIZE 100
typedef struct Node {
	char data;
	struct Node *leftChild,*rightChild;
} biTree;

void createbiTree(biTree *&bt) ; //�ݹ鹹�������

void preOrder(biTree *bt); //�ݹ�ǰ�����������
void inOrder(biTree *bt); //�ݹ��������������
void postOrder(biTree *bt); //�ݹ�������������
void leverOrder(biTree *bt); //��α���  �ö��������в�α���

void leafNum(biTree *bt,int &count);  //����Ҷ���ĸ���
void nodeNum(biTree *bt,int &count);  //���������������
void Search(biTree *bt,char x);//��������
int biTreeDepth(biTree *bt);  //������������

void SearchOh(biTree *bt,char x) ;

int main() {
	biTree *bt;        //���õݹ鹹�캯��
	createbiTree(bt);
	printf("ok!\n");

	printf("�������Ϊ:");
	preOrder(bt);
	printf("\n");
	printf("�������Ϊ:");
	inOrder(bt);
	printf("\n");
	printf("�������Ϊ:");
	postOrder(bt);
	printf("\n");
	printf("��α���Ϊ:");
	leverOrder(bt);
	printf("\n");

	int count=0;
	leafNum(bt,count);
	printf("��Ҷ�����Ϊ:%d\n",count);
	count=0;
	nodeNum(bt,count);
	printf("�������������Ϊ:%d\n",count);
	count=biTreeDepth(bt);
	printf("�����������Ϊ:%d\n",count);

	return 0;
}

void createbiTree(biTree *&bt) { //�ݹ鹹�������
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

void preOrder(biTree *bt) { //�ݹ�ǰ�����������
	if(bt!=NULL) {
		printf("%c",bt->data);
		preOrder(bt->leftChild);
		preOrder(bt->rightChild);
	}
}

void inOrder(biTree *bt) { //�ݹ��������������
	if(bt!=NULL) {
		inOrder(bt->leftChild);
		printf("%c",bt->data);
		inOrder(bt->rightChild);
	}
}

void postOrder(biTree *bt) { //�ݹ�������������
	if(bt!=NULL) {
		postOrder(bt->leftChild);
		postOrder(bt->rightChild);
		printf("%c",bt->data);
	}

}

void leverOrder(biTree *bt) { //��α���  �ö��������в�α���
	biTree *q[MAXSIZE],*p;
	int front=0,rear=1;      //����front��rearΪ���е�ͷ��β��ָ�롱
	if(bt!=NULL) {           //��������Ϊ�գ�����������
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

void leafNum(biTree *bt,int &count) { //����Ҷ���ĸ���
	if(bt!=NULL) {
		if(bt->leftChild==NULL&&bt->rightChild==NULL)  //�����Ϊ��Ҷ��ʱ��count++
			count++;
		leafNum(bt->leftChild,count);
		leafNum(bt->rightChild,count);
	}
}

void nodeNum(biTree *bt,int &count) { //���������������
	if(bt!=NULL) {
		count++;
		nodeNum(bt->leftChild,count);
		nodeNum(bt->rightChild,count);
	}
}

int biTreeDepth(biTree *bt) { //������������
	int ldep=0,rdep=0;          //�����������ͱ��������Դ���������������
	if(bt==NULL)            //����Ϊ���򷵻�0
		return 0;
	else {
		ldep=biTreeDepth(bt->leftChild);    //�ݹ�ͳ��bt�������������
		rdep=biTreeDepth(bt->rightChild);   //�ݹ�ͳ��bt�������������
		return  ldep>rdep?ldep+1:rdep+1;//���������������
	}
}

void Search(biTree *bt,char x) {
	if(bt->data==x)
		printf("�ҵ���%c\n",bt->data);  //�����Ҹ��ڵ�ɹ��������أ�����ֱ���������������
	else {
		if(bt->leftChild!=NULL)
			return (Search(bt->leftChild,x)); //��bt->leftChildΪ���ڵ�ָ��Ķ������в�������Ԫ��x
		else {
			if(bt->rightChild!=NULL)
				return (Search(bt->rightChild,x)); //��bt->rightChildΪ���ڵ�ָ��Ķ������в�������Ԫ��x
			else
				printf("û��%c\n",x);  //����ʧ�ܷ���
		}
	}
}

void SearchOh(biTree *bt,char x) {
	if(bt->data!=NULL) {
		if(bt->data==x) {
			printf("�ҵ���%c\n",bt->data);
		} else {
			SearchOh(bt->leftChild,x);
			SearchOh(bt->rightChild,x);
		}
	} else
		printf("û��%c\n",x);
}

void LeafCount_CSTree(biTree *bt) {
	if(!)
}






