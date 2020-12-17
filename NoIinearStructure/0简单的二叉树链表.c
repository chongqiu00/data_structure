/*
* 时间：2020/10/16 22:56
* 功能：创建一个简单的链表二叉树，先序遍历，中序遍历，后序遍历。
* 二叉树的示意图：
*					A
*                 /   \
*               B	   C
*             /       /
*            D       E       
*                     \     
*                       F
* 
*		先序：ABDCEF
*		中序：DBAEFC
*		后序：DBFECA
*		
*/

#include <stdio.h>
#include <malloc.h>

//结构体
struct BTNode
{
	char data;//数据域
	struct BTNode* pLchild;//左孩子
	struct BTNode* pRchild;//右孩子
};

//函数声明
struct BTNode* CreateBTree( void );
void PreTraverseBTree(struct BTNode* pT);
void InTraverseBTree(struct BTNode* pT);
void PostTraverseBTree(struct BTNode* pT);

//主函数
int main(void)
{
	struct BTNode* pT;
	pT = CreateBTree();
	//PreTraverseBTree(pT);
	//InTraverseBTree(pT);
	PostTraverseBTree(pT);
	return 0;
}

//子函数的实现
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
* 结论：
* --------------------------------------------------------------------------------------------
* 通过递归实现的。
* 先序遍历，中序遍历，后序遍历的步骤，都分为三步骤，
* 先序遍历：（1）访问根结点
*			（2）访问左子树
*			（3）访问右子树
* 
* 中序遍历：（1）访问左子树
*			（2）访问根结点
*			（3）访问右子树
* 
* 后序遍历：（1）访问左子树
*			（2）访问右子树
*			（3）访问根结点
* 
* 故可以用递归的思想将大规模的树转换成小规模的树，依次访问到最下面的那个结点。
* -----------------------------------------------------------------------------------------------
* 
*/