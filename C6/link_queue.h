#pragma once
#include <stddef.h>   /* NULL */
#include <stdlib.h>   /* malloc/free */
#include <stdio.h>    /* printf */

// 不带头结点的单链表队列 —— list_queue.h *

/* 数据元素类型，可按需修改 */
typedef int QDataType;

/* 链表结点 */
typedef struct QNode {
    QDataType      data;
    struct QNode* next;
} QNode;

/* 队列结构：只维护队头、队尾指针 */
typedef struct {
    QNode* front;   /* 指向第一个有效结点 */
    QNode* back;    /* 指向最后一个有效结点 */
} LinkedQueue;

/* 基本操作声明 */
void queue_init(LinkedQueue* q);            /* 初始化队列 */
int  queue_empty(const LinkedQueue* q);     /* 判空：1-空 0-非空 */
int  queue_push(LinkedQueue* q, QDataType x);/* 入队，成功返回 1，失败返回 0 */
int  queue_shift(LinkedQueue* q, QDataType* out);/* 出队，成功返回 1，失败返回 0 */
int  queue_front(const LinkedQueue* q, QDataType* out);/* 取队头元素，成功返回 1 */
int  queue_rear(const LinkedQueue* q, QDataType* out);/* 取队尾元素，成功返回 1 */
void queue_clear(LinkedQueue* q);           /* 清空队列 */
void queue_print(const LinkedQueue* q);     /* 打印队列（调试用） */

/* -------------------- 接口实现 -------------------- */
/* 初始化：空队列 front/back 均为 NULL */
void queue_init(LinkedQueue* q) 
{
    q->front = q->back = NULL;
}

/* 判空 */
int queue_empty(const LinkedQueue* q) 
{
    return q->front == NULL;   /* 也可写 q->back == NULL */
}

/* 入队 */
int queue_push(LinkedQueue* q, QDataType x)
{
    QNode* node = (QNode*)malloc(sizeof(QNode));

    if (node == NULL) return 0;      /* 内存分配失败 */

    node->data = x;
    node->next = NULL;

    if (queue_empty(q)) {            /* 第一个元素 */
        q->front = q->back = node;
    }
    else {
        q->back->next = node;        /* 链到旧尾结点之后 */
        q->back = node;              /* 更新尾指针 */
    }

    return 1;
}

/* 出队 */
int queue_shift(LinkedQueue* q, QDataType* out = NULL) 
{
    if (queue_empty(q)) return 0;    /* 空队列 */

    QNode* old_front = q->front;
    *out = old_front->data;
    q->front = old_front->next;      /* 头指针后移 */

    free(old_front);                 /* 释放旧头结点 */

    if (q->front == NULL)            /* 队列变空，同步尾指针 */
        q->back = NULL;

    return 1;
}

/* 取队头元素（不删除） */
int queue_front(const LinkedQueue* q, QDataType* out)
{
    if (queue_empty(q)) return 0;

    *out = q->front->data;

    return 1;
}

/* 取队尾元素（不删除） */
int queue_rear(const LinkedQueue* q, QDataType* out)
{
    if (queue_empty(q)) return 0;

    *out = q->back->data;

    return 1;
}

/* 清空队列 */
void queue_clear(LinkedQueue* q)
{
    while (!queue_empty(q)) queue_shift(q);
}

/* 打印队列（调试） */
void queue_print(const LinkedQueue* q) 
{
    printf("Queue: front -> ");

    for (QNode* p = q->front; p; p = p->next) printf("%d ", p->data);

    printf("<- back\n");
}