#ifndef _SLLIST_H
#define _SLLIST_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
      int data;          // 数据域
      struct Node *next; // 指针域
} Node;

// 创建节点--链表
struct Node *create_node(int data);

// 销毁链表
bool destroy_node(struct Node *head);

// 插入节点
bool insert_node_head(struct Node *head, struct Node *newNode); // 头插法

bool insert_node_tail(struct Node *head, struct Node *newNode); // 尾插法

// 删除节点
bool delete_node(struct Node *head, int data);

// 遍历节点
void display_node(struct Node *head);

// 排序
bool sort_node(struct Node *head);

// 反转
void reversal_node(struct Node **head);

// 反转（自己写的）
void reversal_node_1(struct Node **head);

// 自己写的交换节点代码
bool swap_node_data(Node **head,int data);

//自己写的
//交换节点的核心代码
bool swap_node(Node **p);
#endif
