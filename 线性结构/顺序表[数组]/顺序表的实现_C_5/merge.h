#ifndef MERGE_H_
#define MERGE_H_

#include "main.h"

void Union(struct SqList* La, struct SqList* Lb);//13.1	a与b并集，制造出来的新顺序表为La，A，B中的相等元素均计入A中，A中的length是准确值,sizelist为准确值
void MergeList1(struct SqList* La, struct SqList* Lb, struct SqList* Lc);//13.2，结果放入新的顺序表中，A，B中的相等元素均计入C中，C中的length不是准确值,sizelist为准确值
void MergeList2(struct SqList* La, struct SqList* Lb, struct SqList* Lc);//13.3,无需使用创建初始化函数实现新顺序表的创建,使用指针分别指向A，B表，操作会更加清晰，以上缺点仍没有解决
void MergeList3(struct SqList* La, struct SqList* Lb, struct SqList* Lc);//13.4，A，B中的相等元素不计入C中，C中的length,sizelist均为准确值 

#endif