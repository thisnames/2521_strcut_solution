#include <stdio.h>
#include "BTree.cpp.h"

/*
假设二叉树中的每个结点是单个字符且均不相同，采用二叉链存储结构，设计两个算法实如下功能，并用相关数据进行测试：
	（1）求二叉树b中第k层上结点个数，并输出每层结点个数；
	（2）求二叉树b中指定值为x的结点的双亲结点（父节点）p（根结点的双亲为NULL,若b中未找到值为x的结点，p则为NULL）。
*/

// （1）求二叉树b中第k层上结点个数，并输出每层结点个数；
int CountNode(BTNode *b, int k)
{
	// 空树返回 0
	if (b == NULL)
	{
		return 0;
	}
	// 到达第 k 层，返回 1
	if (k == 1)
	{
		return 1;
	}
	// 递归左右子节点，每次层级 k-1
	return CountNode(b->lchild, k - 1) + CountNode(b->rchild, k - 1);
}

// （2）求二叉树b中指定值为x的结点的双亲结点（父节点）p（根结点的双亲为NULL,若b中未找到值为x的结点，p则为NULL）。
BTNode *FindParent(BTNode *b, char x)
{
	// 空树返回 NULL
	if (b == NULL)
	{
		return NULL;
	}
	// 如果左节点不为空且左节点值为 x，返回 b（父节点）
	if (b->lchild != NULL && b->lchild->data == x)
	{
		return b;
	}
	// 如果右节点不为空且右节点值为 x，返回 b（父节点）
	if (b->rchild != NULL && b->rchild->data == x)
	{
		return b;
	}
	// 递归左右子节点
	BTNode *p = FindParent(b->lchild, x);
	if (p != NULL)
	{
		return p;
	}
	// 如果左节点为空，递归右节点
	return FindParent(b->rchild, x);
}

// test 1
void TestCountNode(BTNode *b, int *ks, int lk)
{
	printf("（1）求二叉树b中第k层上结点个数，并输出每层结点个数：\n");
	for (int i = 0; i < lk; i++)
	{
		printf("\t第 %d 层上结点个数：", ks[i]);
		printf("%d\n", CountNode(b, ks[i]));
	}
	printf("\n");
}

// test 2
void TestFindParent(BTNode *b, char *xs, int lx)
{
	printf("（2）求二叉树b中指定值为x的结点的双亲结点（父节点）：\n");
	for (int i = 0; i < lx; i++)
	{
		printf("\t值为 %c 结点的双亲结点：", xs[i]);
		BTNode *p = FindParent(b, xs[i]);
		p == NULL ? printf("NULL\n") : printf("%c\n", p->data);
	}
	printf("\n");
}

// main
int main()
{
	BTNode *bt;
	char data[] = "A(B(D,E),C(F,G))";

	// 创建树
	CreateBTree(bt, data);

	// 输出树
	printf("二叉树bt：");
	DispBTree(bt);
	printf("\n");

	printf("\t结点个数：%d\n\n", NodeCount(bt));

	// 1
	int ks[] = {1, 2, 3, 4, 5, 6, 7};
	TestCountNode(bt, ks, sizeof(ks) / sizeof(int));
	// 2
	char xs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	TestFindParent(bt, xs, sizeof(xs) / sizeof(char));

	return 0;
}
