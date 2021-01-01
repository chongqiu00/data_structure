#include "sqlist.h"

void InitList(PSQLIST L){
    L->elem = (ElemType*) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (NULL == L){
        printf("动态分配内存失败！\n");
        exit(-1);
    }
    else{
        L->length = 0;
        L->listsize = LIST_INIT_SIZE;
    }
    return;
}

void DestroyList(PSQLIST L){
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
    L->listsize = 0;
    return;
}

void ClearList(PSQLIST L){
    L->length = 0;
    return;
}

Status ListEmpty(PSQLIST L){
    if (0 == L->length){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int ListLength(PSQLIST L)
{
    return L->length;
}

Status GetElem(PSQLIST L,int i,ElemType *e){
    //判断i是否合法
    if (i<1 || i>L->length){
        printf("线性表中没有第%d位数据！您输入的数值不合法！\n", i);
        return ERROR;
    }
    else{
        *e = L->elem[i-1];
        return OK;
    }
}

int LocateElem(PSQLIST L, ElemType e, Status(*compare)(ElemType e1, ElemType e2))
{
    int i;
    for (i=0; i<L->length; i++){
        if (compare(L->elem[i], e)){
            return 1;
        }
    }
    return 0;
}

Status compare(ElemType e1, ElemType e2){
    if (e1 == e2){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

Status PriorElem(PSQLIST L,ElemType cur_e,ElemType *pre_e){
    ElemType* p = L->elem + 1;
    int i = 2;
    while (i<=L->length && *p!= cur_e){
        p++;
        i++;
    }
    if (i>L->length){
        return INFEASIBLE;
    }
    else{
        *pre_e = *--p;
        return OK;
    }
}

Status NextElem(PSQLIST L,ElemType cur_e,ElemType *next_e){
    ElemType *p = L->elem;
    int i = 1;
    while (i<L->length && *p!=cur_e){
        p++;
        i++;
    }
    if (i>=L->length){
        return INFEASIBLE;
    }
    else{
        *next_e = *p++;
        return OK;
    }
}

Status ListInsert(PSQLIST L,int i,ElemType e){
    
}