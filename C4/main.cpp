#include <malloc.h>
#include "SLinkNode.h"

// 连接两个单链表 L1 = n, L2 = M, L3 = tl
SLinkNode* ConcatSingleList(SLinkNode*& l1, SLinkNode*& l2)
{
	// 开辟内存
	SLinkNode* tl = (SLinkNode*)malloc(sizeof(SLinkNode));

	// 非空判断
	if (tl == NULL) return NULL;

	// 初始化
	InitList(tl);

	// 记录长度
	int l1_len = GetLength(l1); // n
	int l2_len = GetLength(l2); // m
	int tl_len = GetLength(tl); // L3
	SLinkNode* c1 = NULL;
	SLinkNode* c2 = NULL;

	// L3=（X1，Y1，X2，Y2，…Xm，Ym，Xm+1，…Xn）当m<=n
	// L1 的长度大于等于 L2 时
	if (l1_len >= l2_len)
	{
		//printf("// 遍历 L1\r\n");
		// 遍历 l1
		c1 = l1->next;
		c2 = l2->next;
		while (c1 != NULL)
		{
			InsElem(tl, c1->data, ++tl_len);
			c1 = c1->next;

			if (c2 != NULL)
			{
				InsElem(tl, c2->data, ++tl_len);
				c2 = c2->next;
			}
		}
	}
	else
	{
		//printf("// 遍历 L2\r\n");
		// 遍历 l2
		c1 = l1->next;
		c2 = l2->next;
		while (c2 != NULL)0
		{
			if (c1 != NULL)
			{
				InsElem(tl, c1->data, ++tl_len);
				c1 = c1->next;
			}

			InsElem(tl, c2->data, ++tl_len);
			c2 = c2->next;
		}
	}

	return tl;
}

int main()
{
	SLinkNode* l1; // n
	SLinkNode* l2; // m
	
	// m < n
	ElemType e1[] = { 1, 3, 5, 7, 9, 11, 13, 15 };
	ElemType e2[] = { 2, 4, 6, 8, 10, 12 };

	// m = n
	//ElemType e1[] = { 1, 3, 5, 7, 9 };
	//ElemType e2[] = { 2, 4, 6, 8, 10 };

	// m > n
	//ElemType e1[] = { 1, 3, 5, 7, 9 };
	//ElemType e2[] = { 2, 4, 6, 8, 10, 12, 14 };

	size_t e1_len = sizeof(e1) / sizeof(ElemType);
	size_t e2_len = sizeof(e2) / sizeof(ElemType);

	// 创建单链表 L1、L2
	CreateListR(l1, e1, e1_len);
	CreateListR(l2, e2, e2_len);

	printf("单链表L1：");
	DispList(l1);
	printf("单链表L2：");
	DispList(l2);

	// 合并单链表
	SLinkNode* l3 = ConcatSingleList(l1, l2);

	printf("L1 + L2 = L3：");
	DispList(l3);

	// 释放
	DestroyList(l1);
	DestroyList(l2);
	DestroyList(l3);

	return 0;
}
