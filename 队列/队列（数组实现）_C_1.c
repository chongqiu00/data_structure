/*
* 时间：2020/10/15 18:14
* 功能：队列的创建，入队，出队，判断空，判断满。
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
//结构体
typedef struct queue
{
	int* pBase;
	int front;
	int rear;

}QUEUE,*PQUEUE;

//函数声明
void CreateQueue(PQUEUE pS);
bool OutQueue(PQUEUE pS, int* pVal);
bool InQueue(PQUEUE pS);
bool IsEmpty(PQUEUE pS);
bool IsFull(PQUEUE pS);
void traverse(PQUEUE pS);

int main(void)
{
	QUEUE arry;
	int a;
	CreateQueue(&arry);
	InQueue(&arry, 1);
	InQueue(&arry, 2);
	InQueue(&arry, 3);
	traverse(&arry);
	OutQueue(&arry, &a);
	traverse(&arry);

	return 0;
}

//子函数的实现
void CreateQueue(PQUEUE pS)
{
	
	pS->pBase = (int*)malloc(sizeof(int) * 10);
	if (NULL == pS->pBase)
	{
		printf_s("分配内存失败！\n");
		exit(-1);
	}
	else
	{
		pS->front = 0;
		pS->rear = 0;
	}
	
	return;
}

bool OutQueue(PQUEUE pS,int* pVal)
{
	if (IsEmpty(pS))
	{
		printf_s("无元素出队！\n");
		return false;
	}
	else
	{
		*pVal = pS->pBase[pS->front];
		pS->front = (pS->front + 1) % 10;
		printf_s("%d出队成功！\n", *pVal);
		return true;
	}
}

bool InQueue(PQUEUE pS, int Val)
{
	if (IsFull(pS))
	{
		printf_s("不可再加元素！\n");
		return false;
	}
	else
	{
		pS->pBase[pS->rear] = Val;
		pS->rear = (pS->rear + 1) % 10;
		printf_s("入队成功!\n");
		return true;
	}
}

bool IsEmpty(PQUEUE pS)
{
	if (pS->front == pS->rear)
	{
		printf_s("队列为空！\n");
		return true;
	}
	else
	{
		return false;
	}
}

bool IsFull(PQUEUE pS)
{
	if ( pS->front == (pS->rear + 1) )
	{
		printf_s("队列已满！\n");
		return true;
	}
	else
	{
		return false;
	}
}

void traverse(PQUEUE pS)
{
	int q;
	if (IsEmpty(pS))
	{
		printf_s("无遍历元素！\n");
	}
	else
	{
		q = pS->front;
		while ( q != pS->rear)
		{
			printf_s("%d\n", pS->pBase[q]);
			q =  (q + 1) % 10;
		}
	}
	
	return;
}

/*
* 结论：
* -------------------
* 入队，出队均加一
* -------------------
*/