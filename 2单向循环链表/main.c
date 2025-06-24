#include "CLinkedList.h"

#define B

int main()
{
#ifdef A // 第一题
	/*
	1.设计一个链表存储1-15自然数 ，
	实现从头开始1,2,3第三个节点删除，
	后面继续数1,2,3，
	删除数到3所在的节点以此类推，
	最后剩下的一个节点输出
	*/
	CNode *head = create_cnode(1);
	for (int i = 15; i > 1; i--)
	{
		insert_cnode_head(head, create_cnode(i));
	}
	display_cnode(head);

	CNode *p = head;
	int flag = 0;
	while (p->next != p)
	{
		flag++;
		if (flag == 2)
		{
			printf("delete:%d,\t", p->next->data);
			head = delete_cnode_by_pointer(head, p);
			display_cnode(head);
			flag = 0;
		}
		p = p->next;
	}
	printf("result:\t\t");
	display_cnode(head);

	/*
		printf("请输入你要删除的数据:");
		int del = 0;
		scanf("%d", &del);
		head = delete_cnode_by_data(head, del);
		display_cnode(head);
	*/

#endif

#ifdef B // 第二题
				 /*
				 2.检测一个单链表是否存在环（思考---面试问题）
				 */
	// 快慢速度问题

	srand(time(NULL));

	// 有环链表
	CNode *p1;

	// 无环链表

#endif
}
