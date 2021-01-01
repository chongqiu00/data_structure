/*
* ��һ�α�д
* 
* ����ʱ�䣺2020/10/14 20:07
* ���ܣ���̬�����ڴ棬ʵ��ջ����ʽ�洢�����������жϿգ���ջ����ջ����գ�
* ���ʱ�䣺22��00
* 
*/

//ͷ�ļ�
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

//�ṹ��
typedef struct Node
{
	int data;
	struct Node* pNext;
}NODE, *PNODE;//���

typedef struct Stack
{
	PNODE pTop;
	PNODE pBotton;
}STACK, *PSTACK;//ջ����ջ��

//��������
void InitStack(PSTACK pS);
bool IsEmpty(PSTACK pS);
void Push(PSTACK pS, int val);
bool Pop(PSTACK pS, int* pval);
void clear(PSTACK pS);
void Traverse(PSTACK pS);

//������
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
//�Ӻ�����ʵ��
void InitStack(PSTACK pS)
{
	 pS->pBotton = (PNODE)malloc(sizeof(NODE) * 1);
	 if (NULL == pS->pBotton)
	 {
		 printf_s("�ڴ����ʧ�ܣ�\n");
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
		printf_s("ջ�գ�\n");
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
		printf_s("�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	else
	{
		pNew->data = val;
		pNew->pNext = pS->pTop;
		pS->pTop = pNew;
		 printf_s("��ջ�ɹ���\n");
	}
	return;
}

bool Pop(PSTACK pS, int * pval)
{
	if (IsEmpty(pS))
	{
		printf_s("�޳�ջԪ�أ�\n\n\n");
		return false;
	}
	else
	{
		PNODE r = pS->pTop;
		*pval = r->data;
		pS->pTop = r->pNext;
		free(r);
		r = NULL;
		printf_s("��ջ�ɹ���\n");
		return true;
	}
}

void clear(PSTACK pS)
{
	if (IsEmpty(pS))
	{
		printf_s("�����Ԫ�أ�\n\n\n");
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
			printf_s("��ճɹ�!\n");
			return;
		}

	}
}

void Traverse(PSTACK pS)
{
	if ( IsEmpty(pS) )
	{
		printf_s("��Ԫ�ر�����\n");
	}
	else
	{
		printf_s("����Ԫ��Ϊ��\n");
		PNODE p = pS->pTop;
		while (p != pS->pBotton)
		{
			printf_s("%d\n", p->data);
			p = p->pNext;
		}
	}
	return;
}