#include "stack.h"

struct Node* create_stack(int data)//创建栈节点
{
	Node *n=malloc(sizeof(Node));
	if(n==NULL) return n;
	n->next=NULL;
	n->data=data;
	return n;
}

bool destroy_stack(struct Node** top) //销毁栈---考虑栈还有多个元素
{
//	Node *p=*top;
	if(*top==NULL) return true;
	while(*top!=NULL)
	{
		pop_stack(top);
	}
	return true;
}

bool push_stack(struct Node** top,  int data) //入栈
{
	Node *node=create_stack(data);
	if(node==NULL) return false;
	node->next=*top;
	*top=node;
	return true;
}

int stack_top(struct Node *top)//获取栈顶元素--不出栈
{
	//如果没有元素
	if(top==NULL) return -1;
	else return top->data;
}

bool pop_stack(struct Node** top)//出栈--把栈顶元素删除
{
	if(*top==NULL) return false;
	Node *p=*top;
	*top=p->next;
	free(p);
	return true;
}

void display_stack(Node *top)//遍历
{
	if(top==NULL) 
	{
		printf("没有元素\n");
		return;
	}
	printf("display:");
	Node *p=top;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
