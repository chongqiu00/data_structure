

//����

#include <stdio.h>
#include<stdbool.h>

void print(int* a, int len, bool isBefore);//����ǰ�����

void BubbleSort(int* a, int len);//ð������

void SelectSort(int* a, int len);//ѡ������

void InsertSort(int* a, int len);//��������

void ShellSort(int* a, int len);//shell����

void quick_sort(int s[], int lift, int right);//��������

//�鲢����

int main(void)
{
	int arry[10] = { 9,8,7,6,5,4,3,2,1,0 };
	//����ǰ
	print(arry, 10, true);

	//BubbleSort(arry, 10);
	//SelectSort(arry, 10);
	//InsertSort(arry, 10);
	//ShellSort(arry,10);
	
	//�����
	print(arry, 10, false);

	while (1);
	return 0;
}

void print(int* a, int len, bool isBefore)
{
	if (isBefore)
		printf_s("before sort:");
	else
		printf_s("after sort:");

	for (int i = 0; i < len; i++)
		printf_s("%d\t", a[i]);

	printf_s("\n");
}

void BubbleSort(int* a, int len)
{
	int i, j, t;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
		//print(a, 10,0);
	}
}

void SelectSort(int* a, int len)
{
	int t;
	for (int i = 0; i < len; i++)
	{
		int k = i;
		for (int j = i; j < len; j++)
		{
			if (a[k] > a[j])
				k = j;
		}
		t = a[k];
		a[k] = a[i];
		a[i] = t;

	}
}

void InsertSort(int* a, int len)//��������
{
	for (int i = 1; i < len; i++)
	{
		int temp = a[i];
		while (i - 1 >= 0 && a[i - 1] > temp)
		{
			a[i] = a[i - 1];
			--i;
		}
		a[i] = temp;
	}
}

void ShellSort(int* a, int len)
{
	int i, j;
	int r, temp;
	int x = 0;

	for (r = len / 2; r >= 1; r /= 2)
	{
		for (i = r; i < len; i++)
		{
			temp = a[i];
			j = i - r;
			while (j >= 0 && temp < a[j])
			{
				a[j + r] = a[j];
				j -= r;
			}
			a[j + r] = temp;
		}
	}
}

//��������
void quick_sort(int s[], int l, int r)
{
	if (l < r)
	{
		//Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // ���������ҵ�һ��С��x����
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, l, i - 1); // �ݹ���� 
		quick_sort(s, i + 1, r);
	}
}

