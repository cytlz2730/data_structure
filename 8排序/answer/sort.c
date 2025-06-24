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
	for (int i = 1; i < size; i++)
	{
		int key = data[i];
		int j = i - 1;
		for (; j > -1; j--)
		{
			// 如果大于key就往后挪
			if (key < data[j])
				data[j + 1] = data[j];
			else
				break;
		}
		data[j + 1] = key;

		printf("插入%d--", key);

		display(data, size);
	}
}

// 冒泡排序------------------------------------------
void bubble_sort(int data[], int size)
{
	bool done = false;
	for (int i = 0; i < size - 1; i++)
	{
		done = false;
		for (int j = 0; j < size - 1 - i; j++)
			if (data[j] > data[j + 1])
			{
				swap(&data[j], &data[j + 1]);
				done = true;
			}

		if (!done)
			break;
		printf("第%d次排序: ", i + 1);
		display(data, size);
	}
}

// 选择排序------------------------------------
void select_sort(int data[], int size)
{
	int min_i = 0;
	for (int i = 0; i < size - 1; i++)
	{
		min_i = i;
		for (int j = i + 1; j < size; j++)
		{
			if (data[j] < data[min_i])
				min_i = j;
		}
		printf("min为%d, ", data[min_i]);
		swap(&data[i], &data[min_i]);
		display(data, size);
	}
}

// 快速排序-----------------------------------------------
static int partition(int data[], int size)
{
	if (size <= 1)
		return 0;
	int i = 0, j = size - 1;
	int pivot = data[0];

	while (i < j)
	{
		while (data[j] >= pivot && i < j)
			j--;
		while (data[i] <= pivot && i < j)
			i++;
		if (i < j)
			swap(&data[i], &data[j]);
	}

	swap(&data[0], &data[i]);

	printf("支点:%d, ", pivot);
	display(data, size);

	return i;
}

// 快速排序函数
void quick_sort(int data[], int size)
{
	if (size <= 1)
		return;

	int pivot = partition(data, size);

	quick_sort(data, pivot);
	quick_sort(data + pivot + 1, size - 1 - pivot);
}

// 希尔排序---------------------------------------------------
static void shell_insert_sort(int data[], int size, int delta)
{
	for (int i = delta; i < size; i++)
	{
		int key=data[i];
		int j=i;
		//j合法并且当前数字大于key时，当前数字往后挪
		while(j>=delta&&data[j-delta]>key)
		{
			data[j]=data[j-delta];
			j -= delta;
		}
		data[j]=key;
	}

	printf("Δ为%d, ", delta);
	display(data, size);
}

// 希尔排序函数
void shell_sort(int data[], int size)
{
	for (int i = size / 2; i > 0; i/=2)
		shell_insert_sort(data, size, i);
}
