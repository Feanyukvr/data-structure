#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 10   //
typedef struct {
	char data[MAXSIZE];
	int  i;
} StrAssign;

void InitQueue(StrAssign *&q) { //
	q=( StrAssign*)malloc(sizeof( StrAssign));
	q->i=0;
}
void give(StrAssign *q) {
	q->data[0]= {15};
	q->data[1]= {'a'};
	q->data[2]= {'b'};
	q->data[3]= {'a'};
	q->data[4]= {'b'};
	q->data[5]= {'a'};
	q->data[6]= {'b'};
	q->data[7]= {'c'};
	q->data[8]= {'a'};
	q->data[9]= {'b'};
	q->data[10]= {'a'};
	q->data[11]= {'b'};
	q->data[12]= {'a'};
	q->data[13]= {'b'};
	q->data[14]= {'a'};
	q->data[15]= {'b'};
}
void gave(StrAssign *q) {
	q->data[0]= {8};
	q->data[1]= {'a'};
	q->data[2]= {'b'};
	q->data[3]= {'a'};
	q->data[4]= {'b'};
	q->data[5]= {'a'};
	q->data[6]= {'b'};
	q->data[7]= {'a'};
	q->data[8]= {'b'};
}
void PrintList(StrAssign *q) {    //���˳��������е�Ԫ��
	int i;
	for(i=1; i<=q->data[0]; i++)
		printf("%c  ",q->data[i]);
	printf("\n");
}

int inDexBF(StrAssign *s,StrAssign *t) {//�����ַ���λ�÷���һ
	int i=1,j=1,a;
	a=s->data[0];
	while(a>=t->data[0]) {
		printf("i=%d ",i);
		printf("j=%d\n",j);
		while(s->data[i]==t->data[j]) {
			if(j==t->data[0]) {
				return i-j+1;
			} else {
				j++;
				i++;
			}
		}
		a--;
		i=i-j+2;
		j=1;
	}
	printf("������\n");
	return 10;
}


int next(StrAssign *t,int e) {    // //�����ַ���λ�÷����� next��������
	int m=1,n=2;
	while(n<e) {
		if(t->data[m]==t->data[n]) {
			m++;
			n++;
		} else {
			n++;
		}
	}
	return m;
}

int inDexKMPnext(StrAssign *s,StrAssign *t) {
	int i=1,j=1,a;
	a=s->data[0];
	while(a>=t->data[0]) {
		printf("i=%d ",i);
		printf("j=%d\n",j);
		while(s->data[i]==t->data[j]) {
			if(j==t->data[0]) {
				return i-j+1;
			} else {
				i++;
				j++;
			}
		}
		if(j==1)//j����1��Ҫi���Ų
			i++;
		j=next(t,j);
		a--;
	}
	printf("������\n");
	return 0;
}
void getnext(StrAssign *t,int next[]) {//�����ַ���λ�÷��������غ���
	for(int i=1; i<=t->data[0]; i++) {
		int m=1,n=2;
		while(n<i) {
			if(t->data[m]==t->data[n]) {
				m++;
				n++;
			} else {
				n++;
			}
		}
		next[i]=m;
	}
}

void getnextval(StrAssign *t,int next[]) {
	int i,j;
	for(i=1; i<=t->data[0]; i++) {
		j=next[i];
		if(t->data[i]==t->data[j]) {
			next[i]=next[j];
		}
	}
}

int inDexKMPnextval(StrAssign *s,StrAssign *t) {
	int next[t->data[0]];
	int nextval[t->data[0]];
	getnext(t, next);
	getnextval(t,next);
	int i=1,j=1,a;
	a=s->data[0];
	while(a>=t->data[0]) {
		printf("i=%d ",i);
		printf("j=%d\n",j);
		while(s->data[i]==t->data[j]) {
			if(j==t->data[0]) {
				return i-j+1;
			} else {
				i++;
				j++;
			}
		}
		if(j==1)//
			i++;	//j����1��Ҫi���Ų
		j=next[j];
		a--;
	}
	printf("������\n");
	return 0;
}

int main() {
	int pos,a,b=1;
	StrAssign *q,*t;
	InitQueue(q);
	give(q);
	PrintList(q);

	InitQueue(t);
	gave(t);
	PrintList(t);//��ֵ�����

	pos=inDexBF(q,t);//�����ַ���λ��
	printf("pos=%d\n",pos);//����ַ���λ��
	printf("\n");
	pos=inDexKMPnext(q,t);//�����ַ���λ��
	printf("pos=%d\n",pos);//����ַ���λ��
	printf("\n");
	pos=inDexKMPnextval(q,t);//�����ַ���λ��
	printf("pos=%d\n",pos);//����ַ���λ��
	return 0;
}
