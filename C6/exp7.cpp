#define LANUAGE 0
#define MAIN 1
#define CL_SCREEN_CMD "cls"

#include <stdio.h>

#include "link_queue.h"
#include "my_tools.h"

// 选择语言文件
#if LANUAGE == 0
// 使用中文语言（默认）
#include "ln_zh_cn.h"
#elif LANUAGE == 1
// 使用英文语言
#include "ln_en_us.h"
#else
#include "ln_zh_cn.h"
#endif

// 清屏
void clear_screen()
{
	system(CL_SCREEN_CMD);
}

// 打印标题
void title()
{
	pl(program_title);

	pl(menu_title_1);
	pl(menu_desct_1);

	pl(menu_title_2);
	pl(menu_desct_2);

	pl(menu_title_3);
	pl(menu_desct_3);

	pl(menu_title_4);
	pl(menu_desct_4);

	pl(menu_title_5);
	pl(menu_desct_5);

	pl(program_tline);
}

// 排队的卡号是否已经在队列中排队；存在返回1，否则返回0
int Exist(LinkedQueue* lq, QDataType id)
{
	// 队列为空，直接返回 0
	if (queue_empty(lq)) return 0;

	// 遍历队列
	for (QNode* p = lq->front; p; p = p->next) if (p->data == id) return 1;

	return 0;
}

// 进队
void InQueue(LinkedQueue* lq)
{
	// 输入卡号
	size_t car;

	// 输入失败
	if (!get_sizet_input(inqueue_prompt, &car))
	{
		pl(inqueue_invcar);
		return;
	}

	// 已存在
	if (Exist(lq, car))
	{
		pl(inqueue_exist, car);
		return;
	}

	// 入队
	if (queue_push(lq, car))
	{
		pl(inqueue_in, car);
	}
	else
	{
		pl(inqueue_fail);
	}
}

// 查看排队
void DispQueue(LinkedQueue* lq)
{
	if (queue_empty(lq))
	{
		pl(diqueue_empty);
		return;
	}

	printf(diqueue_queue);
	//queue_foreach(lq, [](QDataType item)-> void { printf("%d ", item); });

	for (QNode* p = lq->front; p; p = p->next) printf("%d ", p->data);

	pl("");
}

// 就诊出队
void OutQueue(LinkedQueue* lq)
{
	// 卡号
	QDataType car;

	if (queue_shift(lq, &car))
	{
		pl(poqueue_out, car);
	}
	else
	{
		pl(poqueue_empty);
	}
}

// 不再排队
void AllCompletes(LinkedQueue* lq)
{
	if (queue_empty(lq))
	{
		pl(unqueue_empty);
		return;
	}

	// 遍历队列
	while (!queue_empty(lq)) OutQueue(lq);
}

// 销毁队列
void DestroyQueue(LinkedQueue* lq)
{
	queue_clear(lq);
}

// 操作菜单
void SeeDoctor(LinkedQueue* lq)
{
	// 循环执行
	while (true)
	{
		// 输入
		size_t input = 0;
		size_t sleep = 0;

		// 大屏
		pl("------ %s ------", option_plane);
		DispQueue(lq);
		pl("----------------------");

		// 标题
		title();

		// 监听用户输入
		get_sizet_input(option_select, &input);
		//pl("你的选择是：%d", input);

		if (input == 1)
		{
			InQueue(lq);
		}
		else if (input == 2)
		{
			OutQueue(lq);
		}
		else if (input == 3)
		{
			DispQueue(lq);
		}
		else if (input == 4)
		{
			AllCompletes(lq);
			DestroyQueue(lq);
			get_sizet_input(option_end, &sleep);
			break;
		}
		else if (input == 5)
		{
			// 退出
			pl(option_exit);
			if (input == 5) break;
		}
		else
		{
			pl(":( %s", option_error);
			pl("");
		}

		// 暂停
		pl("");
		get_sizet_input(option_continue, &sleep);

		// 清除屏幕
		clear_screen();
	}

}

#ifdef MAIN
// 程序入口
int main(void)
{
	// 排队队列
	LinkedQueue lq;

	// 初始化队列
	queue_init(&lq);

	SeeDoctor(&lq);

	return 0;
}
#else
// 单元测试
int main()
{
	LinkedQueue q;
	queue_init(&q);

	for (int i = 1; i <= 5; ++i)
		queue_push(&q, i * 100);   // 入队 10 20 30 40 50
	queue_print(&q);

	QDataType x;
	if (queue_front(&q, &x))
		printf("front = %d\n", x);

	if (queue_back(&q, &x))
		printf("back = %d\n", x);

	queue_print(&q);

	pl("front:");
	queue_foreach(&q, [](QDataType item)-> void { pl("%d ", item); });
	pl("back:");

	queue_print(&q);

	QDataType temp;
	while (!queue_empty(&q))
	{
		queue_shift(&q, &temp);

		pl("shift: %d", temp);

		if (queue_front(&q, &x))
			printf("front = %d\n", x);

		if (queue_back(&q, &x))
			printf("back = %d\n", x);

		queue_print(&q);
	}

	pl("front:");
	queue_foreach(&q, [](QDataType item)-> void { pl("%d ", item); });
	pl("back:");
}
#endif // MAIN
