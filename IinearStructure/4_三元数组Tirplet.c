/*
* ʱ�䣺2020/10/19 21:31
* ���ܣ�����һ����Ԫ����Tirplet��������г�ʼ�������������٣��õ�һ��Ԫ�أ��޸�һ��Ԫ�أ��ж����򣬽���Ԫ���е����ֵ����Сֵ
*/
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

int* InitTirplet(int a, int b, int c);
void TraverseTirplet(int* p);
void DestroyTirplet(int* p);
bool GetTirplet(int* p, int i, int* e);
bool ChangeTirplet(int* p, int i, int e);
bool IsAscending(int* p);//�ж��Ƿ�Ϊ����
bool IsDescending(int* p);//�ж��Ƿ���
int MaxTirplet(int* p);
int MinTirplet(int* p);

int main(void)
{
	int* a;
	int b;
	a = InitTirplet(1,2,3);
	b = MaxTirplet(a);
	printf_s("���ֵΪ%d\n", b);
	b = MinTirplet(a);
	printf_s("��СֵΪ%d\n", b);
	return 0;
}

int* InitTirplet(int a, int b, int c)
{
	int* p = (int*)malloc(sizeof(int) * 3);
	if (NULL == p)
	{
		printf_s("�����ڴ�ʧ�ܣ�\n");
		exit(-1);
	}
	else
	{
		p[0] = a;
		p[1] = b;
		p[2] = c;

		printf_s("��ʼ���ɹ���\n");
	}
	return p;
}
void TraverseTirplet(int* p)
{
	int i;
	printf_s("��ʼ������\n");
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
	printf_s("���ٳɹ���\n");
	return;
}
bool GetTirplet(int* p, int i, int* e)
{
	if (i < 0 || i>3)
	{
		printf_s("��������һ���Ƿ����֣�\n");
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
		printf_s("��������һ���Ƿ����֣�\n");
		return false;
	}
	else
	{
		p[i - 1] = e;
		printf_s("�޸ĳɹ���\n");
		return true;
	}
}
bool IsAscending(int* p)
{
	if (p[1] > p[0] && p[2] > p[1])
	{
		printf_s("��Ԫ����Ϊ����\n");
		return true;
	}
	else
	{
		printf_s("��Ԫ���鲻������\n");
		return false;
	}
}
bool IsDescending(int* p)
{
	if (p[0] > p[1] && p[1] > p[2])
	{
		printf_s("��Ԫ����Ϊ����\n");
		return true;
	}
	else
	{
		printf_s("��Ԫ���鲻�ǽ���\n");
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
* ���ۣ�
* 
* 1��ע��ָ��Ĵ��ݣ�ָ������ͣ�ָ����ָ������ͣ�ָ��ָ������мǶ�����һ��ָ�룬��Ҫ��ʼ����ָ�룬��Ȼ�����ô�ָ����д��ε�һϵ�еĲ�����
*
* 2���޸�������������ֵ���򱻵���������ñ����ĵ�ַ��
* 
* 3���޸������������ĵ�ַ���򱻵���������ñ����ĵ�ַ�ĵ�ַ��
*/