#include <stdio.h>
#include "SLinkNode.h"


//（1）逆向输出单链表中的所有结点值
void rev_prints(SLinkNode* list)
{
	if (list == NULL) return;
	rev_prints(list->next);
	printf("%d ", list->data);
}

//（2）计算单链表中结点个数
int get_list_len(SLinkNode* list)
{
	return list ? 1 + get_list_len(list->next) : -1;
}

//（3）找最大值结点
SLinkNode* find_max(SLinkNode* list)
{
	if (list == NULL) return NULL;
	SLinkNode* max_node = find_max(list->next);
	return (max_node == NULL || list->data > max_node->data) ? list : max_node;
}

//（4）删除单链表中所有值为x的结点
SLinkNode* del_x(SLinkNode* list, ElemType x)
{
	if (list == NULL) return NULL;
	list->next = del_x(list->next, x);
	if (list->data == x)
	{
		SLinkNode* new_head = list->next;
		free(list);
		return new_head;
	}
}

int main()
{
	SLinkNode* list;
	ElemType list_data[] = { 1, 20, 3, 4, 5, 3, 6, 70, 8, 9, 10, 3};
	size_t list_len = sizeof(list_data) / sizeof(ElemType);

	// 创建单链表
	CreateListR(list, list_data, list_len);
	printf("单链表：");
	DispList(list);

	//（1）逆向输出单链表中的所有结点值
	printf("（1）逆向输出单链表中的所有结点值：");
	rev_prints(list);
	printf("\n");

	//（2）计算单链表中结点个数
	int list_count = get_list_len(list);
	printf("（2）计算单链表中结点个数：%d\n", list_count);


	//（3）找最大值结点
	SLinkNode* max_node = find_max(list);
	printf("（3）找最大值结点：%d\n", max_node->data);
	

	//（4）删除单链表中所有值为x的结点
	ElemType x = 3;
	del_x(list, x);
	printf("（4）删除单链表中所有值为 %d 的结点：", x);
	DispList(list);

	return 0;
}