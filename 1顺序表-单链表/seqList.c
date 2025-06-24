#include "seqList.h"

Sqlist *createSq(int size)
{
	Sqlist *l = (Sqlist *)malloc(sizeof(Sqlist));
	if (l == NULL)
		return l;

	l->len = 0;
	l->size = size;
	l->data = (int *)malloc(sizeof(int) * size);
	return l;
}

bool destroySq(Sqlist *sq)
{
	if (sq == NULL)
		return false;

	free(sq->data);
	free(sq);
	return true;
}

bool insertSq(Sqlist *sq, int pos, int data) // 在指定位置pos插入数据
{
	if (sq == NULL || sq->len == sq->size)
		return false;
	if (pos < 0 || pos > sq->size)
		return false;

	if (pos > sq->len - 1)
	{
		sq->data[pos] = data;
		sq->len++;
		return true;
	}

	for (int i = sq->len - 1; i > pos; i--)
		sq->data[pos + 1] = sq->data[pos];

	sq->data[pos] = data;
	sq->len++;
	return true;
}

bool deleteSq(Sqlist *sq, int data)
{
	if (sq == NULL)
		return false;

	for (int i = 0; i < sq->len - 1; i++)
		if (sq->data[i] == data)
		{
			for (int j = i; j < sq->len - 1; j++)
				sq->data[j] = sq->data[j + 1];
			sq->len--;
			return true;
		}
	return false;
}

void displaySq(Sqlist *sq)
{
	printf("display:");
	for (int i = 0; i < sq->len; i++)
		printf("%d ", sq->data[i]);
	printf("\n");
}

void sortSq(Sqlist *sq)
{
	for (int i = 0; i < sq->len - 1; i++)
		for (int j = 0; j < sq->len - 1 - i; j++)
			if (sq->data[j] > sq->data[j + 1])
			{
				int temp = sq->data[j];
				sq->data[j] = sq->data[j + 1];
				sq->data[j + 1] = temp;
			}
}
