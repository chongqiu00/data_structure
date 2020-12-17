/*
* -----------------------------------------------------------------
*  ʱ�䣺2020/10/13 18:36
* ------------------------------------------------------------------
* ���ܣ�������Ĵ������������жϿգ����㳤�ȣ������㣬ɾ����㣬����
* ------------------------------------------------------------------
* ��������ɾ��Ҫ��д�����򷽷�Ҫȫ����ʵ�֡�
* ---------------------------------------------------------------------
* 
*/

//ͷ�ļ�
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

//�ṹ��
typedef struct Node
{
	int data;//������
	struct Node* pNext;//��ַ��
}NODE,*PNODE;//   struct Node <==> NODE, struct Node* <==> PNODE

//��������
PNODE CreateList(void);//����
void TraverList(PNODE pHead);//����
bool IsEmpty(PNODE pHead);//�жϿ�
int LengthList(PNODE pHead);//���㳤��
bool InsertList(PNODE pHead, int pos, int val);//������
bool DeleteList(PNODE pHead, int pos,int* pval);//ɾ�����
void SortList(PNODE pHead);//����
GetList();

//������
int main(void)
{
	PNODE arry = CreateList();
	TraverList(arry);
  //LengthList(arry);
  //InsertList(arry, 2, 999);
	//int* a;
	//int i;
	//a = &i;
	//DeleteList(arry, 2, a);
	SortList(arry);
	TraverList(arry);

	return 0;
}

//�Ӻ�����ʵ��
PNODE CreateList(void)
{
	int length;
	int i;
	int val;

	PNODE pHead = (PNODE*)malloc(sizeof(NODE) * 1);
		if (NULL == pHead->pNext)
		{
			printf_s("�����ڴ�ʧ�ܣ�\n");
			exit(-1);
		}//����һ��ͷ���

	PNODE pTail = (PNODE*)malloc(sizeof(NODE)*1);
	if (NULL == pHead->pNext)
	{
		printf_s("�����ڴ�ʧ�ܣ�\n");
		exit(-1);
	}//����һ��������

	pTail = pHead;

	printf_s("����Ҫ�����ĵ������ȣ�lenght = ");
	scanf_s("%d", &length);

	for (i = 0; i < length; i++)
	{
		printf_s("������ĵ�һ���������Ϊ��");
		scanf_s("%d", &val);

		PNODE pNew = (PNODE*)malloc(sizeof(NODE) * 1);
		if (NULL == pHead->pNext)
		{
			printf_s("�����ڴ�ʧ�ܣ�\n");
			exit(-1);
		}//����һ���½��

		pNew->data = val;
		pTail->pNext = pNew;//������ָ���½��
		pNew->pNext = NULL;//�½����ʱΪ�����β���
		pTail = pNew;//�����㴦���½��λ��
	}

	return pHead;
}

void TraverList(PNODE pHead)
{
	if (IsEmpty(pHead))
	{
		printf_s("�������ޱ���Ԫ�أ�\n");
		exit(-1);
	}
	else
	{
		PNODE p;
		p = pHead->pNext;
		printf_s("�����������\n");
		while (NULL != p)
		{
			printf_s("%d\n",p->data);
			p = p->pNext;
		}

		return;
	}
}

bool IsEmpty(PNODE pHead)
{
	if (pHead->pNext == NULL)
	{
		printf_s("������Ϊ�գ�\n");
		return true;
	}
	else
	{
		return false;
	}
}

int  LengthList(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int num = 0;

	if (IsEmpty(pHead))
	{
		return;
	}
	else
	{
		while (NULL != p)
		{
			++num;
			p = p->pNext;
		}
		printf_s("������ĳ���Ϊ��%d\n",num);
		return num;
	}
}

bool InsertList(PNODE pHead, int pos, int val)//�ڵ�pos�����ǰ�����val
{
	int i = 0;
	int j = 0;
	PNODE p = pHead;
	PNODE q;

	while (NULL != p && i < pos - 1)
	{
		p = p->pNext;
		++i;
	}
	if (i > pos - 1 || p == NULL)
	{
		return false;
	}
	else
	{
		PNODE pNew = (PNODE*)malloc(sizeof(NODE) * 1);
		if (NULL == pHead->pNext)
		{
			printf_s("�����ڴ�ʧ�ܣ�\n");
			exit(-1);
		}//����һ���½��
		pNew->data = val;
		q = p->pNext;
		p->pNext = pNew;
		pNew->pNext = q;

		return true;
	}
}

bool DeleteList(PNODE pHead, int pos, int* pval)//ɾ����pos�����
{
	int i = 0;
	PNODE p = pHead;

	while (NULL != p->pNext && i < pos - 1)
	{
		p = p->pNext;
		++i;
	}
	if (NULL == p->pNext && i > pos - 1)
	{
		return false;
	}

	PNODE q = p->pNext;
	*pval = p->data;

	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;
}

void SortList(PNODE pHead)
{
	int i = 0;
	int j = 0;
	int t;
	PNODE p,q;
	int len = LengthList(pHead);

	for(i=0, p = pHead->pNext; i<len-1; i++,p->pNext)
		for (j = i+1,q = p->pNext; j < len; j++, q=q->pNext)
		{
			if (p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
}

