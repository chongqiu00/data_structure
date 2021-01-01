#ifndef BASIC_H_
#define BASIC_H_

#include "main.h"
void InitList(struct SqList* L);//1@
status ListInsert(struct SqList* L, int i, ElemType e);//2@
void ListTraverse(struct SqList* L, void (*vi)(ElemType*));//3@
status ListDelete(struct SqList* L, int i, ElemType* e);//4@
void ClearList(struct SqList* L);//5
void DestroyList(struct SqList* L);//6@
status ListEmpty(struct SqList* L);//7
int ListLength(struct SqList* L);//8
status GetList(struct SqList* L, int i, ElemType* e);//9
status PriorElem(struct SqList* L, ElemType cur_e, ElemType* pre_e);//10@
status NextElem(struct SqList* L, ElemType cur_e, ElemType* next_e);//11@
status LocteElem(struct SqList* L, ElemType e, status(*compare)(ElemType, ElemType));//12@


#endif