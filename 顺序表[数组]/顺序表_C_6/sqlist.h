#ifndef SQLIST_H
#define SQLIST_H

#include "main.h"
//线性表的数据类型
typedef int ElemType;

#define LIST_INIT_SIZE 10//线性表初始化存储分配量
#define LIST_INCREMENT 2//分配增量

typedef struct SqList{
    ElemType *elem;//存储空件基址
    int length;//当前长度
    int listsize;//当前分配存储容量
}SQLIST, *PSQLIST;

//函数功能实现
void InitList(PSQLIST L); // 操作结果：构造一个空的顺序线性表L
void DestroyList(PSQLIST L);// 初始条件：顺序线性表L已存在。操作结果：销毁顺序线性表L
void ClearList(PSQLIST L);// 初始条件：顺序线性表L已存在。操作结果：将L重置为空表
Status ListEmpty(PSQLIST L);// 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE
int ListLength(PSQLIST L);// 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数
Status GetElem(PSQLIST L,int i,ElemType *e);// 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)。操作结果：用e返回L中第i个数据元素的值
int LocateElem(PSQLIST L,ElemType e,Status(*compare)(ElemType e1,ElemType e2));// 初始条件：顺序线性表L已存在，compare()是数据元素判定函数(满足为1，否则为0)
   // 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。
   //           若这样的数据元素不存在，则返回值为0。
Status PriorElem(PSQLIST L,ElemType cur_e,ElemType *pre_e);// 初始条件：顺序线性表L已存在
   // 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，
   //           否则操作失败，pre_e无定义
Status NextElem(PSQLIST L,ElemType cur_e,ElemType *next_e); // 初始条件：顺序线性表L已存在
   // 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，
   //           否则操作失败，next_e无定义
Status ListInsert(PSQLIST L,int i,ElemType e);// 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)+1
   // 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
#endif