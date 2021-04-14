#ifndef SQLIST_H_
#define SQLIST_H_

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

//����״̬
#define true 1
#define false 0
#define OK 1
#define ERROR 0

//��������
typedef int Status;
typedef int ElemType;

//����˳������
typedef struct SqList{
    ElemType* elem;
    int length;
    int listsize;
}Sq, *pSq;
#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 2

//��������
void InitList(pSq list);
Status ListInsert(pSq list, ElemType elem, int pov);
Status ListTraverse(pSq list);
ListDelete();

#endif