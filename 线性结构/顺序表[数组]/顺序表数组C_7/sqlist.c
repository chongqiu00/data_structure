#include "sqlist.h"

void InitList(pSq list)
{
    list->elem = (ElemType*) malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if (NULL == list->elem)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        exit(-1);
    }
    list->length = 0;
    list->listsize = LIST_INIT_SIZE;
    
    return;
}

Status ListInsert(pSq list, ElemType elem, int pov)
{
    //����λ���Ƿ�Ϸ�
    if (pov<1 || pov>list->length+1)
    {
        printf("���ݲ����λ�÷Ƿ���\n");
        return ERROR;
    }

    //�ռ��ڴ��Ƿ���
    if (list->length == list->listsize)
    {
        pSq new_elem = (ElemType*) realloc(list->elem, list->length + LIST_INCREMENT);
        if (NULL == new_elem)
        {
            printf("�ڴ����ʧ�ܣ�\n");
            exit(-1);
        }
        //��������
        list->elem = new_elem;
        list->listsize += LIST_INCREMENT;
    }

    //����
    ElemType* p = list->elem + pov - 2;
    ElemType* q = list->elem + list->length - 1;
    while (p != q)
    {
        *(q + 1) = *q;
        q--;
    }

    return OK;
}

Status ListTraverse(pSq list)
{
    int i;
    for (i=0; i<list->length; i++)
    {
        printf("%d ", list->elem[i]);
    }
}