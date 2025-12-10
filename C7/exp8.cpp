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
int IncludeStr(LinkString* org, LinkString* temp)
{
	int orgl = StrLength(org);
	int templ = StrLength(temp);

	//if (StrEqual(org, temp)) return 1;
	if (temp->next == NULL || orgl < templ) return 0;

	int count = 0;
	int index = 0;

	LinkString* cur = org->next;
	while (cur != NULL)
	{
		if (orgl - index < templ) break;

		int base = 1;
		LinkString* next = cur;
		LinkString* ttt = temp->next;
		while (next != NULL && ttt != NULL)
		{
			if (next->data != ttt->data)
			{
				base = 0;
				break;
			}
			next = next->next;
			ttt = ttt->next;
		}

		index++;
		cur = cur->next;

		if (cur == NULL) break;

		count += base;
	}

	return count;
}

void SqStringTest()
{
	// 顺序串
	SqString str;
	char c1[] = "Hello World C++"; // 15

	Assign(str, c1);
	printf("字符串 str：");
	DispStr(str);

	// 取反
	ReverseSqStr(&str);
	printf("逆置 str：");
	DispStr(str);
}

void LinkStringTest()
{
	LinkString* org;
	LinkString* temp;
	//char c1[] = "Hello C++, Hello C, Hello C#"; // 15
	//char c2[] = "Hello"; // 15

	char c1[] = "aaa"; // 15
	char c2[] = "aa"; // 15

	Assign(org, c1);
	Assign(temp, c2);

	printf("主串 S：");
	DispStr(org);
	printf("子串 T：");
	DispStr(temp);

	int count = IncludeStr(org, temp);
	printf("现的总次数：%d\r\n", count);
}

int main()
{

	printf("（1）-------------------------\r\n");
	SqStringTest();
	printf("（2）-------------------------\r\n");
	LinkStringTest();

	return 0;
}