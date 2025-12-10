#pragma once
#include <malloc.h>
#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct node
{
	ElemType data;					//数据域
	struct node* next;				//指针域
} SLinkNode;						//单链表结点类型
void InitList(SLinkNode*& L)					//初始化单链表L
{
	L = (SLinkNode*)malloc(sizeof(SLinkNode));	//创建头结点L
	L->next = NULL;
}

void DestroyList(SLinkNode*& L)		//销毁单链表L
{
	SLinkNode* pre = L, * p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p; p = p->next;			//pre、p同步后移
	}
	free(pre);
}

int GetLength(SLinkNode* L)			//求长度
{
	int i = 0;
	SLinkNode* p = L->next;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

int GetElem(SLinkNode* L, int i, ElemType& e)	//求第i个结点值
{
	int j = 0;
	SLinkNode* p = L;					//p指向头结点，计数器j置为0
	if (i <= 0) return 0;				//参数i错误返回0
	while (p != NULL && j < i)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return 0;					//未找到返回0
	else
	{
		e = p->data;
		return 1;					//找到后返回1
	}
}

int Locate(SLinkNode* L, ElemType e)	//求第一个值为e的结点位置
{
	SLinkNode* p = L->next;
	int j = 1;						//p指向第一个数据结点，j置为其序号1
	while (p != NULL && p->data != e)
	{
		p = p->next;
		j++;
	}
	if (p == NULL) return(0);			//未找到返回0
	else return(j);					//找到后返回其序号
}

int InsElem(SLinkNode*& L, ElemType x, int i)	//插入结点值为x的结点
{
	int j = 0;
	SLinkNode* p = L, * s;
	if (i <= 0) return 0;				//参数i错误返回0
	while (p != NULL && j < i - 1)		//查找第i-1个结点p
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return 0;					//未找到第i-1个结点时返回0
	else							//找到第i-1个结点p
	{
		s = (SLinkNode*)malloc(sizeof(SLinkNode));
		s->data = x;					//创建存放元素x的新结点s
		s->next = p->next;			//将s结点插入到p结点之后
		p->next = s;
		return 1;					//插入运算成功,返回1
	}
}

int DelElem(SLinkNode*& L, int i)	//删除结点
{
	int j = 0;
	SLinkNode* p = L, * q;
	if (i <= 0) return 0;				//参数i错误返回0
	while (p != NULL && j < i - 1)		//查找第i-1个结点
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return 0;					//未找到第i-1个结点时返回0
	else							//找到第i-1个结点p
	{
		q = p->next;					//q指向被删结点
		if (q == NULL)
			return 0;				//没有第i个结点时返回0
		else
		{
			p->next = q->next;		//从单链表中删除q结点
			free(q);				//释放其空间
			return 1;
		}
	}
}

void DispList(SLinkNode* L)			//输出单链表
{
	SLinkNode* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void CreateListF(SLinkNode*& L, ElemType a[], int n)	//头插法建表
{
	SLinkNode* s;  int i;
	L = (SLinkNode*)malloc(sizeof(SLinkNode));		//创建头结点
	L->next = NULL;									//头结点的next域置空
	for (i = 0; i < n; i++)								//遍历a数组所有元素
	{
		s = (SLinkNode*)malloc(sizeof(SLinkNode));
		s->data = a[i];								//创建存放a[i]元素的新结点s
		s->next = L->next;							//将s插在头结点之后
		L->next = s;
	}
}

void CreateListR(SLinkNode*& L, ElemType a[], int n)	//尾插法建表
{
	SLinkNode* s, * tc;  int i;
	L = (SLinkNode*)malloc(sizeof(SLinkNode));		//创建头结点
	tc = L;											//tc为L的尾结点指针
	for (i = 0; i < n; i++)
	{
		s = (SLinkNode*)malloc(sizeof(SLinkNode));
		s->data = a[i];								//创建存放a[i]元素的新结点s
		tc->next = s;									//将s结点插入tc结点之后
		tc = s;
	}
	tc->next = NULL;									//尾结点next域置为NULL
}
