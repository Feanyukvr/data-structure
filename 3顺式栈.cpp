#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct Node {   //定义栈
	ElemType data[MAXSIZE];
	int top;
} SqStack;

void *InitStack(SqStack *&s)  ;//栈的初始化
int StackEmpty(SqStack *s);  //当栈空时返回1，否则返回0
void PushStack(SqStack *s,ElemType x) ;//入栈操作，当栈未满的时候入栈
void GetTopStack(SqStack *s) ; //读取栈顶元素操作
ElemType PopStack(SqStack *s)  ; //出栈操作，若栈不为空则删除栈顶元素
void ClearStack(SqStack *s); //栈置空操作
void StackLength(SqStack *s) ;   //栈长度

int main() {
	SqStack *s;
	InitStack(s);
	PushStack(s,1);
	PushStack(s,2);
	PushStack(s,3);

	GetTopStack(s);//读取栈顶元素操作
	PopStack(s); //出栈操作，若栈不为空则删除栈顶元素
	GetTopStack(s);//读取栈顶元素操作
	StackLength(s);//当栈空时返回1，否则返回0
	ClearStack(s);
	StackLength(s);
	return 0;
}

void *InitStack(SqStack *&s) { //栈的初始化
	s=(SqStack*)malloc(sizeof(SqStack));  //方法一
//	s=new SqStack;                           方法二
	s->top=-1;
}

int StackEmpty(SqStack *s) { //当栈空时返回1，否则返回0
	if(s->top==-1)
		return 1;
	else
		return 0;
}

void PushStack(SqStack *s,ElemType x) { //入栈操作，当栈未满的时候入栈
	if(s->top==MAXSIZE-1)
		printf("Stack full\n");
	else {
		s->top++;
		s->data[s->top]=x;
	}
}

void GetTopStack(SqStack *s) { //读取栈顶元素操作
	ElemType x;
	if(StackEmpty(s)) {
		printf("Stack empty.\n");
	} else {
		x=s->data[s->top];
		printf("%d\n",x);
	}
}

ElemType PopStack(SqStack *s) { //出栈操作，若栈不为空则删除栈顶元素
	ElemType x;
	if(StackEmpty(s)) {       //判断栈是否为空
		printf("Stack Empty\n");
		return NULL;
	} else {
		x=s->data[s->top];
		s->top--;
		return x;
	}
}

void ClearStack(SqStack *s) { //栈置空操作
	s->top=-1;
}

void StackLength(SqStack *s) {    //长度炒作
	printf("stack length is %d\n",s->top+1);
}

