#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXLEN 10    // ����˳������󳤶�MAXLENΪ10
typedef struct {     //����ڵ�
	int data[MAXLEN];
	int last;        //last������¼��ǰ���Ա������һ��Ԫ�ص������е�λ�ã���last����ָ�������
} SeqList;

SeqList* InitList();//��ʼ��˳���ĺ���
//InitList����˳���
//DestoryList���ٱ�
//Clearist��Ϊ�ձ�
//ListEmpty��ѯ�Ƿ�Ϊ�ձ��Ƿ���1���񷵻�0
void ListLength(SeqList* L);//�������
//GetElem���λ
void ListLocate(SeqList* L, int x);//����λ//��λĳֵ�����򷵻�0
//PriorElem���ǰһλ�����򷵻�0 
//NextElem �����һλ�����򷵻�0
void ListInsert(SeqList* L, int i, int x);//����λ
void ListDelete(SeqList* L, int i);//ɾ��λ
void PrintList(SeqList* L);//�����
//�����
int SearchBin(SeqList* L, int x);//˳���۰���� //�۰���� 

int main() {
	SeqList* A;
	A = InitList();
	ListInsert(A, 1, 78);
	ListInsert(A, 2, 45);
	ListInsert(A, 3, 65);
	ListInsert(A, 4, 58);
	ListInsert(A, 3, 32);
	PrintList(A); //���l 
	ListLength(A);

	ListDelete(A, 2);
	PrintList(A); //���l

	ListLocate(A, 8);
	ListLocate(A, 78);

	return 0;
}

SeqList* InitList() { //��ʼ��˳���ĺ���
	SeqList* L;
	L = new SeqList;
	L->last = 0;      //��ʼ����ʱ��˳���Ϊ�գ�����last��ֵ����Ϊ0;
	return L;
}

void ListInsert(SeqList* L, int i, int x) { //��˳�����в��룬i�ǲ����λ�ã�x�ǲ��������
	int j;
if (L->last == MAXLEN) {    //�����ж�˳����Ƿ�������������˵Ļ�����return -1
		printf("˳���������\n");
	}
	else if (i<1 || i>L->last + 1) {      //�жϲ���λ���Ƿ���ȷ
		printf("����λ�ó���\n");
	}
	else {
		for (j = L->last; j >= i; j--)
			L->data[j] = L->data[j - 1];
		L->data[i - 1] = x;
		L->last++;
	}
}

void ListDelete(SeqList* L, int i) {  //ɾ����i��λ���ϵ�Ԫ�صĺ���
	int j;
	if (i<1 || i>L->last)
		printf("�����ڵ�%d��Ԫ�أ�\n", i);
	else {
		for (j = i; j < L->last; j++)
			L->data[j - 1] = L->data[j];
		L->last--;
		printf("��ɾ����%d��Ԫ��!\n", i);
	}
}

void PrintList(SeqList* L) {    //���˳��������е�Ԫ��
	int i;
	for (i = 0; i < L->last; i++)
		printf("%d  ", L->data[i]);
	printf("\n");
}

void ListLength(SeqList* L) {   //��˳����ȵ�Ԫ��
	printf("˳���ĳ���Ϊ��%d\n", L->last);
}

void ListLocate(SeqList* L, int x) { //����Ԫ��x���������򷵻�����λ�ã����������򷵻�-1
	int j, c = 0;
	for (j = 0; j < L->last; j++) {
		if (L->data[j] == x) {
			printf("����%d�ڵ�%d��\n", x, j + 1);
			c = 1;
			break;
		}
	}
	if (c == 0) {
		printf("����%d�Ҳ���\n", x);
	}
}

int SearchBin(SeqList* L, int x){//˳���۰���� 
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



