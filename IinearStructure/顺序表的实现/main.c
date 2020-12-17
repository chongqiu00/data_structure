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
		printf_s("插入是否成功： i = %d (1:是 0:否)\n", i);
	}
	for (j = 0; j < 10; j++)
	{
		i = ListInsert(&Lb, 1, j);
		printf_s("插入是否成功： i = %d (1:是 0:否)\n", i);
	}
	Union(&La, &Lb);
	//MergeList3(&La, &Lb, &Lc);
	printf_s("初始化Lc后，Lc->elem = %u, Lc->length = %d, Lc->listsize = %d\n", La.elem, La.length, La.listsize);
	ListTraverse(&Lc, printf1);
	printf_s("遍历Lc后，Lc->elem = %u, Lc->length = %d, Lc->listsize = %d\n", La.elem, La.length, La.listsize);
	/*子函数
	* struct SqList L;
	//1
	 InitList(&L);
	 printf_s("初始化L后，L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	//2
	 for (j = 0; j < 5; j++)
	 {
		i = ListInsert(&L, 1, j);
		printf_s("插入是否成功： i = %d (1:是 0:否)\n", i);
	 }
	 printf_s("插入L后，L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	 //7
	 i = ListEmpty(&L);
	 printf_s("顺序表是否为空：i = %d (1:是 0:否)\n ", i);
	//9
	 GetList(&L,1, &e);
	 printf_s("第1位的数据为 %d\n", e);
	 //10
	 i = PriorElem(&L, 4, &e);
	 printf_s("查询数据的先继是否成功：i = %d (1:是 0：否)\n", i);
	 if (i != -1)
	 {
		 printf_s("数据4的前继为%d\n", e);
	 }
	 else
	 {
		 printf_s("您查询的元素不在顺序表中，或者无前驱.\n");
	 }
	 //11
	 NextElem(&L, 0, &e);
	 printf_s("数据0的后继为%d\n", e);
	 //3
	 ListTraverse(&L, db1);
	 ListTraverse(&L, printf1);
	 printf_s("遍历L后，L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	 //4
	 i = ListDelete(&L, 2, &e);
	 printf_s("删除的元素值为%d\n", e);
	 printf_s("插入L后，L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	 //3
	// ListTraverse(&L, db1);
	 ListTraverse(&L, printf1);
	 printf_s("遍历L后，L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	 //5
	 ClearList(&L);
	 printf_s("清空L后，L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	 //6
	 DestroyList(&L);
	 printf_s("销毁L后，L->elem = %u, L->length = %d, L->listsize = %d\n", L.elem, L.length, L.listsize);
	// ClearList(&L);
	*/
	return 0;
}