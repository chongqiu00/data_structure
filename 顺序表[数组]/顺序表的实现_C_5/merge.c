#include "merge.h"
#include "pointer.h"
void Union(struct SqList* La, struct SqList* Lb)
{
	int i;
	ElemType e;
	int La_len = ListLength(La);
	int Lb_len = ListLength(Lb);
	for (i = 0; i < Lb_len; i++)
	{
		GetList(Lb, i, &e);
		if (!LocteElem(La, e, equ))
		{
			ListInsert(La, ++La_len, e);
		}
	}
}
void MergeList1(struct SqList* La, struct SqList* Lb, struct SqList* Lc)
{
	int i = 1;
	int j = 1;
	int k = 0;
	ElemType ai, bj;
	InitList(Lc);
	int La_len = ListLength(La);
	int Lb_len = ListLength(Lb);
	while (i <= La_len && j <= Lb_len)//La,Lb下标相同时
	{
		GetList(La, i, &ai);
		GetList(Lb, i, &bj);
		if (ai <= bj)
		{
			ListInsert(Lc, ++k, ai);
			++i;
		}
		else
		{
			ListInsert(Lc, ++k, bj);
			++j;
		}
	}
	while (i <= La_len)
	{
		GetList(La, ++i, ai);
		ListInsert(Lc, ++k, ai);
	}
	while (j <= Lb_len)
	{
		GetList(Lb, ++j, bj);
		ListInsert(Lc, ++k, bj);
	}
}
void MergeList2(struct SqList* La, struct SqList* Lb, struct SqList* Lc)
{
	ElemType* pa, * pb, * pc;
	ElemType* pa_last, * pb_last;
	pa = La->elem;
	pb = Lb->elem;
	pa_last = La->elem + La->length - 1;
	pb_last = Lb->elem + Lb->length - 1;
	Lc->listsize = Lc->length = La->length + Lb->length;
	Lc->elem = (ElemType*)malloc(sizeof(ElemType) * Lc->length);
	if (NULL == Lc->elem)
	{
		printf_s("分配内存失败！程序将异常退出！\n");
		exit(INFEASIBLE);
	}
	pc = Lc->elem;
	while (pa <= pa_last && pb <= pb_last)
	{
		if (*pa <= *pb)
		{
			*pc++ = *pa++;
		}
		else
		{
			*pc++ = *pb++;
		}
	}
	while (pa <= pa_last)
	{
		*pc++ = *pa++;
	}
	while (pb <= pb_last)
	{
		*pc++ = *pb++;
	}


}
void MergeList3(struct SqList* La, struct SqList* Lb, struct SqList* Lc)
{
	ElemType* pa, * pb, * pc, * pa_last, pb_last;
	pa = La->elem;
	pb = Lb->elem;
	pa_last = La->elem + La->length - 1;
	pb_last = Lb->elem + Lb->length - 1;
	Lc->listsize = La->length + Lb->length;
	pc = Lc->elem = (ElemType*)malloc(sizeof(ElemType) * Lc->listsize);
	if (NULL == pc)
	{
		printf_s("内存分给失败！程序将异常退出！\n");
		exit(OVERFLOW);
	}
	while (pa <= pa_last && pb < pb_last)
	{
		switch (comp(*pa, *pb))
		{
		case 0:pb++;
		case -1: *pc++ = *pa++; break;
		case  1: *pc++ = *pb++;
		}
	}
	while (pa <= pa_last)
	{
		*pc++ = *pa++;
	}
	while (pb <= pb_last)
	{
		*pc++ = *pb++;
	}
	Lc->length = pc - Lc->elem;
}
