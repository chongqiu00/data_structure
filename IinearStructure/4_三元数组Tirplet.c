/*
* 时间：2020/10/19 21:31
* 功能：创建一个三元数组Tirplet，对其进行初始化，遍历，销毁，得到一个元素，修改一个元素，判断升序，降序，元素中的最大值，最小值
*/
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

int* InitTirplet(int a, int b, int c);
void TraverseTirplet(int* p);
void DestroyTirplet(int* p);
bool GetTirplet(int* p, int i, int* e);
bool ChangeTirplet(int* p, int i, int e);
bool IsAscending(int* p);//判断是否为升序
bool IsDescending(int* p);//判断是否降序
int MaxTirplet(int* p);
int MinTirplet(int* p);

int main(void)
{
	int* a;
	int b;
	a = InitTirplet(1,2,3);
	b = MaxTirplet(a);
	printf_s("最大值为%d\n", b);
	b = MinTirplet(a);
	printf_s("最小值为%d\n", b);
	return 0;
}

int* InitTirplet(int a, int b, int c)
{
	int* p = (int*)malloc(sizeof(int) * 3);
	if (NULL == p)
	{
		printf_s("分配内存失败！\n");
		exit(-1);
	}
	else
	{
		p[0] = a;
		p[1] = b;
		p[2] = c;

		printf_s("初始化成功！\n");
	}
	return p;
}
void TraverseTirplet(int* p)
{
	int i;
	printf_s("开始遍历：\n");
	for (i = 0; i < 3; i++)
	{
		printf_s("%d\n", *(p+i));
	}
	return;
}
void DestroyTirplet(int* p)
{
	free(p);
	p = NULL;
	printf_s("销毁成功！\n");
	return;
}
bool GetTirplet(int* p, int i, int* e)
{
	if (i < 0 || i>3)
	{
		printf_s("您输入了一个非法数字！\n");
		return false;
	}
	else
	{
		*e = p[i - 1];
	}
}
bool ChangeTirplet(int* p, int i, int e)
{
	if (i < 0 || i>3)
	{
		printf_s("您输入了一个非法数字！\n");
		return false;
	}
	else
	{
		p[i - 1] = e;
		printf_s("修改成功！\n");
		return true;
	}
}
bool IsAscending(int* p)
{
	if (p[1] > p[0] && p[2] > p[1])
	{
		printf_s("三元数组为升序。\n");
		return true;
	}
	else
	{
		printf_s("三元数组不是升序。\n");
		return false;
	}
}
bool IsDescending(int* p)
{
	if (p[0] > p[1] && p[1] > p[2])
	{
		printf_s("三元数组为降序。\n");
		return true;
	}
	else
	{
		printf_s("三元数组不是降序。\n");
		return false;
	}
}
int MaxTirplet(int* p)
{
	int max;
	if (p[0] > p[1])
	{
		if (p[0] > p[2])
		{
			max = p[0];
		}
	}
	else if (p[1] > p[2])
	{
		max = p[1];
	}
	else
	{
		max = p[2];
	}
	return max;
}
int MinTirplet(int* p)
{
	int min;
	if (p[0] < p[1])
	{
		if (p[0] < p[2])
		{
			min = p[0];
		}
	}
	else if (p[1] < p[2])
	{
		min = p[1];
	}
	else
	{
		min = p[2];
	}
	return min;
}

/*
* 结论：
* 
* 1，注意指针的传递，指针的类型，指针所指向的类型，指向指向哪里，切记定义了一个指针，就要初始化此指针，不然不可用此指针进行传参等一系列的操作。
*
* 2，修改主函数变量的值，向被调函数传入该变量的地址。
* 
* 3，修改主函数变量的地址，向被调函数传入该变量的地址的地址。
*/