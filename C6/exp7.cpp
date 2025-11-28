#define MAIN

#define PROGRAM_TITLE	"#===================== 病人看病模拟程序 =====================#"
#define TTTLE_END_LINE	"#===========================================================#"

#define CONTENT_1_TITLE	"1：排队"
#define CONTENT_1		"\t——输入排队病人的就诊卡号，加入到病人排队的队列中。"

#define CONTENT_2_TITLE "2：就诊"
#define CONTENT_2		"\t——病人排队队列中最前面的病人就诊，并将其中队列中删除。"

#define CONTENT_3_TITLE "3：查看排队"
#define CONTENT_3		"\t——从队首到队尾输出所有的排队病人的就诊卡号。"

#define CONTENT_4_TITLE "4：不再排队"
#define CONTENT_4		"\t——余下的依次就诊从队首到队尾输出所有的排队病人的就诊卡号，看完病后，退出运行。"

#define CONTENT_5_TITLE "5：下班"
#define CONTENT_5		"\t——退出运行。"

#include <stdio.h>

#include "link_queue.h"
#include "my_tools.h"

// 清屏
void clear_screen()
{
	system("cls");
}

// 打印标题
void title()
{
	pl(PROGRAM_TITLE);

	pl(CONTENT_1_TITLE);
	pl(CONTENT_1);

	pl(CONTENT_2_TITLE);
	pl(CONTENT_2);

	pl(CONTENT_3_TITLE);
	pl(CONTENT_3);

	pl(CONTENT_4_TITLE);
	pl(CONTENT_4);

	pl(CONTENT_5_TITLE);
	pl(CONTENT_5);

	pl(TTTLE_END_LINE);
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
	if (!get_sizet_input("请输入你的就诊卡号：", &car))
	{
		pl("无效卡号！");
		return;
	}

	// 已存在
	if (Exist(lq, car))
	{
		pl("卡号 %d 已经在队列中，无需重复排队！", car);
		return;
	}

	// 入队
	if (queue_push(lq, car))
	{
		pl("卡号 %d 入队成功！", car);
	}
	else
	{
		pl("入队失败！");
	}
}

// 查看排队
void DispQueue(LinkedQueue* lq)
{
	if (queue_empty(lq))
	{
		pl("当前没有人在排队！");
		return;
	}

	printf("当前排队：");
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
		pl("就诊的病人是：%d", car);
	}
	else
	{
		pl("当前没有病人排队！");
	}
}

// 不再排队
void AllCompletes(LinkedQueue* lq)
{
	if (queue_empty(lq))
	{
		pl("当前没有人在排队！");
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
		pl("------ 大屏显示 ------");
		DispQueue(lq);
		pl("----------------------");

		// 标题
		title();

		// 监听用户输入
		get_sizet_input("请输入你的选择：", &input);
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
			get_sizet_input("就诊结束！按回车键退出", &sleep);
			break;
		}
		else if (input == 5)
		{
			// 退出
			pl("程序退出！");
			if (input == 5) break;
		}
		else
		{
			pl(":( 输入错误，请重新输入！");
			pl("");
		}

		// 暂停
		pl("");
		get_sizet_input("^_^ 按下键回车继续操作...", &sleep);

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
