#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    struct Node *next;
    int data;    
}Node;

struct Node* create_stack(int data);//创建栈节点

bool destroy_stack(struct Node** top); //销毁栈---考虑栈还有多个元素

bool push_stack(struct Node** top,  int data); //入栈

int stack_top(struct Node *top);//获取栈顶元素--不出栈

bool pop_stack(struct Node** top);//出栈--把栈顶元素删除

void display_stack(Node *top);//遍历
#endif
