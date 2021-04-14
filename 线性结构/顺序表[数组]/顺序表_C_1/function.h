#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "main.h"
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
//函数状态
#define OK 1//成功
#define ERROR 0//出错
#define TRUE 1//真
#define FLASE 0//假
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
//链表结构
typedef struct{
	ElemType* pelem;
	int length;
	int listsize;
}SqList,*PSqList;
#define INIT_SIZE_LIST 10
#define LIST_INCREMENT 2
//函数实现功能
Status InitList(PSqList pL);//初始化
int ListLength(SqList L);//得出L的元素个数
Status ListInsert(PSqList pL,int i,ElemType e);//在顺序表的i位插入数据。0000
Status ListDelete(PSqList pL, int i, ElemType* pe);//删除顺序表的第i位，将删除的数值返还给pe
Status ListTraverse(PSqList pL, void (*vi)(ElemType* pe));
Status PriorElem(PSqList pL, ElemType cur_e, ElemType* pro_e);
Status NextElem(PSqList pL, ElemType cur_e, ElemType* next_e);
int LocateElem(PSqList pL, ElemType e, Status(*compare)(ElemType a, ElemType b));
void Union(PSqList pLa, PSqList pLb);
void Merge1(PSqList pLa, PSqList pLb, PSqList pLc);
void Merge2(PSqList pLa, PSqList pLb, PSqList pLc);

Status Destroy(PSqList pL);
Status ClearList(PSqList pL);
Status ListEmpty(PSqList pL);
int ListLength(PSqList pL);
Status GetList(PSqList pL, int i, ElemType* e);
/*
union
merge
*/


#endif