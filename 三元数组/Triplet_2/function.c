#include "main.h"

Triplet InitTriplet(Triplet T, ElemType v1, ElemType v2, ElemType v3)
{
    T = (ElemType*) malloc(sizeof(ElemType) * 3);

    if (NULL == T){
        printf("�����ڴ�ʧ�ܣ�\n");
        exit(-1);
    }
    T[0] = v1, T[1] = v2, T[2] = v3;
    return T;
}  

Status TraverseTriplet(Triplet T)
{
    int i;

    for (i=0; i<3; i++)
    {
        printf("%d ", T[i]);
    }
    return OK;
}

Status DestroyTriplet(Triplet T)
{
    free(T);
    T = NULL;
    return OK;
}

Status Get(Triplet T, int i, ElemType* e)
{
    //�ų����Ϸ�λ��
    if (i<1 || i>3){
        printf("������ĵ�%dλ����Ԫ�����в����ڣ�\n", i);
        return ERROE;
    }
    else{
        *e = T[i-1];
        return OK;
    }
   
}

Status Put(Triplet T, int i, ElemType e)
{
    //�ж�����ĵ�iλ�Ƿ�Ϸ�
    if (i<1 || i>3)
    {
        printf("������ĵ�%dλ����Ԫ�����в����ڣ�\n", i);
        return ERROE;
    }
    else
    {
        T[i-1] = e;
        return OK;
    }
    
}

Status IsAscending(Triplet T)
{
    return (T[0]<T[1] && T[1]<T[2]);
}

Status IsDescending(Triplet T)
{
    return (T[0]>T[1] && T[1]>T[2]);
}

Status Max(Triplet T, ElemType* e)
{
    *e = T[0]>T[1]?T[0]>T[2]?T[0]:T[2]:T[1]>T[2]?T[1]:T[2];
    return OK;
}

Status Min(Triplet T, ElemType* e)
{
    *e = T[0]<T[1]?T[0]<T[2]?T[0]:T[2]:T[1]<T[2]?T[1]:T[2];
    return OK;
}