#include "basic.h"

void InitList(struct SqList* L)
{
	L->elem = (ElemType*)malloc(sizeof(ElemType) * (LIST_INIT_SIZE));
	if (NULL == L->elem)
	{
		printf_s("内存分配失败！\n");
		exit(OVERFLOW);
	}
	else
	{
		L->length = 0;
		L->listsize = 10;
	}
	return;
}
void DestroyList(struct SqList* L)//顺序表的存储是一片内存单元所组成的，释放时，只需将头地址释放即可
{

	free(L->elem);
	L->elem = NULL;
	L->length = 0;
	L->listsize = 0;
	return;
}
void ClearList(struct SqList* L)
{
	L->length = 0;
	return;
}
status ListEmpty(struct SqList* L)//为空返回1，不空返回0
{
	if (0 == L->length)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
int ListLength(struct SqList* L)
{
	return (L->length);
}
status GetList(struct SqList* L, int i, ElemType* e)
{
	//判断i是否合法
	if (i < 1 && i > L->length)
	{
		printf_s("i为非法数据\n");
		return ERROR;
	}
	else
	{
		*e = L->elem[i - 1];
		return OK;
	}
}
status PriorElem(struct SqList* L, ElemType cur_e, ElemType* pre_e)
{
	int i = 2;//从下标为1开始遍历
	ElemType* p = L->elem + 1;
	while ((i <= L->length) && (cur_e != *p))
	{
		p++;
		i++;
	}
	if (i > L->length)
	{
		return INFEASIBLE;
	}
	else
	{
		*pre_e = *--p;
		return OK;

	}
}
status NextElem(struct SqList* L, ElemType cur_e, ElemType* next_e)
{
	int i = 1;
	ElemType* p = L->elem;
	while (i < L->length && cur_e != *p)
	{
		i++;
		p++;
	}
	if (i < (L->length - 1))
	{
		*next_e = *++p;
		return OK;
	}
	else
	{
		return INFEASIBLE;
	}
}
void ListTraverse(struct SqList* L, void (*vi)(ElemType* e))
{
	ElemType* p = L->elem;
	int i;
	for (i = 0; i < L->length; i++)
	{
		vi(p++);

	}
	return;
}
status ListInsert(struct SqList* L, int i, ElemType e)
{
	ElemType* p = L->elem + L->length - 1;
	ElemType* q = L->elem + i - 1;
	//判断I值是否合法
	if (i < 1 || i > L->length + 1)
	{
		return ERROR;
	}
	else
	{
		//考虑是否需要添加内存空间
		if (L->length == L->listsize)
		{
			ElemType* newbase = (ElemType*)realloc(L->elem, (L->listsize + LIST_INCREMENT) * sizeof(ElemType));
			if (NULL == newbase)
			{
				printf_s("分配内存失败！\n");
				exit(OVERFLOW);
			}
			L->elem = newbase;
			L->listsize = L->listsize + LIST_INCREMENT;
		}//添加内存成功
		for (; p >= q; --p)
		{
			*(p + 1) = *p;
		}
		*q = e;
		++L->length;
	}
	return OK;
}
status ListDelete(struct SqList* L, int i, ElemType* e)
{
	ElemType* p = L->elem + L->length - 1;
	ElemType* q = L->elem + i - 1;
	//判断删除位置是否合法
	if (L->length == 0)
	{
		printf_s("顺序表为空！\n");
		return ERROR;
	}
	else
	{
		*e = *q;
		for (; q <= p; ++q)
		{
			*q = *(q + 1);
		}
		--L->length;
		return OK;
	}
}
status LocteElem(struct SqList* L, ElemType e, status(*compare)(ElemType, ElemType))
{
	ElemType* p = L->elem;
	int i = 1;
	while (i <= L->length && !compare(*p++, e))
	{
		++i;
	}
	if (i <= L->length)
	{
		return i;
	}
	else
	{
		return 0;
	}

}
