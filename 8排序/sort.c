#include "sort.h"

// 交换数据
static void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 遍历数组
void display(int data[], int size)
{
	printf("display: ");
	for (int i = 0; i < size; i++)
		printf("%d ", data[i]);
	printf("\n");
}

// 插入排序--------------------------------------------------
void insert_sort(int data[], int size)
{
	for(int i=1;i<size;i++)
	{
		int key=data[i];
		int j=i-1;
		for(;j>-1;j--)
			if(data[j]>key)
				data[j+1]=data[j];
			else break;
		data[j+1]=key;
		printf("插入%d, ",key);
		display(data,size);
	}
}

// 冒泡排序------------------------------------------
void bubble_sort(int data[], int size)
{
	for(int i=0;i<size-1;i++)
	{
		bool done=false;
		for(int j=0;j<size-1-i;j++)
			if(data[j]>data[j+1])
			{
				swap(&data[j],&data[j+1]);
				done=true;
			}
		if(!done) break;
		printf("第%d次: ",i+1);
		display(data,size);
	}
}

// 选择排序------------------------------------
void select_sort(int data[], int size)
{
	for(int i=0;i<size;i++)
	{
		int min_i=i;
		for(int j=i+1;j<size;j++)
		{
			if(data[j]<data[min_i])
				min_i=j;
		}
		swap(&data[i],&data[min_i]);
		printf("min:%d, ",data[i]);
		display(data,size);
	}
}

// 快速排序-----------------------------------------------
//重点在于：
//1.j是--，不是++
//2.先哨兵j移动，再哨兵i移动
//3.最后i位置和0位置交换数据
static int partition(int data[],int size)
{
	if(size<=1) return 0;
	int pivot = data[0];
	int i=0,j=size-1;
	while(i<j)
	{
	
		//右边
		while(data[j]>=pivot&&i<j) {j--;/*printf("j-1, ");*/}
		//左边
		while(data[i]<=pivot&&i<j) {i++;/*printf("i+1, ");*/};
		
		//printf("i=%d, j=%d, %d和%d换位置, ",i, j,data[i],data[j]);
		//display(data,size);
		
		if(i<j) swap(&data[i],&data[j]);
	}
	
	swap(&data[0],&data[i]);
	printf("支点为:%d, ",data[i]);
	display(data,size);
	return i;	
}
// 快速排序函数
void quick_sort(int data[], int size)
{
	if(size<=1) return;
	//支点
	int pivot = partition(data,size);
	//左边递归
	quick_sort(data,pivot);
	//右边递归
	quick_sort(data+pivot+1,size-1-pivot);
}

// 希尔排序---------------------------------------------------
static void shell_insert_sort(int data[],int size,int delta)
{
	//利用插入排序
	//从第二个元素开始
	for(int i=delta;i<size;i++)
	{
		int key=data[i];
		int j=i-delta;
		//printf("插入%d前, ",key);
		//display(data,size);
		for(;j>-1;j-=delta)
		{
			if(data[j]>key)
				data[j+delta]=data[j];
			else break;
		}
		data[j+delta]=key;
		//printf("插入%d后, ",key);
		//display(data,size);
	}
}

// 希尔排序函数
void shell_sort(int data[], int size)
{
	for(int i=size/2;i>0;i/=2)
	{
		printf("delta: %d, ",i);
		display(data,size);
		shell_insert_sort(data,size,i);
	}
}
