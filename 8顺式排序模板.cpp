#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXLEN 11    // 定义顺序表的最大长度MAXLEN为4 
typedef struct {
	int key;
	int otherinfo;
} RedType;

typedef struct {    //定义节点
	RedType r[MAXLEN];
	int length;    //length用来记录当前线性表中最后一个元素的数组中的位置，即length起到了指针的作用
} SqList;

SqList* InitList() { //初始化顺序表的函数
	SqList* L;
	L = new SqList;
	L->length = 0;   //初始化的时候顺序表为空，定义一个头结点
	L->r[0].key=0;
	return L;
}

void ListInsert(SqList* L, int i, int x) { //对顺序表进行插入，i是插入的位置，x是插入的数据
	int j;
	if (L->length == MAXLEN-1) {//首先判断顺序表是否已满，如果满了的话，则return -1
		printf("顺序表已满！\n");
	} else if (i<1 || i>L->length+1) {    //判断插入位置是否正确
		printf("插入位置出错！\n");
	} else {
		for (j = L->length; j >= i; j--)
			L->r[j+1].key =L->r[j].key;
		L->r[i].key = x;
		L->length++;
		printf("插入%d到%d位\n",x,i);
	}
}

void PrintList(SqList* L) {    //输出顺序表中所有的元素
	int i;
	for (i = 0; i < L->length+1; i++)
		printf("%3d", L->r[i].key);
	printf("\n");
}

void InsertSort(SqList *L) { //直接插入排序
	int i,j;
	for(i=2; i<=L->length; i++) {
		L->r[0]=L->r[i];
		for(j=i-1; L->r[0].key<=L->r[j].key; j--)
			L->r[j+1]=L->r[j];
		L->r[j+1]=L->r[0];
	}
}

void BlnsertSort(SqList *L) { //折半寻找插入排序
	int i,j,low,high,m;
	for(i=2; i<=L->length; i++) {
		L->r[0]=L->r[i];
		low=1;
		high=i-1;
		while(low<=high) {
			m=(low+high)/2;
			if(L->r[0].key<L->r[m].key)
				high=m-1;
			else low=m+1;
		}
		for(j=i-1; j>=high+1; j--)
			L->r[j+1]=L->r[j];
		L->r[high+1]=L->r[0];
	}
}
/*
void ShellInsert(SqList *L,int dk) {//希尔排序 希尔表，8，4，2，1以1结尾 
	for(i=dk+1; i<=L.length; i++)
		if(L->r[i].key<L->r[i-dk].key) {
			L->r[0]=L->r[i];
			for(j=i-dk; j>0&&(L->r[0].key<L->r[j].key); j=j-dk)
				L->r[j+dk]=L->r[j];
			L->r[j+dk]=L->r[0];
		}
}

void ShellSort(SqList *L,int dlta[],int t) {
	for(k=0; k<t; k++)
		ShellInsert(L,dlta[k]);
}



void Paopao(SqList *L){//起泡法没写完  起泡法进化版 
	int i,j;
	L->r[].key;
	L->length;
}
*/

int Partiton(SqList *L,int low,int high) { //快速排序法
	int pivotkey;
	L->r[0]=L->r[low];
	pivotkey=L->r[low].key;
	while(low<high) {
		while(low<high&&L->r[high].key>=pivotkey)
			high--;
		L->r[low]=L->r[high];
		while(low<high&&L->r[low].key<=pivotkey)
			low++;
		L->r[high]=L->r[low];
	}
	L->r[low]=L->r[0];
	return low;
}
void QSort(SqList *L,int low,int high) {
	int pivotloc;
	if(low<high) {
		pivotloc=Partiton(L,low,high);
		QSort(L,low,pivotloc-1);
		QSort(L,pivotloc+1,high);
	}
}

void SelsctSort(SqList *L) { //简单选择排序法
	int i,j,k;
	for(i=1; i<L->length; i++) {
		k=i;
		for(j=i+1; j<=L->length; j++)
			if(L->r[j].key<L->r[k].key)
				k=j;
		if(k!=i) {
			L->r[0]=L->r[i];
			L->r[i]=L->r[k];
			L->r[k]=L->r[0];
		}
	}
}


int main() {
	SqList* A;
	A = InitList();
	ListInsert(A, 1, 78);
	ListInsert(A, 2, 45);
	ListInsert(A, 3, 58);
	ListInsert(A, 4, 32);
	ListInsert(A, 5, 99);
	ListInsert(A, 6, 56);
	ListInsert(A, 7, 21);
	ListInsert(A, 8, 36);
	ListInsert(A, 9, 10);
	PrintList(A);
	SelsctSort(A);

	PrintList(A);
}

