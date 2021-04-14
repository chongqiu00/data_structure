/*
时间：2021/2/5 20:40
编辑人：chongqiu00
功能：顺序表的实现，（基于数组实现）

<第七次编写>
*/

#include <stdio.h>
#include "sqlist.h"

int main (int argv, char* argc[])
{
    Sq list_1;
    int i;
    InitList(&list_1);

    for (i=0; i<12; i++)
    {
        ListInsert(&list_1, i, 1);
    }

    ListTraverse(&list_1);

    return 0;
}