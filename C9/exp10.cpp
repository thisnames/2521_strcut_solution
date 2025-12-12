#include <stdio.h>
#include "BTree.cpp.h"

// 二叉树b中的所有大于x的结点个数
int findMaxCount(BTNode* tree, char x)
{
	int count = 0;
	if (tree == NULL) return count;

	count += findMaxCount(tree->lchild, x);
	count += findMaxCount(tree->rchild, x);

	if (tree->data > x)
	{
		count++;
	}

	return count;
}

// 以及最大结点值（空树返回‘0’）
char findMaxValue(BTNode* tree)
{
	char max = '0';
	if (tree == NULL) return max;

	max = tree->data;

	char lmax = findMaxValue(tree->lchild);

	if (lmax > max)
	{
		max = lmax;
	}

	char rmax = findMaxValue(tree->rchild);

	if (rmax > max)
	{
		max = rmax;
	}

	return max;
}

// 先序遍历
void eachBefore(BTNode* tree)
{
	if (tree == NULL) return;

	printf("%c ", tree->data);
	eachBefore(tree->lchild);
	eachBefore(tree->rchild);
}

// 中序遍历
void eachMid(BTNode* tree)
{
	if (tree == NULL) return;

	eachBefore(tree->lchild);
	printf("%c ", tree->data);
	eachBefore(tree->rchild);
}

// 后序遍历
void eachAfter(BTNode* tree)
{
	if (tree == NULL) return;

	eachBefore(tree->lchild);
	eachBefore(tree->rchild);
	printf("%c ", tree->data);
}

// 快捷打印
void echo_print(const char* title, void (*action)(BTNode* bt), BTNode* bt , const char* end)
{
	printf("%s\n", title);
	action(bt);
	printf("%s\n", end);
}

// main
int main()
{
	BTNode* bt;
	char datas[] = "A(B(D,E),C(F,G))";

	CreateBTree(bt, datas);
	printf("二叉树bt：");
	DispBTree(bt);
	printf("\n");

	int node_count = NodeCount(bt);
	printf("节点数量：%d\n", node_count);

	char base_char = 'B';
	int max_count = findMaxCount(bt, base_char);
	printf("大于 [%c] 的节点数量：%d\n", base_char, max_count);

	char max_value = findMaxValue(bt);
	printf("最大值节点值: %c\n", max_value);

	printf("----------- 遍历 -----------\n");
	echo_print("先序遍历：", eachBefore, bt, "");
	echo_print("中序遍历：", eachMid, bt, "");
	echo_print("后序遍历：", eachAfter, bt, "");

	return 0;
}