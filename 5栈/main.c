#include "stack.h"

int  main()
{
	Node *top;
	top=NULL;
	for(int i=0;i<8;i++)
		push_stack(&top,i);
	display_stack(top);
	
	printf("栈顶元素为:%d\n",stack_top(top));
	
	printf("---出栈---");
	pop_stack(&top);
	display_stack(top);
	
	destroy_stack(&top);
	
	display_stack(top);
}
