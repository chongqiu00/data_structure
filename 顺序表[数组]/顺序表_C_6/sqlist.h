#ifndef SQLIST_H
#define SQLIST_H

#include "main.h"
//���Ա����������
typedef int ElemType;

#define LIST_INIT_SIZE 10//���Ա��ʼ���洢������
#define LIST_INCREMENT 2//��������

typedef struct SqList{
    ElemType *elem;//�洢�ռ���ַ
    int length;//��ǰ����
    int listsize;//��ǰ����洢����
}SQLIST, *PSQLIST;

//��������ʵ��
void InitList(PSQLIST L); // �������������һ���յ�˳�����Ա�L
void DestroyList(PSQLIST L);// ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������˳�����Ա�L
void ClearList(PSQLIST L);// ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
Status ListEmpty(PSQLIST L);// ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
int ListLength(PSQLIST L);// ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ���
Status GetElem(PSQLIST L,int i,ElemType *e);// ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�������������e����L�е�i������Ԫ�ص�ֵ
int LocateElem(PSQLIST L,ElemType e,Status(*compare)(ElemType e1,ElemType e2));// ��ʼ������˳�����Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����(����Ϊ1������Ϊ0)
   // �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
   //           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0��
Status PriorElem(PSQLIST L,ElemType cur_e,ElemType *pre_e);// ��ʼ������˳�����Ա�L�Ѵ���
   // �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����
   //           �������ʧ�ܣ�pre_e�޶���
Status NextElem(PSQLIST L,ElemType cur_e,ElemType *next_e); // ��ʼ������˳�����Ա�L�Ѵ���
   // �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�
   //           �������ʧ�ܣ�next_e�޶���
Status ListInsert(PSQLIST L,int i,ElemType e);// ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)+1
   // �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
#endif