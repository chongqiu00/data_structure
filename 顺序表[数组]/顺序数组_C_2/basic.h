#ifndef BASIC_H_
#define BASIC_H_
//
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


//
typedef int ElemType;
//
typedef struct SqList{
    ElemType* Arr;
    int length;
    int sizelist;
}SqList,*pAqList;
#define SIZE_LIST_INIT 10
#define INCREAM_SIZE_LIST 2
//
typedef int Status;

#define ERROR 0
#define OK 1
#define OVERFLOW -1
#define TRUE 1
#define FLASE 0
//
void InitList(pAqList pList);
Status InsertList(pAqList pList, int i, ElemType e);
Status TraverseList(pAqList pList);
#endif