#include "pointer.h"
void db1(ElemType* e)//���������β���	
{
	*e *= 2;
	return;
}
void printf1(ElemType* e)//�����ʽ
{
	printf_s("%d ", *e);
	return;
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
