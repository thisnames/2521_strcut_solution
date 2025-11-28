#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int ElemType;				//设置顺序表元素为int类型
typedef struct
{	ElemType data[MaxSize];			//存放顺序表的元素
	int length;						//顺序表的实际长度
} SqList;							//顺序表类型声明
void InitList(SqList &L)			//初始化顺序表L
{
	L.length=0;
}
void DestroyList(SqList L)			//销毁顺序表L
{
}
int GetLength(SqList L)				//求长度
{
	return L.length;
}
int GetElem(SqList L,int i,ElemType &e)	//求第i个元素
{	if (i<1 || i>L.length)			//无效的i值
		return 0;
	else
	{	e=L.data[i-1];
		return 1;
	}
}
int Locate(SqList L,ElemType x)		//查找第一个x元素的位置
{	int i=0;
	while (i<L.length && L.data[i]!=x)
		i++; 						//查找第1个值为x的元素
	if (i>=L.length) return(0);		//未找到返回0
	else return(i+1);				//找到后返回其逻辑序号
}
int InsElem(SqList &L,ElemType x,int i)	//插入x作为第i个元素
{	int j;
	if (i<1 || i>L.length+1)		//无效的参数i
		return 0;
	for (j=L.length;j>i;j--)		//将位置为i的元素及之后的元素后移
		L.data[j]=L.data[j-1];
	L.data[i-1]=x;					//在位置i处放入x
	L.length++;						//顺序表长度增1
	return 1;
}
int DelElem(SqList &L,int i)		//删除第i个元素
{	int j;
	if (i<1 || i>L.length)			//无效的参数i
		return 0;
	for (j=i;j<L.length;j++)		//将位置为i的元素之后的元素前移
		L.data[j-1]=L.data[j];
	L.length--;						//顺序表长度减1
	return 1;
}
void DispList(SqList L)				//输出顺序表
{	int i;
	for (i=0;i<L.length;i++)
		printf("%d ",L.data[i]);
	printf("\n");
}
void CreateList(SqList &L,ElemType a[],int n)	//整体创建顺序表L
{
	int i,k=0;						//k累计顺序表L中的元素个数
	for (i=0;i<n;i++)
	{
		L.data[k]=a[i];				//向L中添加一个元素
		k++;						//L中元素个数增1
	}
	L.length=k;						//设置L的长度
}

// 两个集合A、B的并集C。（合并去重）
SqList* Union(SqList &l1, SqList&l2)
{
	SqList* temp = (SqList*)malloc(sizeof(SqList));

	// 非空判断
	if (temp == NULL) return NULL;

	InitList(*temp);

	// 先把 l1 的所有元素拷进去
	for (int i = 0; i < l1.length; i++)
	{
		InsElem(*temp, l1.data[i], temp->length + 1);
	}

	// 再把 l2 中不在 l1 里的元素插入
	for (int j = 0; j < l2.length; j++)
	{
		// 如果 l1 中没有找到 l2 中包含的元素，则表示 l1 没有
		if (Locate(l1, l2.data[j]) == 0) InsElem(*temp, l2.data[j], temp->length + 1);
	}

	return temp;
}

// 求两个集合A、B的差集C。（A 差 B，A有的，B没有）
SqList* Difference(SqList& l1, SqList& l2)
{
	SqList* temp = (SqList*)malloc(sizeof(SqList));

	// 非空判断
	if (temp == NULL) return NULL;

	InitList(*temp);

	for (int i = 0; i < l1.length; i++)
	{
		if (Locate(l2, l1.data[i]) == 0) InsElem(*temp, l1.data[i], temp->length + 1);
	}

	return temp;
}

// 求两个集合A、B的交集C。（共有的）
SqList* Intersection(SqList& l1, SqList& l2)
{
	SqList* temp = (SqList*)malloc(sizeof(SqList));

	// 非空判断
	if (temp == NULL) return NULL;

	InitList(*temp);

	for (int i = 0; i < l1.length; i++)
	{
		if (Locate(l2, l1.data[i]) != 0) InsElem(*temp, l1.data[i], temp->length + 1);
	}

	return temp;
}

int main()
{
	SqList l1;
	SqList l2;
	ElemType e1[] = { 1, 3, 5, 7, 9, 11 };
	ElemType e2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	size_t e1_len = sizeof(e1) / sizeof(ElemType);
	size_t e2_len = sizeof(e2) / sizeof(ElemType);

	CreateList(l1, e1,e1_len);
	CreateList(l2, e2, e2_len);

	printf("顺序表 L1: ");
	DispList(l1);
	printf("顺序表 L2: ");
	DispList(l2);

	// 并集
	SqList* ul = Union(l1, l2);
	// 差集
	SqList* dl = Difference(l1, l2);
	// 差集
	SqList* dl2 = Difference(l2, l1);
	// 交集
	SqList* il = Intersection(l1, l2);

	printf("L1 & L2 并集：");
	DispList(*ul);

	printf("L1 - L2 差集：");
	DispList(*dl);
	printf("L2 - L1 差集：");
	DispList(*dl2);

	printf("L1 + L2 交集：");
	DispList(*il);

	return 0;
}