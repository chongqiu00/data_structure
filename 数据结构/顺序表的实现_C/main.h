#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <malloc.h>
#include <stdio.h>
#include <math.h>

//����״̬
#define TRUE 1//��
#define FALSE 0//��
#define OK 1//�����ɹ�
#define ERROR 0//��������
#define INFEASIBLE -1//����ʧ��
//#define OVERFLOW -2
typedef int status;
typedef int ElemType;
//�ṹ��
struct SqList {
	ElemType* elem;
	int length;
	int listsize;
};
#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 2

#endif