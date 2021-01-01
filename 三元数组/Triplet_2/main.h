#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROE 0
#define INFEASIBLE -1
typedef int Status;

typedef int ElemType;
typedef ElemType *Triplet;

//初始化
Triplet InitTriplet(Triplet T, ElemType v1, ElemType v2, ElemType v3);
//遍历数组
Status TraverseTriplet(Triplet T);
//销毁数组
Status DestroyTriplet(Triplet T);
//查找元素,用e返回第i位数。
Status Get(Triplet T, int i, ElemType* e);
//改变元素第i位的值
Status Put(Triplet T, int i, ElemType e);
//三元数组升序排列返回OK
Status IsAscending(Triplet T);
//三元数组降序排列返回OK
Status IsDescending(Triplet T);
//找出最大值
Status Max(Triplet T, ElemType* e);
//找出最小值
Status Min(Triplet T, ElemType* e);

#endif