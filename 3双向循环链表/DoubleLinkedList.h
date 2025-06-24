#ifndef _DOUBLELINKEDLIST_H
#define _DOUBLELINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct Dnode
{
	int data;
	struct Dnode *prev;
	struct Dnode *next;
}Dnode;

//创建节点
Dnode *create_dnode(int data);

//头插法
bool insert_dnode_head(Dnode* head,Dnode* p);

//尾插法
bool insert_dnode_tail(Dnode* head,Dnode* p);

//删除节点
Dnode* delete_dnode(Dnode* head,int data);

//遍历
void display_dnode(Dnode* head);

// 销毁链表
bool destroy_dnode(Dnode *head);
#endif
