#ifndef _BSTREE_H
#define _BSTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Bstree
{
	int data;
	struct Bstree *lchild;
	struct Bstree *rchild;
}Bstree;

//创建节点
Bstree *create_node(int data);

//插入节点
Bstree *insert_node(Bstree *root,Bstree *node);

//删除节点
Bstree *delete_node(Bstree *root,int data);

//中序遍历
void display_Bstree_In(Bstree *root);

//先序遍历
void display_Bstree_pre(Bstree *root);

#endif
