#include <stdio.h>
#define MaxSize 100
typedef int ElemType;			//假设顺序表中所有元素为int类型
typedef struct
{
	ElemType data[MaxSize];		//存放顺序表的元素
	int length;					//顺序表的实际长度
} SqList;						//顺序表类型
void InitList(SqList& L)	//由于L要回传给值参，所以用引用类型
{
	L.length = 0;
}
void DestroyList(SqList L)
{
}
int GetLength(SqList L)
{
	return L.length;
}
int GetElem(SqList L, int i, ElemType& e)
{
	if (i<1 || i>L.length)		//无效的i值
		return 0;
	else
	{
		e = L.data[i - 1];
		return 1;
	}
}
int Locate(SqList L, ElemType x)
{
	int i = 0;
	while (i < L.length && L.data[i] != x)
		i++; 	//查找值为x的第1个元素,查找范围为0～L.length-1
	if (i >= L.length) return(0);	//未找到返回0
	else return(i + 1);			//找到后返回其逻辑序号
}
int InsElem(SqList& L, ElemType x, int i)
{
	int j;
	if (i<1 || i>L.length + 1 || L.length == MaxSize)		//无效的参数i
		return 0;
	for (j = L.length; j >= i; j--)		//将位置为i的结点及之后的结点后移
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = x;					//在位置i处放入x
	L.length++;						//线性表长度增1
	return 1;
}
int DelElem(SqList& L, int i)
{
	int j;
	if (i<1 || i>L.length)			//无效的参数i
		return 0;
	for (j = i; j < L.length; j++)		//将位置为i的结点之后的结点前移
		L.data[j - 1] = L.data[j];
	L.length--;						//线性表长度减1
	return 1;
}
void DispList(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
		printf("%d ", L.data[i]);
	printf("\n");
}
void CreateList(SqList& L, ElemType a[], int n)
{
	int i, k = 0;						//k累计顺序表L中的元素个数
	for (i = 0; i < n; i++)
	{
		L.data[k] = a[i];				//向L中添加一个元素
		k++;						//L中元素个数增1
	}
	L.length = k;						//设置L的长度
}

void SwapI(ElemType& x, ElemType& y)
{
	ElemType temp = x;
	x = y;
	y = temp;
}

void SwapL(SqList &L) 
{
	int i, maxi = 0, mini = 0;

	for (int i = 1; i < L.length; i++) 
	{
		if (L.data[i] > L.data[maxi]) 
		{
			maxi = i;
		}
		else if(L.data[i] < L.data[mini])
		{
			mini = i;
		}
	}

	SwapI(L.data[maxi], L.data[mini]);
}

int main()
{
	char name[128] = "徐家国";
	char code[36] = "250604210153";
	char title[128] = "例题2.3";

	SqList arrList;
	ElemType ele[] = { 1, 3, 6, 7, 3, 9 };

	CreateList(arrList, ele, 6);

	printf("题目：%s\t学号：%s\t姓名：%s\r\n", title, code, name);

	printf("线性表：");
	DispList(arrList);

	printf("交换后的线性表：");
	SwapL(arrList);
	DispList(arrList);

	DestroyList(arrList);

	return 0;
}