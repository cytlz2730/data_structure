#include "bstree.h"

int main()
{
	srand(time(NULL));
	Bstree *root = create_node(random() % 100);
	
	for (int i = 0; i < 15; i++)
		root=insert_node(root, create_node(random() % 100));
	
	printf("先序遍历：");	
	display_Bstree_pre(root);
	printf("\n");

	printf("中序遍历：");	
	display_Bstree_In(root);
	printf("\n");

	printf("请输入要删除的节点的数据:");
	int del=0;
	scanf("%d",&del);
	delete_node(root,del);
	
	printf("------删除%d------\n",del);
	
	printf("先序遍历：");	
	display_Bstree_pre(root);
	printf("\n");

	printf("中序遍历：");	
	display_Bstree_In(root);
	printf("\n");
}
