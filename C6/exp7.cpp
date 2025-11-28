#define MAIN

#include <stdio.h>

#include "link_queue.h"

// 打印换行
int pl(char const* const _Format, ...)
{
    int _Result;
    va_list _ArgList;
    __crt_va_start(_ArgList, _Format);
    _Result = _vfprintf_l(stdout, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);

    printf("\r\n");

    return _Result;
}

// 打印标题
int title()
{
    pl("===================病人看病模拟程序===================");

    pl("1：排队");
    pl("\t——输入排队病人的就诊卡号，加入到病人排队的队列中。");

    pl("2：就诊");
    pl("\t——病人排队队列中最前面的病人就诊，并将其中队列中删除。");

    pl("3：查看排队");
    pl("\t——从队首到队尾输出所有的排队病人的就诊卡号。");

    pl("4：不再排队");
    pl("\t——余下的依次就诊从队首到队尾输出所有的排队病人的就诊卡号，看完病后，退出运行。");

    pl("5：下班");
    pl("\t——退出运行。");

    pl("=====================================================");

    return 0;
}

#ifdef MAIN
// 程序入口
int main(void)
{
    // 排队队列
    LinkedQueue lq;
    char input = '3';

    queue_init(&lq);

    title();

    scanf("%c", &input);

    pl("input:");

    return 0;
}
#else
// 单元测试
int main()
{
    LinkedQueue q;
    queue_init(&q);

    for (int i = 1; i <= 5; ++i)
        queue_push(&q, i * 10);   /* 入队 10 20 30 40 50 */
    queue_print(&q);

    QDataType x;
    if (queue_front(&q, &x))
        printf("front = %d\n", x);

    if (queue_rear(&q, &x))
        printf("back = %d\n", x);

    queue_print(&q);

    while (!queue_empty(&q)) {
        queue_shift(&q, &x);

        queue_print(&q);
    }
}
#endif // MAIN
