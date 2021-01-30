#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXLEN 5    // 定义顺序表的最大长度MAXLEN为4 
typedef struct {
	int key;
	int otherinfo;
} RedType;

typedef struct {    //定义节点
	RedType r[MAXLEN];
	int lenght;        //last用来记录当前线性表中最后一个元素的数组中的位置，即last起到了指针的作用
} SqList;

SqList* InitList() { //初始化顺序表的函数
	SqList* L;
	L = new SqList;
	L->lenght = 0;   //初始化的时候顺序表为空，定义一个头结点
	L->r[0].key=0;
	return L;
}

void ListInsert(SqList* L, int i, int x) { //对顺序表进行插入，i是插入的位置，x是插入的数据
	int j;
	if (L->lenght == MAXLEN-1) {
		//首先判断顺序表是否已满，如果满了的话，则return -1
		printf("顺序表已满！\n");
	} else if (i<1 || i>L->lenght+1) {    //判断插入位置是否正确
		printf("插入位置出错！\n");
	} else {
		for (j = L->lenght; j >= i; j--)
			L->r[j+1].key =L->r[j].key;
		L->r[i].key = x;
		L->lenght++;
		printf("插入%d到%d位\n",x,i);
	}
}

void PrintList(SqList* L) {    //输出顺序表中所有的元素
	int i;
	for (i = 1; i < L->lenght+1; i++)
		printf("%d  ", L->r[i].key);
	printf("\n");
}



//折半查找 
int main() {
	SqList* A;
	A = InitList();
	ListInsert(A, 1, 78);
	PrintList(A);
	ListInsert(A, 2, 45);
	PrintList(A);
	ListInsert(A, 4, 58);
	PrintList(A);
	ListInsert(A, 3, 32);
	PrintList(A);
	ListInsert(A, 2, 65);
	PrintList(A);




	PrintList(A);
}

