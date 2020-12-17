/*
* 时间：2020/11/5 9:07
* 功能：构造一个顺序表，实现以下基本功能
*/

#include <stdio.h>
#include <malloc.h>
#include <stdio.h>
#include <math.h>

//函数状态
#define TRUE 1//是
#define FALSE 0//否
#define OK 1//操作成功
#define ERROR 0//操作错误
#define INFEASIBLE -1//操作失败
//#define OVERFLOW -2
typedef int status;
typedef int ElemType;
//结构体
struct SqList{
	ElemType* elem;
	int length;
	int listsize;
};
#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 2
//子函数声明
void InitList(struct SqList* L);//1@
status ListInsert(struct SqList* L, int i, ElemType e);//2@
void ListTraverse(struct SqList* L, void (*vi)(ElemType*));//3@
status ListDelete(struct SqList* L, int i, ElemType* e);//4@
void ClearList(struct SqList* L);//5
void DestroyList(struct SqList* L);//6@
void db1(ElemType* e);//6.1
void printf1(ElemType* e);//6.2
status ListEmpty(struct SqList* L);//7
int ListLength(struct SqList* L);//8
status GetList(struct SqList* L, int i, ElemType* e);//9
status PriorElem(struct SqList* L, ElemType cur_e, ElemType* pre_e);//10@
status NextElem(struct SqList* L, ElemType cur_e, ElemType* next_e);//11@
status LocteElem(struct SqList* L, ElemType e, status (*compare)(ElemType, ElemType));//12@
status equ(ElemType a, ElemType b);//12.1
void Union(struct SqList* La, struct SqList* Lb);//13.1	a与b并集，制造出来的新顺序表为La，A，B中的相等元素均计入A中，A中的length是准确值,sizelist为准确值
void MergeList1(struct SqList* La, struct SqList* Lb, struct SqList* Lc);//13.2，结果放入新的顺序表中，A，B中的相等元素均计入C中，C中的length不是准确值,sizelist为准确值
void MergeList2(struct SqList* La, struct SqList* Lb, struct SqList* Lc);//13.3,无需使用创建初始化函数实现新顺序表的创建,使用指针分别指向A，B表，操作会更加清晰，以上缺点仍没有解决
void MergeList3(struct SqList* La, struct SqList* Lb, struct SqList* Lc);//13.4，A，B中的相等元素不计入C中，C中的length,sizelist均为准确值 
int main(void)
{
	int j;
	ElemType e;
	status i;
	struct SqList La;
	struct SqList Lb;
	struct SqList Lc;
	InitList(&La);
	InitList(&Lb);
	for (j = 0; j < 5; j++)
	{
		i = ListInsert(&La, 1, j);
		printf_s("插入是否成功： i = %d (1:是 0:否)\n", i);
	}
	for (j = 0; j < 10; j++)
	{
		i = ListInsert(&Lb, 1, j);
		printf_s("插入是否成功： i = %d (1:是 0:否)\n", i);
	}
	Union(&La, &Lb);
	//MergeList3(&La, &Lb, &Lc);
	printf_s("初始化Lc后，Lc->elem = %u, Lc->length = %d, Lc->listsize = %d\n", La.elem, La.length, La.listsize);
	ListTraverse(&Lc, printf1);
	printf_s("遍历Lc后，Lc->elem = %u, Lc->length = %d, Lc->listsize = %d\n", La.elem, La.length, La.listsize);
	/*子函数
	* struct SqList L;
	//1
	 InitList(&L);
	 printf_s("初始化L后，L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	//2
	 for (j = 0; j < 5; j++)
	 {
		i = ListInsert(&L, 1, j);
		printf_s("插入是否成功： i = %d (1:是 0:否)\n", i);
	 }
	 printf_s("插入L后，L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	 //7
	 i = ListEmpty(&L);
	 printf_s("顺序表是否为空：i = %d (1:是 0:否)\n ", i);
	//9
	 GetList(&L,1, &e);
	 printf_s("第1位的数据为 %d\n", e);
	 //10
	 i = PriorElem(&L, 4, &e);
	 printf_s("查询数据的先继是否成功：i = %d (1:是 0：否)\n", i);
	 if (i != -1)
	 {
		 printf_s("数据4的前继为%d\n", e);
	 }
	 else
	 {
		 printf_s("您查询的元素不在顺序表中，或者无前驱.\n");
	 }
	 //11
	 NextElem(&L, 0, &e);
	 printf_s("数据0的后继为%d\n", e);
	 //3
	 ListTraverse(&L, db1);
	 ListTraverse(&L, printf1);
	 printf_s("遍历L后，L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	 //4
	 i = ListDelete(&L, 2, &e);
	 printf_s("删除的元素值为%d\n", e);
	 printf_s("插入L后，L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	 //3
	// ListTraverse(&L, db1);
	 ListTraverse(&L, printf1);
	 printf_s("遍历L后，L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	 //5
	 ClearList(&L);
	 printf_s("清空L后，L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	 //6
	 DestroyList(&L);
	 printf_s("销毁L后，L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	// ClearList(&L);
	*/
	return 0;
}
//子函数实现
void InitList(struct SqList* L)
{
	L->elem = (ElemType*)malloc(sizeof(ElemType) * (LIST_INIT_SIZE));
	if ( NULL == L->elem )
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
	ElemType* p = L->elem+1;
	while ( (i <= L->length) && (cur_e != *p ))
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
void db1(ElemType* e)//对数据作何操作	
{
	*e *= 2;
	return;
}
void printf1(ElemType* e)//输出形式
{
	printf_s("%d ", *e);
	return;
}
status ListInsert(struct SqList* L, int i, ElemType e)
{
	ElemType* p = L->elem+ L->length -1;
	ElemType* q = L->elem + i - 1;
	//判断I值是否合法
	if (i < 1 || i > L->length+1 )
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
status equ(ElemType a, ElemType b)
{
	if (a == b)
		return OK;
	else
		return ERROR;
}
int comp(ElemType a, ElemType b)
{
	if (a == b)
		return 0;
	else
		return ((a - b) / abs(a - b));
}
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
	ElemType *pa, *pb, *pc;
	ElemType *pa_last,  *pb_last;
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
	ElemType* pa, * pb, *pc, * pa_last, pb_last;
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

/*
* 结论：
* 1，
*	exit(x);x为0是正常退出，x非0是异常退出
* 2，
*	realloc()函数
*	extern void* realloc (void* men_adders, unsigned int newsize);
*	指针名 = （数据类型*）realloc(要改变内存大小的指针名，新的大小)；
* 3，调用函数指针
*	status LocteElem(struct SqList* L,status (*compare)(ElemType, ElemType));
*	status LocteElem(struct SqList* L,status (*compare)(ElemType, ElemType));
*   使用哪个函数功能即传递给子函数什么样的函数指针，大大增加了函数的可移植性和灵活性。
* 4，status
*	命名函数返回的类型，将其视为该函数的状态，便于主函数访问查询子函数的实现状态。
* 5，需要记忆的单词
* 
*	
*/