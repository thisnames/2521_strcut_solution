//顺序栈的基本运算
#include <stdio.h>
#define MaxSize 100				//顺序栈的初始分配空间大小
typedef char ElemType;			//假设顺序栈中所有元素为char类型
typedef struct
{	ElemType data[MaxSize];		//保存栈中元素
	int top;					//栈顶指针
} SqStack;						//顺序栈类型

void InitStack(SqStack &st)		//初始化顺序栈st
{
	st.top=-1;
}
void DestroyStack(SqStack st)	//销毁顺序栈st
{  }

int Push(SqStack &st,ElemType x)	//进栈元素x
{	if (st.top==MaxSize-1)			//栈满
		return 0;
	else
	{	st.top++;
		st.data[st.top]=x;
		return 1;
	}
}

int Pop(SqStack &st,ElemType &x)	//出栈元素x
{	if (st.top==-1)					//栈空
		return 0;
	else 
	{	x=st.data[st.top];
		st.top--;
		return 1;
	}
}

int GetTop(SqStack st,ElemType &x)	//取栈顶元素x
{	if (st.top==-1)					//栈空
		return 0;
	else 
	{	x=st.data[st.top];
		return 1;
	}
}

int StackEmpty(SqStack st)		//判断栈是否为空
{	if (st.top==-1) return 1;
	else return 0;
}
