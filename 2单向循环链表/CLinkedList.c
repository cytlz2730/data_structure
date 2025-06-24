#include "CLinkedList.h"

//创建
struct CNode* create_cnode(int data)
{
	CNode *n=(CNode*)malloc(sizeof(CNode));
	if(n==NULL) return n;
	n->data=data;
	n->next=n;
	return n;
}

//插入
//头插
bool  insert_cnode_head(struct CNode* head, struct CNode* newNode)
{
	if(head==NULL||newNode==NULL) return false;
	newNode->next=head->next;
	head->next=newNode;
	return true;
}

//尾插
bool insert_cnode_tail(struct CNode* head, struct CNode* newNode);

//删除节点
struct CNode* delete_cnode_by_data(struct CNode*head, int data)
{
	CNode *p=head;
	if(p==NULL) return head;
	//如果要删除头节点
	else if(head->data==data)
	{
		while(p!=NULL&&p->next!=head) p=p->next;
		p->next=head->next;
		free(head);
		return p->next;
	}
	//如果删除的不是头节点
	else
	{
		while(p->next!=head)
		{
			if(p->next->data==data)
			{
				CNode *r=p->next;
				p->next=p->next->next;
				free(r);
				return head;
			}
			else p=p->next;
		}
	}
}

//删除p->next节点
struct CNode* delete_cnode_by_pointer(struct CNode*head,struct CNode*p)
{
	if(head==NULL) return head;
	//如果要删除头节点
	else if(p->next==head)
	{
		p->next=head->next;
		free(head);
		return p->next;
	}
	//如果删除的不是头节点
	else
	{	
		CNode *r=p->next;
		p->next=p->next->next;
		free(r);
		return head;
	}
}

//遍历
void display_cnode(CNode* head)
{
	if(head==NULL) return;
	printf("display:");
	CNode *p=head;
	do
	{
		printf("%d ",p->data);
		p=p->next;
	}while(p!=head);
	printf("\n");
}

//创建有环链表
CNode* create_circle(CNode* head)
{
	CNode *p1=(CNode*)malloc(sizeof(CNode));
	p1->data=random()%100;
	p1->
}
