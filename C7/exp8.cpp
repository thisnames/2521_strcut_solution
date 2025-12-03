#include <stdio.h>

#include "LinkString.cpp.h"
#include "SqString.cpp.h"


//（1）假设一个串采用顺序串存储，设计一个算法将所有字符逆置。并用相关数据进行测试。
void ReverseSqStr(SqString* str)
{
	for (int i = 0; i < str->length / 2; i++)
	{
		char temp = str->data[i];
		int index = str->length - 1 - i;

		str->data[i] = str->data[index];
		str->data[index] = temp;
	}
}

/*
（2）假设一个串采用链串存储，设计一个算法，统计主串 S 中子串 T 出现的总次数。
若子串 T 为空串，返回 0；
若主串 S 长度小于子串 T 长度，返回 0；
若子串 T 在主串 S 中连续出现（如 S="aaa"、T="aa"），需按重叠情况统计（此时结果为 2）。
*/
int IncludeStr(LinkString* str, LinkString* child)
{
	int strLen = StrLength(str);
	int childLen = StrLength(child);

	if (child->next == NULL || strLen < childLen) return 0;
	if (StrEqual(str, child)) return 1;

	LinkString* current = str->next;
	int index = 0;

	while (current != NULL)
	{
		printf("%c", current->data);

		current = current->next;
		index+
	}
}

void SqStringTest()
{
	// 顺序串
	SqString str;
	char c1[] = "Hello World C++"; // 15

	Assign(str, c1);
	DispStr(str);

	// 取反
	ReverseSqStr(&str);
	DispStr(str);
}

int main()
{
	LinkString* str;
	LinkString* temp;
	char c1[] = "Hello C++, Hello C, Hello C#"; // 15
	char c2[] = "Hello"; // 15

	Assign(str, c1);
	Assign(temp, c2);
	DispStr(str);
	DispStr(temp);

	IncludeStr(str, temp);

	return 0;
}