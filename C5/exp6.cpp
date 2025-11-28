#include <stdio.h>
#include "SqStack.cpp.h"

// 利用顺序栈的基本运算，
// 求栈中，从栈顶到栈底的第k个元素，并删除之，要求仍保持栈中元素次序不变
ElemType DelRangeK(SqStack& sk ,int k)
{
	int index = 0;
	ElemType result = 0;

	SqStack before;
	SqStack after;

	InitStack(before);
	InitStack(after);

	// O(n) * 2 - 1
	while (!StackEmpty(sk))
	{
		index++;
		ElemType temp;

		// 弹栈
		Pop(sk, temp);

		if (index < k)
		{
			Push(before, temp);
		}
		else if(index > k)
		{
			Push(after, temp);
		}
		else
		{
			result = temp;
		}
	}

	while (!StackEmpty(after))
	{
		ElemType temp;

		// 弹栈
		Pop(after, temp);
		Push(sk, temp);
	}

	while (!StackEmpty(before))
	{
		ElemType temp;

		// 弹栈
		Pop(before, temp);
		Push(sk, temp);
	}

	return result;
}

// 填充栈
void FillStack(SqStack& sk, ElemType el[], size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		Push(sk, el[i]);
	}
}

// 打印栈
void PrintStack(SqStack sk)
{
	while (!StackEmpty(sk))
	{
		ElemType t;
		Pop(sk, t);

		printf("% d", t);
	}
	printf("\r\n");
}

int main()
{
	ElemType k = 6;

	SqStack sk;
	ElemType e1[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	size_t e1_len = sizeof(e1) / sizeof(ElemType);

	InitStack(sk);
	FillStack(sk, e1, e1_len);

	printf("源栈 sk：");
	PrintStack(sk);

	ElemType result = DelRangeK(sk, k);

	printf("删除栈中 %d 个元素，k = %d\r\n", k, k);
	printf("删除的元素值：%d\r\n", result);
	printf("源栈 sk：");
	PrintStack(sk);

	return 0;
}
