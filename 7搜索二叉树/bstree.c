#include "bstree.h"

// 创建节点
Bstree *create_node(int data)
{
	Bstree *node = malloc(sizeof(Bstree));
	node->data = data;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}

// 插入节点
Bstree *insert_node(Bstree *root, Bstree *node)
{
	if (root == NULL)
	{
		return node;
	}
	if (root->data >= node->data)
	{
		root->lchild = insert_node(root->lchild, node);
	}
	else
	{
		root->rchild = insert_node(root->rchild, node);
	}
	return root;
}

// 删除节点
Bstree *delete_node(Bstree *root, int data)
{
	// 开始寻找要删除的节点
	if (root == NULL)
		return NULL;
	// 如果当前值比要寻找的大，寻找左子树
	else if (root->data > data)
		root->lchild = delete_node(root->lchild, data);
	// 如果当前值比要寻找的小，寻找右子树
	else if (root->data < data)
		root->rchild = delete_node(root->rchild, data);
	// 如果找到了
	else
	{
		// 删除叶子节点，直接删除
		if (root->lchild == NULL && root->rchild == NULL)
		{
			free(root);
			return NULL;
		}
		//删除非叶子节点
		//a. 根节点若有左子树，则用左子树中最大的节点max替换根节点，并在左子树中递归删除max
		//b. 否则，若有右子树，则用右子树中最小的节点min替换根节点，并在右子树中递归删除min
		
		//存在左子树
		else if(root->lchild!=NULL)
		{
			Bstree *max=root->lchild;
			while(max->rchild!=NULL)
			{
				max=max->rchild;
			}
			root->data=max->data;
			root->lchild=delete_node(root->lchild,max->data);
		}
		
		//存在右子树
		else
		{
			Bstree *min=root->rchild;
			while(min->lchild!=NULL)
			{
				min=min->lchild;
			}
			root->data=min->data;
			root->rchild=delete_node(root->rchild,min->data);
		}
	}
	return root;
}

// 中序遍历
void display_Bstree_In(Bstree *root)
{
	if (root == NULL)
		return;
	display_Bstree_In(root->lchild);
	printf("%d ", root->data);
	display_Bstree_In(root->rchild);
}

// 先序遍历
void display_Bstree_pre(Bstree *root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	display_Bstree_pre(root->lchild);
	display_Bstree_pre(root->rchild);
}
