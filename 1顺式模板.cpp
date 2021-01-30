#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXLEN 10    // 定义顺序表的最大长度MAXLEN为10
typedef struct {     //定义节点
	int data[MAXLEN];
	int last;        //last用来记录当前线性表中最后一个元素的数组中的位置，即last起到了指针的作用
} SeqList;

SeqList* InitList();//初始化顺序表的函数
//InitList创建顺序表
//DestoryList销毁表
//Clearist置为空表
//ListEmpty查询是否为空表是返回1，否返回0
void ListLength(SeqList* L);//输出表长度
//GetElem输出位
void ListLocate(SeqList* L, int x);//查找位//定位某值，无则返回0
//PriorElem输出前一位，无则返回0 
//NextElem 输出后一位，无则返回0
void ListInsert(SeqList* L, int i, int x);//插入位
void ListDelete(SeqList* L, int i);//删除位
void PrintList(SeqList* L);//输出表
//排序表
int SearchBin(SeqList* L, int x);//顺序折半查找 //折半查找 

int main() {
	SeqList* A;
	A = InitList();
	ListInsert(A, 1, 78);
	ListInsert(A, 2, 45);
	ListInsert(A, 3, 65);
	ListInsert(A, 4, 58);
	ListInsert(A, 3, 32);
	PrintList(A); //输出l 
	ListLength(A);

	ListDelete(A, 2);
	PrintList(A); //输出l

	ListLocate(A, 8);
	ListLocate(A, 78);

	return 0;
}

SeqList* InitList() { //初始化顺序表的函数
	SeqList* L;
	L = new SeqList;
	L->last = 0;      //初始化的时候顺序表为空，所以last的值设置为0;
	return L;
}

void ListInsert(SeqList* L, int i, int x) { //对顺序表进行插入，i是插入的位置，x是插入的数据
	int j;
if (L->last == MAXLEN) {    //首先判断顺序表是否已满，如果满了的话，则return -1
		printf("顺序表已满！\n");
	}
	else if (i<1 || i>L->last + 1) {      //判断插入位置是否正确
		printf("插入位置出错！\n");
	}
	else {
		for (j = L->last; j >= i; j--)
			L->data[j] = L->data[j - 1];
		L->data[i - 1] = x;
		L->last++;
	}
}

void ListDelete(SeqList* L, int i) {  //删除第i个位置上的元素的函数
	int j;
	if (i<1 || i>L->last)
		printf("不存在第%d个元素！\n", i);
	else {
		for (j = i; j < L->last; j++)
			L->data[j - 1] = L->data[j];
		L->last--;
		printf("已删除第%d个元素!\n", i);
	}
}

void PrintList(SeqList* L) {    //输出顺序表中所有的元素
	int i;
	for (i = 0; i < L->last; i++)
		printf("%d  ", L->data[i]);
	printf("\n");
}

void ListLength(SeqList* L) {   //求顺序表长度的元素
	printf("顺序表的长度为：%d\n", L->last);
}

void ListLocate(SeqList* L, int x) { //搜索元素x，若存在则返回它的位置，若不存在则返回-1
	int j, c = 0;
	for (j = 0; j < L->last; j++) {
		if (L->data[j] == x) {
			printf("数字%d在第%d个\n", x, j + 1);
			c = 1;
			break;
		}
	}
	if (c == 0) {
		printf("数字%d找不到\n", x);
	}
}

int SearchBin(SeqList* L, int x){//顺序折半查找 
	int low =0,high=L->last;
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(x==L->data[mid])
		return mid;
		else if(x<L->data[mid])
		high=mid-1;
		else low=mid+1;
	}
}



