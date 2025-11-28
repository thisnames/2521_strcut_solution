#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

// 不带头结点的单链表队列 —— list_queue.h

// 数据元素类型
typedef int QDataType;

// 链表结点
typedef struct QNode
{
	QDataType data;
	struct QNode* next;
} QNode;

// 队列结构：只维护队头、队尾指针
typedef struct
{
	// 指向第一个有效结点
	QNode* front;
	// 指向最后一个有效结点
	QNode* back;
} LinkedQueue;

// -------------------- 接口实现 --------------------
// 初始化：空队列 front/back 均为 NULL
void queue_init(LinkedQueue* q)
{
	q->front = q->back = NULL;
}

// 判空
int queue_empty(const LinkedQueue* q)
{
	return q->front == NULL; // 或 q->back == NULL
}

// 入队；成功返回 1，失败返回 0
int queue_push(LinkedQueue* q, QDataType x)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));

	// 内存分配失败
	if (node == NULL) return 0;

	node->data = x;
	node->next = NULL;

	//  第一个元素
	if (queue_empty(q))
	{
		q->front = q->back = node;
	}
	else
	{
		// 链到旧尾结点之后
		q->back->next = node;
		// 更新尾指针
		q->back = node;
	}

	return 1;
}

// 出队；成功返回 1，失败返回 0
int queue_shift(LinkedQueue* q, QDataType* out = NULL)
{
	// 空队列
	if (queue_empty(q)) return 0;

	QNode* old_front = q->front;
	*out = old_front->data;

	// 头指针后移
	q->front = old_front->next;

	// 释放旧头结点
	free(old_front);

	// 队列变空，同步尾指针
	if (q->front == NULL) q->back = NULL;

	return 1;
}

// 取队头元素（不删除）；成功返回 1，失败返回 0
int queue_front(const LinkedQueue* q, QDataType* out)
{
	if (queue_empty(q)) return 0;

	*out = q->front->data;

	return 1;
}

// 取队尾元素（不删除）；成功返回 1，失败返回 0
int queue_back(const LinkedQueue* q, QDataType* out)
{
	if (queue_empty(q)) return 0;

	*out = q->back->data;

	return 1;
}

// 清空队列
void queue_clear(LinkedQueue* q)
{
	while (queue_shift(q));
}

// 打印队列（调试）
void queue_print(const LinkedQueue* q)
{
	printf("Queue: front -> ");

	for (QNode* p = q->front; p; p = p->next) printf("%d ", p->data);

	printf("<- back\n");
}

// 遍历队列，对每个元素执行 action 函数
void queue_foreach(const LinkedQueue* q, void (*action)(QDataType item))
{
	for (QNode* p = q->front; p; p = p->next)
	{
		if (action != NULL) action(p->data);
	}
}