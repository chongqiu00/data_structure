#include "main.h"
#include "basic.h"
#include "pointer.h"
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