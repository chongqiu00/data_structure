#include "main.h"
#include "function.h"
#include "pointer.h"
int main(void)
{
	int i;
	int j;
	SqList L;
	ElemType e;
	InitList(&L);
	for (i = 1; i <= 10; i++)
	{
		ListInsert(&L, 1, i);
	}
	SqList La; SqList Lb; SqList Lc;
	InitList(&La);
	for (i = 1; i <= 5; i++)
	{
		ListInsert(&La, 1, i);
	}
	InitList(&Lb);
	for (i = 1; i <= 5; i++)
	{
		ListInsert(&Lb, 1, i);
	}

	switch (13)
	{
	case(1):ListInsert(&L, 10, 999); break;
	case(2):ListDelete(&L, 0, &e); break;
	case(3):NextElem(&L, 4, &e); break;
	case(4):PriorElem(&L, 4, &e); break;
	case(5): {
		j = LocateElem(&L, 1, equ);
		if (j = 0)
		{
			printf_s("´ËÊý´æÔÚ£¡\n");
		}
	}break;
	case(6):Destroy(&L); break;
	case(7):ClearList(&L); break;
	case(8):ListEmpty(&L); break;
	case(9):printf_s("%d \n", j = ListLength); break;
	case(10):GetList(&L, 2, &e); break;
	case(11):Union(&La, &Lb);
	case(12):Merge1(&La, &Lb,&Lc);
	case(13):Merge2(&La, &Lb, &Lc);
	default: break;
	}
	ListTraverse(&Lc, printf1);
	return 0;
}