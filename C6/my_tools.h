#pragma once

#include <stdarg.h>
#include <stdio.h>

// 打印换行
int pl(char const* const _Format, ...)
{
	int _Result;
	va_list _ArgList;

	va_start(_ArgList, _Format);

	_Result = vfprintf(stdout, _Format, _ArgList);

	va_end(_ArgList);

	// 使用标准换行符
	printf("\n");

	return _Result;
}

// 获取整数输入，成功返回 1，失败返回 0
int get_sizet_input(const char* prompt, size_t* output)
{
	// 一千万以内的整数
	const short max_length = 9;
	char input[max_length];
	size_t result = 0;

	// 提示用户输入
	printf(prompt);

	// 获取输入
	if (fgets(input, sizeof(input), stdin) == NULL)
	{
		pl("读取输入失败");
		return 0;
	}

	// 解析输入
	for (size_t i = 0; i < sizeof(input); i++)
	{
		char temp = input[i];

		if (temp == '\0') break;
		if (temp < '0' || temp > '9') continue;

		if (result == 0)
		{
			result = temp - '0';
		}
		else
		{
			result = result * 10 + (temp - '0');
		}
	}

	if (result == 0) return 0;

	// 保存数据
	*output = result;

	return 1;
}
