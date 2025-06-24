#include "DoubleLinkedList.h"

int main()
{
	Dnode *head=create_dnode(1);
	
	//for(int i=15;i>1;i--)
	//	insert_dnode_head(head,create_dnode(i));
	//for(int i=0;i<5;i++)
	//	insert_dnode_tail(head,create_dnode(i));
	display_dnode(head);
	
	//printf("请输入要删除的数据:");
	int del=0;
	//scanf("%d",&del);
	//head=delete_dnode(head,del);
	
	//display_dnode(head);
	
	destroy_dnode(head);
	display_dnode(head);
}
