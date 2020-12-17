/*
* ʱ�䣺2020/10/15 18:14
* ���ܣ����еĴ�������ӣ����ӣ��жϿգ��ж�����
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
//�ṹ��
typedef struct queue
{
	int* pBase;
	int front;
	int rear;

}QUEUE,*PQUEUE;

//��������
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

//�Ӻ�����ʵ��
void CreateQueue(PQUEUE pS)
{
	
	pS->pBase = (int*)malloc(sizeof(int) * 10);
	if (NULL == pS->pBase)
	{
		printf_s("�����ڴ�ʧ�ܣ�\n");
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
		printf_s("��Ԫ�س��ӣ�\n");
		return false;
	}
	else
	{
		*pVal = pS->pBase[pS->front];
		pS->front = (pS->front + 1) % 10;
		printf_s("%d���ӳɹ���\n", *pVal);
		return true;
	}
}

bool InQueue(PQUEUE pS, int Val)
{
	if (IsFull(pS))
	{
		printf_s("�����ټ�Ԫ�أ�\n");
		return false;
	}
	else
	{
		pS->pBase[pS->rear] = Val;
		pS->rear = (pS->rear + 1) % 10;
		printf_s("��ӳɹ�!\n");
		return true;
	}
}

bool IsEmpty(PQUEUE pS)
{
	if (pS->front == pS->rear)
	{
		printf_s("����Ϊ�գ�\n");
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
		printf_s("����������\n");
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
		printf_s("�ޱ���Ԫ�أ�\n");
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
* ���ۣ�
* -------------------
* ��ӣ����Ӿ���һ
* -------------------
*/