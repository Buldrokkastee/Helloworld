#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LinkNode
{
	ElemType data;
	struct LinkNode* next;
}LinkNode;

typedef struct
{
	LinkNode* front;
	LinkNode* rear;
}LinkQueue;

void InitQueue(LinkQueue&Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue& Q, ElemType e);
bool DeQueue(LinkQueue& Q, ElemType& e);

void InitQueue(LinkQueue&Q)
{
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
	{
		printf("栈为空\n");
		return true;
	}
	return false;
}

void EnQueue(LinkQueue &Q, ElemType e)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = e;
	s->next = NULL;
	Q.rear->next = s;//让头结点的next存储下一个元素的地址
	Q.rear = s;
}

bool DeQueue(LinkQueue& Q,ElemType &e)
{
	if (Q.front == Q.rear)
	{
		return false;
	}
	LinkNode* p = Q.front->next;//用p存储队头节点
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
	{
		Q.front = Q.rear;
	}
	free(p);
}

int main()
{
	ElemType elem;
	LinkQueue Q;
	InitQueue(Q);
	IsEmpty(Q);
	EnQueue(Q,1);
	EnQueue(Q,2);
	EnQueue(Q,3);
	EnQueue(Q,4);
	DeQueue(Q,elem);
	printf("%d出队列\n", elem);
	DeQueue(Q, elem);
	printf("%d出队列\n", elem);
	DeQueue(Q, elem);
	printf("%d出队列\n", elem);
}
