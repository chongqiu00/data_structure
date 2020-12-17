/*
* 时间：2020.10.11
* 功能：创建一个顺序链表，实现基本的操作(创建，判空，判满，遍历，追加，插入，删除，倒置，排序,查找)
* 目的：顺序链表的结构了解，1
*/
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h> //bool
//声明结构体
struct Arr {
	int* pbase;//数组第一个元素的指针
	int len;//链表的最大容量
	int cnt;//链表的有效数据容量
};

//函数声明
void init_arr(struct Arr*,int);//初始化
bool is_empty(struct Arr* p);//判断空
bool is_full(struct Arr* p);//判断满
void traverse_arr(struct Arr*);//遍历链表
bool append_arr(struct Arr* , int );//追加数据
bool insert_arr(struct Arr*,int ,int);//插入数据
bool delete_arr(struct Arr*,int ,int*);//删除数据
bool inversion_arr(struct Arr* p);//倒置数据
bool sort_arr(struct Arr* p);//排序数据
bool seek_arr(struct Arr*,int val);//查找数据

//主函数
int main(void)
{
	int length=0;
	struct Arr a;
	
	printf_s("链表的长度：length=");
	scanf_s("%d", &length);
	printf_s("\n");
	
	init_arr(&a,length);
	append_arr(&a, 5);
	append_arr(&a, 4);
	append_arr(&a, 3);
	append_arr(&a, 2);
	traverse_arr(&a);
	seek_arr(&a,2);
	traverse_arr(&a);
	return 0;
}

//调用函数实现
void init_arr(struct Arr* p, int length)
{
	p->pbase = (int*)malloc(sizeof(int) * length);
	if (NULL == p->pbase)
	{
		printf_s("分配内存失败！！！\n");
		
		return;
	}
	else
	{
		p->len = length;
		p->cnt = 0;
		printf_s("链表初始化成功！！！\n");
		
	}

	return;
}
void traverse_arr(struct Arr* p)
{
	int i;

	if ( is_empty(p) )
	{
		printf_s("链表显示失败！！！\n");
		
	}
	else
	{
		printf_s("显示此链表数据:\n");

		for (i = 0; i < p->cnt; i++)
		{
			printf_s("第%d个数据为：%d\n",i+1,p->pbase[i]);
		}
		
	}
	return;
}
bool is_empty(struct Arr* p)
{
	if ( 0 == p->cnt )
	{
		printf_s("此链表为空！！！\n");
		
		return true;
	}
	else
	{
		return false;
	}
}
bool is_full(struct Arr* p)
{
	if (p->cnt == p->len)
	{
		printf_s("此链表已满！！！\n");
		
		return true;
	}
	else
	{
		return false;
	}
}
bool append_arr(struct Arr* p, int val)
{
	if (is_full(p))
	{
		printf_s("链表追加失败！！！\n");
		
		return false;
	}
	else
	{
		p->pbase[p->cnt] = val;
		p->cnt++;
		printf_s("链表追加成功！！！\n");
		
		return true;

	}
}
bool inversion_arr(struct Arr* p)
{
	int i = 0;
	int j = p->cnt-1;
	int t;

	if (is_empty(p))
	{
		printf_s("链表倒置失败！！！\n");
		
		return false;
	}
	else
	{
		while(i<j)
		{
			t = p->pbase[i];
			p->pbase[i] = p->pbase[j];
			p->pbase[j] = t;
			i++;
			j--;
		}

		printf_s("链表倒置成功！！！\n");
		
		
		return true;
	}
}
bool insert_arr(struct Arr* p, int pos, int val)//p->pbase[pos+1] = val ;数据插入pos位的后面。
{
	int i = p->cnt-1;

	if (is_full(p))
	{
		printf_s("链表插入失败！！！\n");
		
		return false;
	}
	else
	{
		while (i >pos || i==pos)
		{
			p->pbase[i + 1] = p->pbase[i];
			i--;
		}
		p->pbase[pos] = val;

		p->cnt = p->cnt + 1;
		printf("链表数据插入成功！！！\n");
		
		return true;
	}
}
bool delete_arr(struct Arr* p, int pos, int* pval)//pos是删除的元素标号+1的位置。
{
	int i = p->cnt - 1;
	int j = pos-1;
	if (is_empty(p))
	{
		printf_s("无删除数据！！！\n");
		
		return false;
	}
	if(pos==0||pos>=p->cnt)
	{
		printf_s("输入pos为一个非法数值！！！\n");
		
		return false;
	}

	*pval = p->pbase[pos - 1];

	while (j < i)
	{
		p->pbase[j] = p->pbase[j + 1];
		i--;
	}
	p->cnt = p->cnt - 1;
	printf_s("链表删除成功！！！\n");
	
	return true;
	
}
bool sort_arr(struct Arr* p)
{
	int i = p->cnt - 1;
	int j;
	int k;
	int t;
	if (is_empty(p))
	{
		printf_s("链表无数据可排序！！！\n");
		
			return false;
	}
	else
	{
		for (j = 0; j < i ; j++)
		{
			for (k =0; k < i- j; k++)
			{
				if (p->pbase[k] > p->pbase[k+1])
				{
					t = p->pbase[k];
					p->pbase[k] = p->pbase[k+1];
					p->pbase[k+1] = t;
				}
			}
		}
		printf("链表排序成功！！！\n");
		
		return true;
	}
}

bool seek_arr(struct Arr* p, int val)
{
	int i=0;
	int ok=0;
	if (is_empty(p))
	{
		printf_s("查找失败！！！\n");
		
		return false;
	}
	else
	{
		while (i < p->cnt)
		{
			if (p->pbase[i] == val)
			{
				printf_s("查找成功！！！\n");
				printf_s("查找的数据位于数组的第%d位。\n",i+1);
				ok = 1;
			}
			i++;
		}
		
		if (ok)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

