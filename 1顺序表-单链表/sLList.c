#include "sLList.h"

// 创建节点--链表
struct Node *create_node(int data)
{
	Node *e = (Node *)malloc(sizeof(Node));
	if (e == NULL)
		return e;

	e->data = data;
	e->next = NULL;
	return e;
}

// 销毁链表
bool destroy_node(struct Node *head)
{
	if (head == NULL)
		return true;

	Node *p = head->next;
	Node *temp = NULL;
	while (p != NULL)
	{
		temp = p->next;
		free(p);
		p = temp;
	}

	head->next = NULL;
	return true;
}

// 插入节点
bool insert_node_head(struct Node *head, struct Node *newNode) // 头插法
{
	if (head == NULL || newNode == NULL)
		return false;

	newNode->next = head->next;
	head->next = newNode;
	return true;
}

bool insert_node_tail(struct Node *head, struct Node *newNode) // 尾插法
{
	if (head == NULL || newNode == NULL)
		return false;

	Node *p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = newNode;
	return true;
}

// 删除节点
bool delete_node(struct Node *head, int data)
{
	if (head == NULL || head->next == NULL)
		return false;

	Node *p = head;
	while (p->next != NULL &&
				 p->next->data != data)
		p = p->next;
	if (p->next == NULL)
		return false;
	Node *r = p->next;
	p->next = p->next->next;
	free(r);
	return true;
}

// 遍历节点
void display_node(struct Node *head)
{
	Node *p = head->next;
	printf("display:");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

// 冒泡排序
bool sort_node(struct Node *head)
{
	bool flag = false;
	if(head==NULL) return false;

	do
	{
		flag = false;
		Node *p = head;
		if(p==NULL) return true;
		while (p->next != NULL&&p->next->next!=NULL)
		{
			if (p->next->data > p->next->next->data)
			{ 
			// 只交换节点的数据
/*				int temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
*/
				swap_node(&p);
				flag = true;
				// display_node(head);
			}
			p = p->next;
		}
	} while (flag);
}

// 反转
void reversal_node(Node **head)//此时的head为head->next
{
	Node *prev = NULL;
	Node *curr = *head;
	Node *next = NULL;

	while (curr != NULL)
	{
		next = curr->next; // 保存下一个节点
		curr->next = prev; // 当前节点的next指向前一个节点
		prev = curr;			 // prev向后移动
		curr = next;			 // curr向后移动
	}

	*head = prev; // 重新设置头节点
}

// 自己写的翻转链表代码
void reversal_node_1(Node **head)
{
	Node *p = (*head)->next;
	Node *r = p->next;
	p->next = NULL;
	Node *temp = NULL;
	while (r != NULL)
	{
		temp = r->next;
		r->next = p;
		p = r;
		r = temp;
	}
	(*head)->next = p;
}

// 自己写的交换节点代码
// 交换data这个节点和data的下一个节点
bool swap_node_data(Node **head, int data)
{
	Node *p = (*head);
	while (p != NULL && p->next != NULL)
	{
		if(p->next->next==NULL) return false;
		if (p->next->data == data)
		{
			swap_node(&p);
			return true;
		}
		p = p->next;
	}
	return false;
}

//自己写的
//交换节点的核心代码
//交换的是p->next和p->next->next
bool swap_node(Node **p)
{
	Node *r = (*p)->next;		//⭐⭐更改后续指针之前保存后续指针的值
	Node *q = r->next;
	r->next = q->next;
	q->next = r;
	(*p)->next=q;
	return true;
}
