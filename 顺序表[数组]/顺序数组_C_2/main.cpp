/*
编辑人：chongqiu00
功能：顺序表的实现，（基于数组实现）

《第二次编写》
*/

#include "main.h"
#include "basic.h"
int main (void)
{
    SqList L; 
    InitList(&L);
    InsertList(&L, 1,12);
    InsertList(&L, 1,12);
    InsertList(&L, 1,12);
    // printf("%d ", L.Arr[0]);
    // printf("%d ", L.Arr[1]);
    // printf("%d ", L.Arr[2]);
   TraverseList(&L);
    return 0;
}