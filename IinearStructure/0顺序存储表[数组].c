/*
* ʱ�䣺2020.10.11
* ���ܣ�����һ��˳������ʵ�ֻ����Ĳ���(�������пգ�������������׷�ӣ����룬ɾ�������ã�����,����)
* Ŀ�ģ�˳������Ľṹ�˽⣬1
*/
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h> //bool
//�����ṹ��
struct Arr {
	int* pbase;//�����һ��Ԫ�ص�ָ��
	int len;//������������
	int cnt;//�������Ч��������
};

//��������
void init_arr(struct Arr*,int);//��ʼ��
bool is_empty(struct Arr* p);//�жϿ�
bool is_full(struct Arr* p);//�ж���
void traverse_arr(struct Arr*);//��������
bool append_arr(struct Arr* , int );//׷������
bool insert_arr(struct Arr*,int ,int);//��������
bool delete_arr(struct Arr*,int ,int*);//ɾ������
bool inversion_arr(struct Arr* p);//��������
bool sort_arr(struct Arr* p);//��������
bool seek_arr(struct Arr*,int val);//��������

//������
int main(void)
{
	int length=0;
	struct Arr a;
	
	printf_s("����ĳ��ȣ�length=");
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

//���ú���ʵ��
void init_arr(struct Arr* p, int length)
{
	p->pbase = (int*)malloc(sizeof(int) * length);
	if (NULL == p->pbase)
	{
		printf_s("�����ڴ�ʧ�ܣ�����\n");
		
		return;
	}
	else
	{
		p->len = length;
		p->cnt = 0;
		printf_s("�����ʼ���ɹ�������\n");
		
	}

	return;
}
void traverse_arr(struct Arr* p)
{
	int i;

	if ( is_empty(p) )
	{
		printf_s("������ʾʧ�ܣ�����\n");
		
	}
	else
	{
		printf_s("��ʾ����������:\n");

		for (i = 0; i < p->cnt; i++)
		{
			printf_s("��%d������Ϊ��%d\n",i+1,p->pbase[i]);
		}
		
	}
	return;
}
bool is_empty(struct Arr* p)
{
	if ( 0 == p->cnt )
	{
		printf_s("������Ϊ�գ�����\n");
		
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
		printf_s("����������������\n");
		
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
		printf_s("����׷��ʧ�ܣ�����\n");
		
		return false;
	}
	else
	{
		p->pbase[p->cnt] = val;
		p->cnt++;
		printf_s("����׷�ӳɹ�������\n");
		
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
		printf_s("������ʧ�ܣ�����\n");
		
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

		printf_s("�����óɹ�������\n");
		
		
		return true;
	}
}
bool insert_arr(struct Arr* p, int pos, int val)//p->pbase[pos+1] = val ;���ݲ���posλ�ĺ��档
{
	int i = p->cnt-1;

	if (is_full(p))
	{
		printf_s("�������ʧ�ܣ�����\n");
		
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
		printf("�������ݲ���ɹ�������\n");
		
		return true;
	}
}
bool delete_arr(struct Arr* p, int pos, int* pval)//pos��ɾ����Ԫ�ر��+1��λ�á�
{
	int i = p->cnt - 1;
	int j = pos-1;
	if (is_empty(p))
	{
		printf_s("��ɾ�����ݣ�����\n");
		
		return false;
	}
	if(pos==0||pos>=p->cnt)
	{
		printf_s("����posΪһ���Ƿ���ֵ������\n");
		
		return false;
	}

	*pval = p->pbase[pos - 1];

	while (j < i)
	{
		p->pbase[j] = p->pbase[j + 1];
		i--;
	}
	p->cnt = p->cnt - 1;
	printf_s("����ɾ���ɹ�������\n");
	
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
		printf_s("���������ݿ����򣡣���\n");
		
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
		printf("��������ɹ�������\n");
		
		return true;
	}
}

bool seek_arr(struct Arr* p, int val)
{
	int i=0;
	int ok=0;
	if (is_empty(p))
	{
		printf_s("����ʧ�ܣ�����\n");
		
		return false;
	}
	else
	{
		while (i < p->cnt)
		{
			if (p->pbase[i] == val)
			{
				printf_s("���ҳɹ�������\n");
				printf_s("���ҵ�����λ������ĵ�%dλ��\n",i+1);
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

