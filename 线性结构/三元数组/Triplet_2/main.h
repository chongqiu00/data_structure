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

//��ʼ��
Triplet InitTriplet(Triplet T, ElemType v1, ElemType v2, ElemType v3);
//��������
Status TraverseTriplet(Triplet T);
//��������
Status DestroyTriplet(Triplet T);
//����Ԫ��,��e���ص�iλ����
Status Get(Triplet T, int i, ElemType* e);
//�ı�Ԫ�ص�iλ��ֵ
Status Put(Triplet T, int i, ElemType e);
//��Ԫ�����������з���OK
Status IsAscending(Triplet T);
//��Ԫ���齵�����з���OK
Status IsDescending(Triplet T);
//�ҳ����ֵ
Status Max(Triplet T, ElemType* e);
//�ҳ���Сֵ
Status Min(Triplet T, ElemType* e);

#endif