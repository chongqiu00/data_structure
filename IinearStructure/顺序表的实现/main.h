#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <malloc.h>
#include <stdio.h>
#include <math.h>

//函数状态
#define TRUE 1//是
#define FALSE 0//否
#define OK 1//操作成功
#define ERROR 0//操作错误
#define INFEASIBLE -1//操作失败
//#define OVERFLOW -2
typedef int status;
typedef int ElemType;
//结构体
struct SqList {
	ElemType* elem;
	int length;
	int listsize;
};
#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 2

#endif