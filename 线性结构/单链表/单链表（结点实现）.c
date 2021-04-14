/*
* -----------------------------------------------------------------
*  时间：2020/10/13 18:36
* ------------------------------------------------------------------
* 功能：单链表的创建，遍历，判断空，计算长度，插入结点，删除结点，排序
* ------------------------------------------------------------------
* 任务：排序，删除要重写，排序方法要全部都实现。
* ---------------------------------------------------------------------
* 
*/

//头文件
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

//结构体
typedef struct Node
{
	int data;//数据域
	struct Node* pNext;//地址域
}NODE,*PNODE;//   struct Node <==> NODE, struct Node* <==> PNODE

//函数声明
PNODE CreateList(void);//创建
void TraverList(PNODE pHead);//遍历
bool IsEmpty(PNODE pHead);//判断空
int LengthList(PNODE pHead);//计算长度
bool InsertList(PNODE pHead, int pos, int val);//插入结点
bool DeleteList(PNODE pHead, int pos,int* pval);//删除结点
void SortList(PNODE pHead);//排序
GetList();

//主函数
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

//子函数的实现
PNODE CreateList(void)
{
	int length;
	int i;
	int val;

	PNODE pHead = (PNODE*)malloc(sizeof(NODE) * 1);
		if (NULL == pHead->pNext)
		{
			printf_s("分配内存失败！\n");
			exit(-1);
		}//创建一个头结点

	PNODE pTail = (PNODE*)malloc(sizeof(NODE)*1);
	if (NULL == pHead->pNext)
	{
		printf_s("分配内存失败！\n");
		exit(-1);
	}//创建一个跟随结点

	pTail = pHead;

	printf_s("您需要创建的单链表长度：lenght = ");
	scanf_s("%d", &length);

	for (i = 0; i < length; i++)
	{
		printf_s("单链表的第一个结点数据为：");
		scanf_s("%d", &val);

		PNODE pNew = (PNODE*)malloc(sizeof(NODE) * 1);
		if (NULL == pHead->pNext)
		{
			printf_s("分配内存失败！\n");
			exit(-1);
		}//创建一个新结点

		pNew->data = val;
		pTail->pNext = pNew;//跟随结点指向新结点
		pNew->pNext = NULL;//新结点暂时为链表的尾结点
		pTail = pNew;//跟随结点处在新结点位置
	}

	return pHead;
}

void TraverList(PNODE pHead)
{
	if (IsEmpty(pHead))
	{
		printf_s("单链表无遍历元素！\n");
		exit(-1);
	}
	else
	{
		PNODE p;
		p = pHead->pNext;
		printf_s("单链表遍历：\n");
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
		printf_s("单链表为空！\n");
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
		printf_s("单链表的长度为：%d\n",num);
		return num;
	}
}

bool InsertList(PNODE pHead, int pos, int val)//在第pos个结点前面插入val
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
			printf_s("分配内存失败！\n");
			exit(-1);
		}//创建一个新结点
		pNew->data = val;
		q = p->pNext;
		p->pNext = pNew;
		pNew->pNext = q;

		return true;
	}
}

bool DeleteList(PNODE pHead, int pos, int* pval)//删除第pos个结点
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

