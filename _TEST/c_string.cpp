#include <stdio.h>

// 打印换行
int printfl(char const* const _Format, ...)
{
    int _Result;
    va_list _ArgList;
    __crt_va_start(_ArgList, _Format);
    _Result = _vfprintf_l(stdout, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);

    printf("\r\n");

    return _Result;
}

// 求长度
size_t my_strlen(const char* s) {
    const char* p = s;

    while (*p) ++p;

    return p - s;
}

// 拷贝
char* my_strcpy(char* dst, const char* src, int overwrite = 0) {
    char* save = dst;
    const char* _src = src;

    while (true)
    {
        char t = *src++;

        if (t == '\0')
        {
            if (overwrite) *dst++ = t;
            break;
        }

        *dst++ = t;
    }

    return save;
}

// 连接
char* my_strcat(char* dst, const char* src) {
    char* save = dst;

    while (*dst) ++dst;
    while ((*dst++ = *src++));

    return save;
}

int main()
{
    char str1[] = "c_string";
    printfl("string: %s", str1);

    int len = my_strlen(str1);
    printfl("len: %d", len);

    char cpy[32] = "hello world";
    my_strcpy(cpy, str1);
    printfl("cpy: %s", cpy);

    char cat[16] = "cat";
    my_strcat(cat, "dog");
    printfl("cotcat: %s", cat);

	return 0;
}