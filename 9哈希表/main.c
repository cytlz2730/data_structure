#include "hash.h"

int main()
{
	int size=10;
	int data[size];
	for(int i=0;i<size;i++)
		data[i]=random()%100;
	for(int i=0;i<size;i++)
		printf("%d ",data[i]);
	printf("\n");

	return 0;
}
