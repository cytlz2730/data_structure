#include "DoubleLinkedList.h"

//创建节点
Dnode *create_dnode(int data)
{
	Dnode *n=(Dnode*)malloc(sizeof(Dnode));
	n->data=data;
	n->prev=n;
	n->next=n;
	return n;
}

//头插法
bool insert_dnode_head(Dnode* head,Dnode* p)
{
	if(head==NULL||p==NULL) return false;
	//只有一个头节点时
	if(head->next==head)
	{
		p->next=head->next;
		p->prev=head->prev;
		head->next=p;
		head->prev=p;
		return true;
	}
	else
	{
		p->next=head->next;
		p->prev=head;
		head->next->prev=p;
		head->next=p;
		return true;
	}
}

//尾插法
bool insert_dnode_tail(Dnode* head,Dnode* p)
{
	if(head==NULL||p==NULL) return false;
	//只有一个头节点时
	if(head->next==head)
	{
		p->next=head->next;
		p->prev=head->prev;
		head->next=p;
		head->prev=p;
		return true;
	}
	else
	{
		p->next=head;
		p->prev=head->prev;
		head->prev->next=p;
		head->prev=p;
		return true;
	}
}

//删除节点
Dnode* delete_dnode(Dnode* head,int data)
{
	if(head==NULL) return NULL;
	Dnode *p=head;
	
	//如果删除的是头节点且此时只有一个节点
	if(p->data==data&&p->next==p)
	{
		free(head);
		return NULL;
	}
	//如果删除的是头节点且此时不止一个节点
	if(p->data==data&&p->next!=p)
	{
		Dnode *tail=head->prev;//最后一个节点
		tail->next=head->next;
		head->next->prev=tail;
		free(head);
		return tail->next;
	}
	//如果删除的不是头节点
	else
	{
		p=p->next;
		while(p!=head)
		{
			if(p->data==data)
			{
				p->prev->next=p->next;
				p->next->prev=p->prev;
				free(p);
				return head;
			}
			else p=p->next;
		}
	}
}

//遍历
void display_dnode(Dnode* head)
{
	if(head==NULL) 
	{
		printf("没有数据\n");
		return;
	}
	printf("display:");
	Dnode *p=head;
	do
	{
		printf("%d ",p->data);
		p=p->next;
	}while(p!=head);
	printf("\n");
}

// 销毁链表
bool destroy_dnode(Dnode *head)
{
	if (head == NULL)
		return true;

	Dnode *p = head->next;
	while (p != head)
	{
		Dnode *temp = p->next;
		free(p);
		p = temp;
	}
	free(head); // 最后释放头节点
	return true;
}

