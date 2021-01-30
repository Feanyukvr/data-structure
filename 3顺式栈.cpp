#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct Node {   //����ջ
	ElemType data[MAXSIZE];
	int top;
} SqStack;

void *InitStack(SqStack *&s)  ;//ջ�ĳ�ʼ��
int StackEmpty(SqStack *s);  //��ջ��ʱ����1�����򷵻�0
void PushStack(SqStack *s,ElemType x) ;//��ջ��������ջδ����ʱ����ջ
void GetTopStack(SqStack *s) ; //��ȡջ��Ԫ�ز���
ElemType PopStack(SqStack *s)  ; //��ջ��������ջ��Ϊ����ɾ��ջ��Ԫ��
void ClearStack(SqStack *s); //ջ�ÿղ���
void StackLength(SqStack *s) ;   //ջ����

int main() {
	SqStack *s;
	InitStack(s);
	PushStack(s,1);
	PushStack(s,2);
	PushStack(s,3);

	GetTopStack(s);//��ȡջ��Ԫ�ز���
	PopStack(s); //��ջ��������ջ��Ϊ����ɾ��ջ��Ԫ��
	GetTopStack(s);//��ȡջ��Ԫ�ز���
	StackLength(s);//��ջ��ʱ����1�����򷵻�0
	ClearStack(s);
	StackLength(s);
	return 0;
}

void *InitStack(SqStack *&s) { //ջ�ĳ�ʼ��
	s=(SqStack*)malloc(sizeof(SqStack));  //����һ
//	s=new SqStack;                           ������
	s->top=-1;
}

int StackEmpty(SqStack *s) { //��ջ��ʱ����1�����򷵻�0
	if(s->top==-1)
		return 1;
	else
		return 0;
}

void PushStack(SqStack *s,ElemType x) { //��ջ��������ջδ����ʱ����ջ
	if(s->top==MAXSIZE-1)
		printf("Stack full\n");
	else {
		s->top++;
		s->data[s->top]=x;
	}
}

void GetTopStack(SqStack *s) { //��ȡջ��Ԫ�ز���
	ElemType x;
	if(StackEmpty(s)) {
		printf("Stack empty.\n");
	} else {
		x=s->data[s->top];
		printf("%d\n",x);
	}
}

ElemType PopStack(SqStack *s) { //��ջ��������ջ��Ϊ����ɾ��ջ��Ԫ��
	ElemType x;
	if(StackEmpty(s)) {       //�ж�ջ�Ƿ�Ϊ��
		printf("Stack Empty\n");
		return NULL;
	} else {
		x=s->data[s->top];
		s->top--;
		return x;
	}
}

void ClearStack(SqStack *s) { //ջ�ÿղ���
	s->top=-1;
}

void StackLength(SqStack *s) {    //���ȳ���
	printf("stack length is %d\n",s->top+1);
}

