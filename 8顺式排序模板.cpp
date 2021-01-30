#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXLEN 11    // ����˳������󳤶�MAXLENΪ4 
typedef struct {
	int key;
	int otherinfo;
} RedType;

typedef struct {    //����ڵ�
	RedType r[MAXLEN];
	int length;    //length������¼��ǰ���Ա������һ��Ԫ�ص������е�λ�ã���length����ָ�������
} SqList;

SqList* InitList() { //��ʼ��˳���ĺ���
	SqList* L;
	L = new SqList;
	L->length = 0;   //��ʼ����ʱ��˳���Ϊ�գ�����һ��ͷ���
	L->r[0].key=0;
	return L;
}

void ListInsert(SqList* L, int i, int x) { //��˳�����в��룬i�ǲ����λ�ã�x�ǲ��������
	int j;
	if (L->length == MAXLEN-1) {//�����ж�˳����Ƿ�������������˵Ļ�����return -1
		printf("˳���������\n");
	} else if (i<1 || i>L->length+1) {    //�жϲ���λ���Ƿ���ȷ
		printf("����λ�ó���\n");
	} else {
		for (j = L->length; j >= i; j--)
			L->r[j+1].key =L->r[j].key;
		L->r[i].key = x;
		L->length++;
		printf("����%d��%dλ\n",x,i);
	}
}

void PrintList(SqList* L) {    //���˳��������е�Ԫ��
	int i;
	for (i = 0; i < L->length+1; i++)
		printf("%3d", L->r[i].key);
	printf("\n");
}

void InsertSort(SqList *L) { //ֱ�Ӳ�������
	int i,j;
	for(i=2; i<=L->length; i++) {
		L->r[0]=L->r[i];
		for(j=i-1; L->r[0].key<=L->r[j].key; j--)
			L->r[j+1]=L->r[j];
		L->r[j+1]=L->r[0];
	}
}

void BlnsertSort(SqList *L) { //�۰�Ѱ�Ҳ�������
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
void ShellInsert(SqList *L,int dk) {//ϣ������ ϣ����8��4��2��1��1��β 
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



void Paopao(SqList *L){//���ݷ�ûд��  ���ݷ������� 
	int i,j;
	L->r[].key;
	L->length;
}
*/

int Partiton(SqList *L,int low,int high) { //��������
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

void SelsctSort(SqList *L) { //��ѡ������
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

