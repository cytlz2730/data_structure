#ifndef _CLINKEDLIST_H
#define _CLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//链表节点
typedef struct CNode{
    int data;
    struct CNode* next;
}CNode;

//创建
struct CNode* create_cnode(int data);

//插入
//头插
bool  insert_cnode_head(struct CNode* head, struct CNode* newNode);

//尾插
bool insert_cnode_tail(struct CNode* head, struct CNode* newNode);

//删除节点
struct CNode* delete_cnode_by_data(struct CNode*head, int data);
//删除p->next节点
struct CNode* delete_cnode_by_pointer(struct CNode*head,struct CNode*p);

//遍历
void display_cnode(CNode* head);

//创建有环链表
CNode* create_circle();

#endif
