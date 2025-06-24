#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h> // for memcpy

//遍历数组
void display(int data[],int size);

//插入排序
void insert_sort(int data[],int size);

//冒泡排序
void bubble_sort(int data[],int size);

//选择排序
void select_sort(int data[],int size);

//快速排序
void quick_sort(int data[],int size);

//希尔排序
void shell_sort(int data[],int size);
