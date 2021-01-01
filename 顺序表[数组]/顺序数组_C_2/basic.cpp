#include "basic.h"

void InitList(pAqList pList)
{
    pList->Arr = (ElemType*) malloc(sizeof(ElemType)*SIZE_LIST_INIT);
    if (NULL == pList->Arr)
    {
        printf("创建数组内存失败!\n");
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
        printf("数组中没有第%d位元素！\n",i);
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
                printf("扩展数组内存失败！\n");
                return (OVERFLOW);
            }
            pList->Arr = pNew;
            pList->sizelist += 2;
        }
            //切记此处绝对不要写if的匹配else，造成流程分支，当数组需要扩展时，造成程序无法执行以下的操作
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