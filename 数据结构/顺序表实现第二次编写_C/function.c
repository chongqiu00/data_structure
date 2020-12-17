#include "function.h"

Status InitList(PSqList pL)
{
	pL->pelem = (ElemType*)malloc(sizeof(ElemType) * INIT_SIZE_LIST);
	if (NULL == pL)
	{
		printf_s("内存分配失败！\n");
		return (OVERFLOW);
	}
	else
	{
		pL->length = 0;
		pL->listsize = INIT_SIZE_LIST;
		return OK;
	}
		


}
Status ListInsert(PSqList pL, int i, ElemType e)
{
	ElemType* p, *q;
	p = pL->pelem + i - 1;
	q = pL->pelem + pL->length - 1;
	if (i < 1 || i > pL->length + 1)
	{
		printf_s("顺序表无第%位\n",i);
	}
	else
	{
		if (pL->listsize <= pL->length)
		{
			ElemType* pnewL;
			pnewL = (ElemType*)realloc(pL->pelem, (pL->listsize + LIST_INCREMENT)*sizeof(ElemType));
			if (NULL == pnewL)
			{
				printf_s("扩建表的内存失败！\n");
				return (OVERFLOW);
			}
			else
			{
				pL->pelem = pnewL;
				pL->listsize = LIST_INCREMENT + pL->listsize;
				printf_s("L->length = %d L->listsize = %d\n", pL->length, pL->listsize);
			}
		}
			while (i < (pL->length + 1) )
			{
				*(q + 1) = *q;
				--q;
				++i;
			}
			*p = e;
			pL->length += 1;
			return OK;
	}
}
Status ListDelete(PSqList pL, int i, ElemType* pe)
{
	ElemType* p, * q;
	p = pL->pelem + i - 1;
	if (i < 1 || i > pL->length)
	{
		printf_s("顺序表无第%d位！\n", i);
		return ERROR;
	}
	*pe = *p;
	while (i < pL->length)
	{
		*p = *(p+1);
		p++;
		++i;
	}
	pL->length -= 1;
	return OK;
}
Status ListTraverse(PSqList pL, void (*vi)(ElemType* pe))
{
	int i;
	for (i = 0; i < pL->length; i++)
	{
		vi(pL->pelem[i]);
	}
	return OK;
}
Status PriorElem(PSqList pL, ElemType cur_e, ElemType* pro_e)
{
	ElemType* p,*q;
	int i = 2;
	p = pL->pelem + 1;
	while ( i <= pL->length && (*p != cur_e))
	{
		++p;
		++i;
	}
	if ( i > pL->length )
	{
		printf_s("查询失败！\n");
		return ERROR;
	}
	else
	{
		*pro_e = *--p;
		return OK;
	}
}
Status NextElem(PSqList pL, ElemType cur_e, ElemType* next_e)
{
	ElemType* p, * q;
	int i = 1;
	p = pL->pelem;
	while ( i <= pL->length-1 && (*p != cur_e))
	{
		++p;
		++i;
	}
	if (i > (pL->length - 1))
	{
		printf_s("查询失败！\n");
		return ERROR;
	}
	else
	{
		*next_e = *++p;
		return OK;
	}

}
int LocateElem(PSqList pL, ElemType e, Status(*compare)(ElemType a, ElemType b))
{
	ElemType* p;
	p = pL->pelem;
	int i = 1;
	while (i <= pL->length && (compare(*p++, e) != 0))
	{
		++i;
	}
	if (i <= pL->length)
	{
		printf_s("%d \n", i);
		return OK;
	}
	else
	{
		printf_s("查找失败！\n");
		return ERROR;
	}
	
}
void Union(PSqList pLa, PSqList pLb)
{
	int i = 1;
	int j = 1;
	int ai, bj;
	ai = ListLength(pLa);
	bj = ListLength(pLb);
	ElemType Lai;
	ElemType Lbj;
	while (j <= bj )
	{
		Lbj = GetList(pLb, j, &Lbj);
		ListInsert(pLa, j+ai, Lbj);
		j++;
	}
	return OK;
}
void Merge1(PSqList pLa, PSqList pLb, PSqList pLc)
{
	int i = 1;
	int j = 1;
	int k = 0;
	ElemType* p, *q;
	InitList(pLc);
	p = pLa->pelem;
	q = pLb->pelem;
	int La_len, Lb_len;
	La_len = ListLength(pLa);
	Lb_len = ListLength(pLb);
	int ai, bj;
	
	while (i <= La_len && j <= Lb_len)
	{
		ai = GetList(pLa, i, &ai);
		bj = GetList(pLb, j, &bj);
		if ( ai <= bj )
		{
			ListInsert(pLc, ++k, ai);
			++i;
		}
		else
		{
			ListInsert(pLc, ++k, bj);
			++j;
		}
	}
	while (i <= La_len)
	{
		ai = GetList(pLa, i, &ai);
		ListInsert(pLc, ++k, ai);
		++i;
	}
	while (j <= Lb_len)
	{
		bj = GetList(pLb, j, &bj);
		ListInsert(pLc, ++k, bj);
		++j;
	}
	return;
}
void Merge2(PSqList pLa, PSqList pLb, PSqList pLc) 
{
	ElemType* pa, * pb,*pc,*pa_last,*pb_last;
	pa = pLa->pelem;
	pb = pLb->pelem;
	pa_last = pLa->pelem + pLa->length - 1;
	pb_last = pLb->pelem + pLb->length - 1;
	pLc->listsize = pLc->length = pLa->length + pLb->length;
	pLc->pelem = (ElemType*)malloc(sizeof(ElemType) * (pLc->length));
	if (NULL == pLc->pelem)
	{
		printf_s("内存失败！\n");
		return (OVERFLOW);
	}
	else
	{
		pc = pLc->pelem;
		while (pa <= pa_last && pb <= pb_last)
		{
			if (*pa <= *pb)
				*pc++ = *pa++;
			else
				*pc++ = *pb++;
		}
		while (pa <= pa_last)
			*pc++ = *pa++;
		while (pb <= pa_last)
			*pc++ = *pb++;
		return OK;
	}
}
Status Destroy(PSqList pL)
{
	free(pL->pelem);
	pL->pelem = NULL;
	if (NULL != pL->pelem)
	{
		printf_s("销毁内存失败！\n");
		return ERROR;
	}
	else
	{
		return OK;
	}
}
Status ClearList(PSqList pL)
{
	pL->length = 0;
	return OK;
}
Status ListEmpty(PSqList pL)
{
	if (pL->length == 0)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}
int ListLength(PSqList pL)
{
	return (pL->length);
}
Status GetList(PSqList pL, int i, ElemType* e)
{
	if (i < 1 || i > pL->length)
	{
		printf_s("顺序表中无第%i位！\n", i);
		return ERROR;
	}
	else
	{
		return (pL->pelem[i - 1]);
	}
}

/*
总结：
一，语法细节注意
1.1，在定义声明宏时，一定要注意宏的作用是替换，所以在一些情况下，我们不要因习惯当成语句处理而加分号。
		#define SIZE 10;//错误，本意是SIZE替换成10，但误多加了分号
1.2，在使用typedef时不要忘记每行语句加分号；
		typedef int Status;//int 去一个别名为 Status
1.3,连续定义指针变量时，不要忘记变量前面要加*
1.4,注意使用if-else，不要将无论满不满足if都要执行的代码写入else中。
二，编写技巧
2.1，在插入，删除，返回前序，返回后继等访问数组中的每一个元素时，使用指针指向数组的元素，会使其操作简单明了。
		ElemType *p, *q;
		p = pL->pelem;//指向数组第一个元素
		p = pL->pelem + pL->length -1;//指向数组最后一个元素
2.2,凡是定义为指针变量取名都前缀p,表示此变量是指针变量。

*/