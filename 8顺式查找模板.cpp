#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXLEN 5    // ����˳������󳤶�MAXLENΪ4 
typedef struct {
	int key;
	int otherinfo;
} RedType;

typedef struct {    //����ڵ�
	RedType r[MAXLEN];
	int lenght;        //last������¼��ǰ���Ա������һ��Ԫ�ص������е�λ�ã���last����ָ�������
} SqList;

SqList* InitList() { //��ʼ��˳���ĺ���
	SqList* L;
	L = new SqList;
	L->lenght = 0;   //��ʼ����ʱ��˳���Ϊ�գ�����һ��ͷ���
	L->r[0].key=0;
	return L;
}

void ListInsert(SqList* L, int i, int x) { //��˳�����в��룬i�ǲ����λ�ã�x�ǲ��������
	int j;
	if (L->lenght == MAXLEN-1) {
		//�����ж�˳����Ƿ�������������˵Ļ�����return -1
		printf("˳���������\n");
	} else if (i<1 || i>L->lenght+1) {    //�жϲ���λ���Ƿ���ȷ
		printf("����λ�ó���\n");
	} else {
		for (j = L->lenght; j >= i; j--)
			L->r[j+1].key =L->r[j].key;
		L->r[i].key = x;
		L->lenght++;
		printf("����%d��%dλ\n",x,i);
	}
}

void PrintList(SqList* L) {    //���˳��������е�Ԫ��
	int i;
	for (i = 1; i < L->lenght+1; i++)
		printf("%d  ", L->r[i].key);
	printf("\n");
}



//�۰���� 
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

