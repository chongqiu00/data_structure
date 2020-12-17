/*
* ʱ�䣺2020/10/16 22:56
* ���ܣ�����һ���򵥵���������������������������������������
* ��������ʾ��ͼ��
*					A
*                 /   \
*               B	   C
*             /       /
*            D       E       
*                     \     
*                       F
* 
*		����ABDCEF
*		����DBAEFC
*		����DBFECA
*		
*/

#include <stdio.h>
#include <malloc.h>

//�ṹ��
struct BTNode
{
	char data;//������
	struct BTNode* pLchild;//����
	struct BTNode* pRchild;//�Һ���
};

//��������
struct BTNode* CreateBTree( void );
void PreTraverseBTree(struct BTNode* pT);
void InTraverseBTree(struct BTNode* pT);
void PostTraverseBTree(struct BTNode* pT);

//������
int main(void)
{
	struct BTNode* pT;
	pT = CreateBTree();
	//PreTraverseBTree(pT);
	//InTraverseBTree(pT);
	PostTraverseBTree(pT);
	return 0;
}

//�Ӻ�����ʵ��
struct BTNode* CreateBTree(void)
{
	struct BTNode* pA = (struct BTNode*)malloc(sizeof(struct BTNode) * 1);
	struct BTNode* pB = (struct BTNode*)malloc(sizeof(struct BTNode) * 1);
	struct BTNode* pC = (struct BTNode*)malloc(sizeof(struct BTNode) * 1);
	struct BTNode* pD = (struct BTNode*)malloc(sizeof(struct BTNode) * 1);
	struct BTNode* pE = (struct BTNode*)malloc(sizeof(struct BTNode) * 1);
	struct BTNode* pF = (struct BTNode*)malloc(sizeof(struct BTNode) * 1);

	pA->data = 'A';
	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->data = 'B';
	pB->pLchild = pD;
	pB->pRchild = NULL;
	pC->data = 'C';
	pC->pLchild = pE;
	pC->pRchild = NULL;
	pD->data = 'D';
	pD->pLchild = pD->pRchild = NULL;
	pE->data = 'E';
	pE->pLchild = NULL;
	pE->pRchild = pF;
	pF->data = 'F';
	pF->pLchild = pF->pRchild = NULL;
	
	return  pA;
}

void PreTraverseBTree(struct BTNode* pT)
{
	if (NULL != pT)
	{
		printf_s("%c\n",pT->data);

		if (NULL != pT->pLchild)
		{
			PreTraverseBTree(pT->pLchild);
		}
		if (NULL != pT->pRchild)
		{
			PreTraverseBTree(pT->pRchild);
		}
		
	}

	return;
}

void InTraverseBTree(struct BTNode* pT)
{
	if (NULL != pT)
	{
		if (NULL != pT->pLchild)
		{
			InTraverseBTree(pT->pLchild);
		}
		printf_s("%c\n", pT->data);
		if (NULL != pT->pRchild)
		{
			InTraverseBTree(pT->pRchild);
		}
	}
	

	return;
}

void PostTraverseBTree(struct BTNode* pT)
{
	if (NULL != pT)
	{
		if (NULL != pT->pLchild)
		{
			InTraverseBTree(pT->pLchild);
		}
		if (NULL != pT->pRchild)
		{
			InTraverseBTree(pT->pRchild);
		}
		printf_s("%c\n", pT->data);
	}

	return;
}

/*
* ���ۣ�
* --------------------------------------------------------------------------------------------
* ͨ���ݹ�ʵ�ֵġ�
* ��������������������������Ĳ��裬����Ϊ�����裬
* �����������1�����ʸ����
*			��2������������
*			��3������������
* 
* �����������1������������
*			��2�����ʸ����
*			��3������������
* 
* �����������1������������
*			��2������������
*			��3�����ʸ����
* 
* �ʿ����õݹ��˼�뽫���ģ����ת����С��ģ���������η��ʵ���������Ǹ���㡣
* -----------------------------------------------------------------------------------------------
* 
*/