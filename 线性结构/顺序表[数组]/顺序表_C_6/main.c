/*
时间：2021/1/1 22:10
编辑人：chongqiu00
功能：线性表的实现
*/
#include "main.h"
#include "sqlist.h"

int main (int argc, char *argv[])
{
    int i;
    PSQLIST L;
    InitList(L);

    for (i=0; i<10; i++)
    {
        if(ListInsert(L, 1, i)){
            printf("插入成功！\n");
        }
    }
    
    return 0;
}