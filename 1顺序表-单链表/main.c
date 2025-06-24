#include "seqList.h"
#include "sLList.h"
#include <time.h>

//#define E

int main()
{
	srand(time(NULL));

#ifdef A // 第一题
	/*
	1.设计一个顺序表，
	实现对应接口（创建销毁，插入，删除，排序-冒泡排序，显示），
	用顺序表存储一组随机数来测试接口
	*/

	Sqlist *l = createSq(15); // 创建
	for (int i = 0; i < 15; i++)
		insertSq(l, i, random() % 100); // 插入
	displaySq(l);											// 显示

	printf("需要删除什么数据，请输入:");
	int del = 0;
	scanf("%d", &del);
	deleteSq(l, del); // 删除
	displaySq(l);

	sortSq(l); // 冒泡排序
	displaySq(l);

	if (destroySq(l) == true) // 销毁
		printf("成功销毁\n");

#endif

#ifdef B // 第二题
	/*
	2.设计一个链表，
	实现对应接口（创建， 插入，删除，显示， 销毁 排序-选做),
	用链表存储一组随机数来测试接口
	*/
	Node *head = (Node *)malloc(sizeof(Node)); // 创建
	head->next = NULL;

	int len = 0;
	printf("请输入要添加数据的个数:");
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
	{
		insert_node_head(head, create_node(random() % 100)); // 插入
	}
	display_node(head); // 显示

	printf("请输入要删除的数据:");
	int del = 0;
	scanf("%d", &del);
	delete_node(head, del); // 删除
	display_node(head);

	printf("------排序后------\n");
	sort_node(head); // 排序
	display_node(head);

	if (destroy_node(head)) // 销毁
		printf("成功销毁\n");
#endif

#ifdef C // 第三题
	/*
	3.测下链表头插入10000个自然数（0-10000）并输出，
	测试链表未插入10000个自然数（0-10000）并输出，
	看看结果并说明原因
	*/

	/*
	头插法：
	插入操作每次只需要修改链表的头指针，时间复杂度为 O(1)。
	不过最终链表的顺序是反向的，即插入顺序的逆序。

	尾插法：
	尾插法每次都需要找到链表的最后一个节点才能插入，时间复杂度是 O(n)，导致在插入大量数据时效率较低。
	插入顺序与自然数顺序一致，最终链表按顺序存储数据。
	*/

	Node *head = (Node *)malloc(sizeof(Node)); // 创建
	head->next = NULL;

	printf("表头插入:\n");
	for (int i = 0; i < 10000; i++)
	{
		insert_node_head(head, create_node(i + 1)); // 插入
	}
	display_node(head); // 显示

	Node *head1 = (Node *)malloc(sizeof(Node)); // 创建
	head1->next = NULL;
	printf("\n\n表尾插入:\n");
	for (int i = 0; i < 10000; i++)
	{
		insert_node_tail(head1, create_node(i + 1)); // 插入
	}
	display_node(head1); // 显示

	if (destroy_node(head)) // 销毁
		printf("成功销毁\n");

#endif

#ifdef D // 第四题
	/*
	4.用链表存储一组数据比如1,2,3,4,5，
	请实现链表倒序变为5,4,3,2,1
	*/

	Node *head = (Node *)malloc(sizeof(Node)); // 创建
	head->next = NULL;

	int len = 0;
	printf("请输入要添加数据的个数:");
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
	{
		insert_node_head(head, create_node(random() % 100)); // 插入
	}
	display_node(head); // 显示

	printf("------翻转------\n");
	reversal_node_1(&(head));
	display_node(head);

	if (destroy_node(head)) // 销毁
		printf("成功销毁\n");

#endif

#ifdef E																		 // 交换节点，交换输入的数据的当前位置和下一个位置
	Node *head = (Node *)malloc(sizeof(Node)); // 创建
	head->next = NULL;

	int len = 0;
	printf("请输入要添加数据的个数:");
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
	{
		insert_node_head(head, create_node(random() % 100)); // 插入
	}
	display_node(head); // 显示

	printf("请输入要交换的位置的第一个数据:");
	int swap_data = 0;
	scanf("%d", &swap_data);

	printf("------交换节点------\n");
	swap_node_data(&(head), swap_data);
	display_node(head);

	if (destroy_node(head)) // 销毁
		printf("成功销毁\n");

#endif

#ifdef F	//排序（交换节点，非交换数据）
	Node *head = (Node *)malloc(sizeof(Node)); // 创建
	head->next = NULL;

	int len = 0;
	printf("请输入要添加数据的个数:");
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
	{
		insert_node_head(head, create_node(random() % 100)); // 插入
	}
	display_node(head); // 显示

	printf("------排序------\n");
	sort_node(head);
	display_node(head);

	if (destroy_node(head)) // 销毁
		printf("成功销毁\n");
#endif
}
