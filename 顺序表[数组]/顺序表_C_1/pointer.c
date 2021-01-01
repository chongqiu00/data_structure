#include "pointer.h"
void printf1(ElemType e)
{
	printf_s("%d ", e);
	return;
}
int equ(ElemType a, ElemType b)
{
	if (a == b)
	{
		return 0;
	}
	else
	{
		return (a - b) / abs(a - b);
	}
}