#include "basic.h"

void InitList(pAqList pList)
{
    pList->Arr = (ElemType*) malloc(sizeof(ElemType)*SIZE_LIST_INIT);
    if (NULL == pList->Arr)
    {
        printf("���������ڴ�ʧ��!\n");
        exit(OVERFLOW);
    }
    else
    {
        pList->sizelist = SIZE_LIST_INIT;
        pList->length = 0;
        return;
    }
}
Status InsertList(pAqList pList, int i, ElemType e)
{
    //
    if (i < 1 || i > pList->length+1)
    {
        printf("������û�е�%dλԪ�أ�\n",i);
        return (ERROR);
    }
    else
    {
        if (pList->length == pList->sizelist)
        {
            ElemType* pNew;
            pNew = (ElemType*) realloc(pList->Arr,sizeof(ElemType)*(pList->length + INCREAM_SIZE_LIST)) ;
            if (NULL == pNew)
            {
                printf("��չ�����ڴ�ʧ�ܣ�\n");
                return (OVERFLOW);
            }
            pList->Arr = pNew;
            pList->sizelist += 2;
        }
            //�мǴ˴����Բ�Ҫдif��ƥ��else��������̷�֧����������Ҫ��չʱ����ɳ����޷�ִ�����µĲ���
            ElemType* p = pList->Arr + i - 1;
            ElemType* q = pList->Arr + pList->length - 1;
            while ( i <= pList->length )
            {
                *(q + 1) = *q;
                q--;
                i++;
            }   
            *p = e;
            pList->length += 1;
    }
    return OK;
}
Status TraverseList(pAqList pList)
{
    int i;
    for (i=0; i < pList->length; i++)
    {
        printf("%d ", pList->Arr[i]);
    }
    return OK;
}