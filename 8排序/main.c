#include "sort.h"

//#define _INSERT_SORT
//#define _BUBBLE_SORT
//#define _SELECT_SORT
//#define _QUICK_SORT
//#define _SHELL_SORT

int main()
{
	srand(time(NULL));
	int original[10];
	int size=10;
	for(int i=0;i<size;i++)
		original[i]=random()%100;

	//遍历
	printf("原始数组: ");
	display(original,size);
			
//#ifdef _INSERT_SORT
	{
		int data[10];
		memcpy(data, original, sizeof(original));
		printf("\n------------插入排序开始------------\n");
		insert_sort(data,size);
		//遍历
		printf("结果：");
		display(data,size);
	}

//#endif

//#ifdef _BUBBLE_SORT
	{
		int data[10];
		memcpy(data, original, sizeof(original));
		printf("\n------------冒泡排序开始------------\n");
		bubble_sort(data,size);
		printf("结果：");
		display(data,size);
	}
//#endif

//#ifdef _SELECT_SORT
	{
		int data[10];
		memcpy(data, original, sizeof(original));
		printf("\n------------选择排序开始------------\n");
		select_sort(data,size);
		printf("结果：");
		display(data,size);
	}
	
//#endif

//#ifdef _QUICK_SORT
	{
		int data[10];
		memcpy(data, original, sizeof(original));
		printf("\n------------快速排序开始------------\n");
		quick_sort(data,size);
		printf("结果：");
		display(data,size);
	}
	
//#endif

//#ifdef _SHELL_SORT
	{
		int data[10];
		memcpy(data, original, sizeof(original));
		printf("\n------------希尔排序开始------------\n");
		shell_sort(data,size);
		printf("结果：");
		display(data,size);
	}
	
//#endif

	
	
	return 0;
}
