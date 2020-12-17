#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "main.h"
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
//����״̬
#define OK 1//�ɹ�
#define ERROR 0//����
#define TRUE 1//��
#define FLASE 0//��
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
//����ṹ
typedef struct{
	ElemType* pelem;
	int length;
	int listsize;
}SqList,*PSqList;
#define INIT_SIZE_LIST 10
#define LIST_INCREMENT 2
//����ʵ�ֹ���
Status InitList(PSqList pL);//��ʼ��
int ListLength(SqList L);//�ó�L��Ԫ�ظ���
Status ListInsert(PSqList pL,int i,ElemType e);//��˳����iλ�������ݡ�0000
Status ListDelete(PSqList pL, int i, ElemType* pe);//ɾ��˳���ĵ�iλ����ɾ������ֵ������pe
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