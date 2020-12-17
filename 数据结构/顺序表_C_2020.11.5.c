/*
* ʱ�䣺2020/11/5 9:07
* ���ܣ�����һ��˳���ʵ�����»�������
*/

#include <stdio.h>
#include <malloc.h>
#include <stdio.h>
#include <math.h>

//����״̬
#define TRUE 1//��
#define FALSE 0//��
#define OK 1//�����ɹ�
#define ERROR 0//��������
#define INFEASIBLE -1//����ʧ��
//#define OVERFLOW -2
typedef int status;
typedef int ElemType;
//�ṹ��
struct SqList{
	ElemType* elem;
	int length;
	int listsize;
};
#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 2
//�Ӻ�������
void InitList(struct SqList* L);//1@
status ListInsert(struct SqList* L, int i, ElemType e);//2@
void ListTraverse(struct SqList* L, void (*vi)(ElemType*));//3@
status ListDelete(struct SqList* L, int i, ElemType* e);//4@
void ClearList(struct SqList* L);//5
void DestroyList(struct SqList* L);//6@
void db1(ElemType* e);//6.1
void printf1(ElemType* e);//6.2
status ListEmpty(struct SqList* L);//7
int ListLength(struct SqList* L);//8
status GetList(struct SqList* L, int i, ElemType* e);//9
status PriorElem(struct SqList* L, ElemType cur_e, ElemType* pre_e);//10@
status NextElem(struct SqList* L, ElemType cur_e, ElemType* next_e);//11@
status LocteElem(struct SqList* L, ElemType e, status (*compare)(ElemType, ElemType));//12@
status equ(ElemType a, ElemType b);//12.1
void Union(struct SqList* La, struct SqList* Lb);//13.1	a��b�����������������˳���ΪLa��A��B�е����Ԫ�ؾ�����A�У�A�е�length��׼ȷֵ,sizelistΪ׼ȷֵ
void MergeList1(struct SqList* La, struct SqList* Lb, struct SqList* Lc);//13.2����������µ�˳����У�A��B�е����Ԫ�ؾ�����C�У�C�е�length����׼ȷֵ,sizelistΪ׼ȷֵ
void MergeList2(struct SqList* La, struct SqList* Lb, struct SqList* Lc);//13.3,����ʹ�ô�����ʼ������ʵ����˳���Ĵ���,ʹ��ָ��ֱ�ָ��A��B���������������������ȱ����û�н��
void MergeList3(struct SqList* La, struct SqList* Lb, struct SqList* Lc);//13.4��A��B�е����Ԫ�ز�����C�У�C�е�length,sizelist��Ϊ׼ȷֵ 
int main(void)
{
	int j;
	ElemType e;
	status i;
	struct SqList La;
	struct SqList Lb;
	struct SqList Lc;
	InitList(&La);
	InitList(&Lb);
	for (j = 0; j < 5; j++)
	{
		i = ListInsert(&La, 1, j);
		printf_s("�����Ƿ�ɹ��� i = %d (1:�� 0:��)\n", i);
	}
	for (j = 0; j < 10; j++)
	{
		i = ListInsert(&Lb, 1, j);
		printf_s("�����Ƿ�ɹ��� i = %d (1:�� 0:��)\n", i);
	}
	Union(&La, &Lb);
	//MergeList3(&La, &Lb, &Lc);
	printf_s("��ʼ��Lc��Lc->elem = %u, Lc->length = %d, Lc->listsize = %d\n", La.elem, La.length, La.listsize);
	ListTraverse(&Lc, printf1);
	printf_s("����Lc��Lc->elem = %u, Lc->length = %d, Lc->listsize = %d\n", La.elem, La.length, La.listsize);
	/*�Ӻ���
	* struct SqList L;
	//1
	 InitList(&L);
	 printf_s("��ʼ��L��L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	//2
	 for (j = 0; j < 5; j++)
	 {
		i = ListInsert(&L, 1, j);
		printf_s("�����Ƿ�ɹ��� i = %d (1:�� 0:��)\n", i);
	 }
	 printf_s("����L��L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	 //7
	 i = ListEmpty(&L);
	 printf_s("˳����Ƿ�Ϊ�գ�i = %d (1:�� 0:��)\n ", i);
	//9
	 GetList(&L,1, &e);
	 printf_s("��1λ������Ϊ %d\n", e);
	 //10
	 i = PriorElem(&L, 4, &e);
	 printf_s("��ѯ���ݵ��ȼ��Ƿ�ɹ���i = %d (1:�� 0����)\n", i);
	 if (i != -1)
	 {
		 printf_s("����4��ǰ��Ϊ%d\n", e);
	 }
	 else
	 {
		 printf_s("����ѯ��Ԫ�ز���˳����У�������ǰ��.\n");
	 }
	 //11
	 NextElem(&L, 0, &e);
	 printf_s("����0�ĺ��Ϊ%d\n", e);
	 //3
	 ListTraverse(&L, db1);
	 ListTraverse(&L, printf1);
	 printf_s("����L��L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	 //4
	 i = ListDelete(&L, 2, &e);
	 printf_s("ɾ����Ԫ��ֵΪ%d\n", e);
	 printf_s("����L��L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	 //3
	// ListTraverse(&L, db1);
	 ListTraverse(&L, printf1);
	 printf_s("����L��L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	 //5
	 ClearList(&L);
	 printf_s("���L��L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	 //6
	 DestroyList(&L);
	 printf_s("����L��L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	// ClearList(&L);
	*/
	return 0;
}
//�Ӻ���ʵ��
void InitList(struct SqList* L)
{
	L->elem = (ElemType*)malloc(sizeof(ElemType) * (LIST_INIT_SIZE));
	if ( NULL == L->elem )
	{
		printf_s("�ڴ����ʧ�ܣ�\n");
		exit(OVERFLOW);
	}
	else
	{
		L->length = 0;
		L->listsize = 10;
	}
	return;
}
void DestroyList(struct SqList* L)//˳���Ĵ洢��һƬ�ڴ浥Ԫ����ɵģ��ͷ�ʱ��ֻ�轫ͷ��ַ�ͷż���
{

		free(L->elem);
		L->elem = NULL;
		L->length = 0;
		L->listsize = 0;
	    return;
}
void ClearList(struct SqList* L)
{
	L->length = 0;
	return;
}
status ListEmpty(struct SqList* L)//Ϊ�շ���1�����շ���0
{
	if (0 == L->length)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
int ListLength(struct SqList* L)
{
	return (L->length);
}
status GetList(struct SqList* L, int i, ElemType* e)
{
	//�ж�i�Ƿ�Ϸ�
	if (i < 1 && i > L->length)
	{
		printf_s("iΪ�Ƿ�����\n");
		return ERROR;
	}
	else
	{
		*e = L->elem[i - 1];
		return OK;
	}
}
status PriorElem(struct SqList* L, ElemType cur_e, ElemType* pre_e)
{
	int i = 2;//���±�Ϊ1��ʼ����
	ElemType* p = L->elem+1;
	while ( (i <= L->length) && (cur_e != *p ))
	{
		p++;
		i++;
	}
	if (i > L->length)
	{
		return INFEASIBLE;
	}
	else
	{
		*pre_e = *--p;
		return OK;
		
	}
}
status NextElem(struct SqList* L, ElemType cur_e, ElemType* next_e)
{
	int i = 1;
	ElemType* p = L->elem;
	while (i < L->length && cur_e != *p)
	{
		i++;
		p++;
	}
	if (i < (L->length - 1))
	{
		*next_e = *++p;
		return OK;
	}
	else
	{
	    return INFEASIBLE;
	}
}
void ListTraverse(struct SqList* L, void (*vi)(ElemType* e))
{
	ElemType* p = L->elem;
	int i;
	for (i = 0; i < L->length; i++)
	{
		vi(p++);
		
	}
	return;
}
void db1(ElemType* e)//���������β���	
{
	*e *= 2;
	return;
}
void printf1(ElemType* e)//�����ʽ
{
	printf_s("%d ", *e);
	return;
}
status ListInsert(struct SqList* L, int i, ElemType e)
{
	ElemType* p = L->elem+ L->length -1;
	ElemType* q = L->elem + i - 1;
	//�ж�Iֵ�Ƿ�Ϸ�
	if (i < 1 || i > L->length+1 )
	{
		return ERROR;
	}
	else
	{
		//�����Ƿ���Ҫ����ڴ�ռ�
		if (L->length == L->listsize)
		{
			ElemType* newbase = (ElemType*)realloc(L->elem, (L->listsize + LIST_INCREMENT) * sizeof(ElemType));
			if (NULL == newbase)
			{
				printf_s("�����ڴ�ʧ�ܣ�\n");
				exit(OVERFLOW);
			}
			L->elem = newbase;
			L->listsize = L->listsize + LIST_INCREMENT;
		}//����ڴ�ɹ�
		for (; p >= q; --p)
		{
			*(p + 1) = *p;
		}
		*q = e;
		++L->length;
	}
	return OK;
}
status ListDelete(struct SqList* L, int i, ElemType* e)
{
	ElemType* p = L->elem + L->length - 1;
	ElemType* q = L->elem + i - 1;
	//�ж�ɾ��λ���Ƿ�Ϸ�
	if (L->length == 0)
	{
		printf_s("˳���Ϊ�գ�\n");
		return ERROR;
	}
	else
	{
		*e = *q;
		for (; q <= p; ++q)
		{
			*q = *(q + 1);
		}
		--L->length;
		return OK;
	}
}
status LocteElem(struct SqList* L, ElemType e, status(*compare)(ElemType, ElemType))
{
	ElemType* p = L->elem;
	int i = 1;
	while (i <= L->length && !compare(*p++, e))
	{
		++i;
	}
	if (i <= L->length)
	{
		return i;
	}
	else
	{
		return 0;
	}

}
status equ(ElemType a, ElemType b)
{
	if (a == b)
		return OK;
	else
		return ERROR;
}
int comp(ElemType a, ElemType b)
{
	if (a == b)
		return 0;
	else
		return ((a - b) / abs(a - b));
}
void Union(struct SqList* La, struct SqList* Lb)
{
	int i;
	ElemType e;
	int La_len = ListLength(La);
	int Lb_len = ListLength(Lb);
	for (i = 0; i < Lb_len; i++)
	{
		GetList(Lb, i, &e);
		if (!LocteElem(La, e, equ))
		{
			ListInsert(La, ++La_len, e);
		}
	}
}
void MergeList1(struct SqList* La, struct SqList* Lb, struct SqList* Lc)
{
	int i = 1;
	int j = 1;
	int k = 0;
	ElemType ai, bj;
	InitList(Lc);
	int La_len = ListLength(La);
	int Lb_len = ListLength(Lb);
	while (i <= La_len && j <= Lb_len)//La,Lb�±���ͬʱ
	{
		GetList(La, i, &ai);
		GetList(Lb, i, &bj);
		if (ai <= bj)
		{
			ListInsert(Lc, ++k, ai);
			++i;
		}
		else
		{
			ListInsert(Lc, ++k, bj);
			++j;
		}
	}
	while (i <= La_len)
	{
		GetList(La, ++i, ai);
		ListInsert(Lc, ++k, ai);
	}
	while (j <= Lb_len)
	{
		GetList(Lb, ++j, bj);
		ListInsert(Lc, ++k, bj);
	}
}
void MergeList2(struct SqList* La, struct SqList* Lb, struct SqList* Lc)
{
	ElemType *pa, *pb, *pc;
	ElemType *pa_last,  *pb_last;
	pa = La->elem;
	pb = Lb->elem;
	pa_last = La->elem + La->length - 1;
	pb_last = Lb->elem + Lb->length - 1;
	Lc->listsize = Lc->length = La->length + Lb->length;
	Lc->elem = (ElemType*)malloc(sizeof(ElemType) * Lc->length);
	if (NULL == Lc->elem)
	{
		printf_s("�����ڴ�ʧ�ܣ������쳣�˳���\n");
		exit(INFEASIBLE);
	}
	pc = Lc->elem;
	while (pa <= pa_last && pb <= pb_last)
	{
		if (*pa <= *pb)
		{
			*pc++ = *pa++;
		}
		else
		{
			*pc++ = *pb++;
		}
	}
	while (pa <= pa_last)
	{
		*pc++ = *pa++;
	}
	while (pb <= pb_last)
	{
		*pc++ = *pb++;
	}


}
void MergeList3(struct SqList* La, struct SqList* Lb, struct SqList* Lc)
{
	ElemType* pa, * pb, *pc, * pa_last, pb_last;
	pa = La->elem;
	pb = Lb->elem;
	pa_last = La->elem + La->length - 1;
	pb_last = Lb->elem + Lb->length - 1;
	Lc->listsize = La->length + Lb->length;
	pc = Lc->elem = (ElemType*)malloc(sizeof(ElemType) * Lc->listsize);	
	if (NULL == pc)
	{
		printf_s("�ڴ�ָ�ʧ�ܣ������쳣�˳���\n");
		exit(OVERFLOW);
	}
	while (pa <= pa_last && pb < pb_last)
	{
		switch (comp(*pa, *pb))
		{
		case 0:pb++;
		case -1: *pc++ = *pa++; break;
		case  1: *pc++ = *pb++;
		}	
	}
	while (pa <= pa_last)
	{
		*pc++ = *pa++;
	}
	while (pb <= pb_last)
	{
		*pc++ = *pb++;
	}
	Lc->length = pc - Lc->elem;
}

/*
* ���ۣ�
* 1��
*	exit(x);xΪ0�������˳���x��0���쳣�˳�
* 2��
*	realloc()����
*	extern void* realloc (void* men_adders, unsigned int newsize);
*	ָ���� = ����������*��realloc(Ҫ�ı��ڴ��С��ָ�������µĴ�С)��
* 3�����ú���ָ��
*	status LocteElem(struct SqList* L,status (*compare)(ElemType, ElemType));
*	status LocteElem(struct SqList* L,status (*compare)(ElemType, ElemType));
*   ʹ���ĸ��������ܼ����ݸ��Ӻ���ʲô���ĺ���ָ�룬��������˺����Ŀ���ֲ�Ժ�����ԡ�
* 4��status
*	�����������ص����ͣ�������Ϊ�ú�����״̬���������������ʲ�ѯ�Ӻ�����ʵ��״̬��
* 5����Ҫ����ĵ���
* 
*	
*/