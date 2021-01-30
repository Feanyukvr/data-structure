#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node {      //定义结构体
	int data;
	struct Node* next;
}LinkStack;

void InitStack(LinkStack*& top);//初始化栈，栈为空，top指向空
int StackEmpty(LinkStack* top);//   检查是否为空
void PushStack(LinkStack*& top, int x);//前插入数字
void GetTopStack(LinkStack* top); //输出栈1
void PopStack(LinkStack*& top); // 减少一位
void StackLength(LinkStack* top);//输出长度
void ClearStack(LinkStack*& top); //清空表


int main()
{
	LinkStack* top;

	InitStack(top); //初始化栈，栈为空，top指向空

	StackLength(top);//输出长度

	PushStack(top, 1);//前插入数字
	PushStack(top, 2);//前插入数字
	PushStack(top, 3);//前插入数字

	GetTopStack(top); //输出栈1

	PopStack(top);// 减少一位
	GetTopStack(top); //输出栈1

	ClearStack(top);  //清空表
	StackLength(top);//输出长度

}





void InitStack(LinkStack*& top)  //初始化栈，栈为空，top指向空
{
	top = NULL;
}


int StackEmpty(LinkStack* top) //   检查是否为空
{
	if (top == NULL)
		return 1;
	else
		return 0;
}
void PushStack(LinkStack*& top, int x) //前插入数字
{
	LinkStack* p;
	p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = x;
	p->next = top;
	top = p;
}


void GetTopStack(LinkStack* top) //输出栈1
{
	if (top == NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("%d\n", top->data);
	}
}
void PopStack(LinkStack*& top)  // 减少一位
{

	int x;
	LinkStack* p;
	if (top == NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		p = top;
		top = top->next;
		x = p->data;
		free(p);
	}
}
void StackLength(LinkStack* top) //输出长度
{
	int x = 0;
	LinkStack* p;
	p = top;
	while (p != NULL)
	{
		x++;
		p = p->next;
	}
	printf("Stack length is %d\n", x);
}

void ClearStack(LinkStack*& top)  //清空表
{
	LinkStack* p;
	while (top != NULL)
	{
		p = top;
		top = top->next;
		free(p);
	}
	top = NULL;
}