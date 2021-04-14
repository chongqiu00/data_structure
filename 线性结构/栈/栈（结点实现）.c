/*
* 第一次编写
* 
* 创建时间：2020/10/14 20:07
* 功能：动态分配内存，实现栈的形式存储，（创建，判断空，进栈，出栈，清空）
* 完成时间：22：00
* 
*/

//头文件
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

//结构体
typedef struct Node
{
	int data;
	struct Node* pNext;
}NODE, *PNODE;//结点

typedef struct Stack
{
	PNODE pTop;
	PNODE pBotton;
}STACK, *PSTACK;//栈顶，栈底

//函数声明
void InitStack(PSTACK pS);
bool IsEmpty(PSTACK pS);
void Push(PSTACK pS, int val);
bool Pop(PSTACK pS, int* pval);
void clear(PSTACK pS);
void Traverse(PSTACK pS);

//主函数
int main(void)
{
	STACK s;
	InitStack(&s);
	Push(&s, 1);
	Push(&s, 2);
	//clear(&s);
	Push(&s, 3);
	Push(&s, 4);
	Push(&s, 5);
	int* i;
	int a;
	i = &a;
	//Pop(&s, i);
	Traverse(&s);
	return 0;
}
//子函数的实现
void InitStack(PSTACK pS)
{
	 pS->pBotton = (PNODE)malloc(sizeof(NODE) * 1);
	 if (NULL == pS->pBotton)
	 {
		 printf_s("内存分配失败！\n");
		 exit(-1);
	 }
	 else
	 {
		 pS->pTop = pS->pBotton;
		 pS->pTop->pNext = NULL;
	 }

	 return;
}

bool IsEmpty(PSTACK pS)
{
	if (pS->pTop == pS->pBotton)
	{
		printf_s("栈空！\n");
		return true;
	}
	else
	{
		return false;
	}
}

void Push(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE) * 1);
	if (NULL == pNew)
	{
		printf_s("内存分配失败！\n");
		exit(-1);
	}
	else
	{
		pNew->data = val;
		pNew->pNext = pS->pTop;
		pS->pTop = pNew;
		 printf_s("入栈成功！\n");
	}
	return;
}

bool Pop(PSTACK pS, int * pval)
{
	if (IsEmpty(pS))
	{
		printf_s("无出栈元素！\n\n\n");
		return false;
	}
	else
	{
		PNODE r = pS->pTop;
		*pval = r->data;
		pS->pTop = r->pNext;
		free(r);
		r = NULL;
		printf_s("出栈成功！\n");
		return true;
	}
}

void clear(PSTACK pS)
{
	if (IsEmpty(pS))
	{
		printf_s("无清空元素！\n\n\n");
	}
	else
	{
		PNODE p = pS->pTop;
		PNODE q = NULL;
		while (p != pS->pBotton)
		{
			q = p->pNext;
			free(p);
			p = q;
			printf_s("清空成功!\n");
			return;
		}

	}
}

void Traverse(PSTACK pS)
{
	if ( IsEmpty(pS) )
	{
		printf_s("无元素遍历！\n");
	}
	else
	{
		printf_s("遍历元素为：\n");
		PNODE p = pS->pTop;
		while (p != pS->pBotton)
		{
			printf_s("%d\n", p->data);
			p = p->pNext;
		}
	}
	return;
}