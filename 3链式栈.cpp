#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node {      //����ṹ��
	int data;
	struct Node* next;
}LinkStack;

void InitStack(LinkStack*& top);//��ʼ��ջ��ջΪ�գ�topָ���
int StackEmpty(LinkStack* top);//   ����Ƿ�Ϊ��
void PushStack(LinkStack*& top, int x);//ǰ��������
void GetTopStack(LinkStack* top); //���ջ1
void PopStack(LinkStack*& top); // ����һλ
void StackLength(LinkStack* top);//�������
void ClearStack(LinkStack*& top); //��ձ�


int main()
{
	LinkStack* top;

	InitStack(top); //��ʼ��ջ��ջΪ�գ�topָ���

	StackLength(top);//�������

	PushStack(top, 1);//ǰ��������
	PushStack(top, 2);//ǰ��������
	PushStack(top, 3);//ǰ��������

	GetTopStack(top); //���ջ1

	PopStack(top);// ����һλ
	GetTopStack(top); //���ջ1

	ClearStack(top);  //��ձ�
	StackLength(top);//�������

}





void InitStack(LinkStack*& top)  //��ʼ��ջ��ջΪ�գ�topָ���
{
	top = NULL;
}


int StackEmpty(LinkStack* top) //   ����Ƿ�Ϊ��
{
	if (top == NULL)
		return 1;
	else
		return 0;
}
void PushStack(LinkStack*& top, int x) //ǰ��������
{
	LinkStack* p;
	p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = x;
	p->next = top;
	top = p;
}


void GetTopStack(LinkStack* top) //���ջ1
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
void PopStack(LinkStack*& top)  // ����һλ
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
void StackLength(LinkStack* top) //�������
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

void ClearStack(LinkStack*& top)  //��ձ�
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