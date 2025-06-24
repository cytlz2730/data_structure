#ifndef _SEQLIST_H
#define _SEQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	int len;
	int size;
	int *data;
} Sqlist;

// 设计操作顺序表的接口
Sqlist *createSq(int size);

bool destroySq(Sqlist *sq);

bool insertSq(Sqlist *sq, int pos, int data); // 在指定位置pos插入数据

bool deleteSq(Sqlist *sq, int data);

void displaySq(Sqlist *sq);

void sortSq(Sqlist *sq);
#endif
