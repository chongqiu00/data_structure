/*
ʱ�䣺2021/1/1 22:10
�༭�ˣ�chongqiu00
���ܣ����Ա��ʵ��
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
            printf("����ɹ���\n");
        }
    }
    
    return 0;
}