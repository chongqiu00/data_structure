/*
ʱ�䣺2021/2/5 20:40
�༭�ˣ�chongqiu00
���ܣ�˳����ʵ�֣�����������ʵ�֣�

<���ߴα�д>
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