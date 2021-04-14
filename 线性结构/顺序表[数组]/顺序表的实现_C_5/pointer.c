#include "pointer.h"
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
