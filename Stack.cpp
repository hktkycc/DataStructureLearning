#include <iostream>
using namespace std;

typedef struct StackNode
{
	int data;
	StackNode* next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;

StackNode *initNode()
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = 0;
	return p;
}

LinkStack *initStack()
{
	LinkStack *s = (LinkStack*)malloc(sizeof(StackNode));
	StackNode* p = initNode();
	s->top = p;
	s->count = 1;
	return s;
}

void StackPush(LinkStack* S, int data)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = data;
	s->next = S->top;
	S->top = s;
	S->count++;
}

int StackEmpty(LinkStack* S)
{
	if (S->count == 1)
	{
		return 1;
	}
	else
		return 0;
}

int StackPop(LinkStack* S)
{
	LinkStackPtr p = 0;
	if (StackEmpty(S))
		cout << "Stack empty";
	int data = S->top->data;
	p = S->top;
	S->top = S->top->next;
	free(p);
	S->count--;
	return data;
}

void ShowStack(LinkStack* S)
{
	LinkStack* p = S;
	int i = p->count;
	while (i != 1)
	{
		cout << p->top->data << "\n";
		p->top = p->top->next;
		i--;
	}
}

int fbi(int data)
{
	if (data < 2)
		return data == 0 ? 0 : 1;
	return fbi(data - 1) + fbi(data - 2);
}

int main()
{
	LinkStack* S = initStack();
	for (int i = 1; i < 10; i++)
		StackPush(S, i);
	for (int j = 0; j < 3; j++)
		int data = StackPop(S);
	cout << "Stack is here:\n";
	ShowStack(S);

	cout << "Fibonacci is here:\n";
	int i;
	for (i = 0; i < 40; i++)
		cout << fbi(i) << " ";

}
