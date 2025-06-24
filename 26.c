#include <stdio.h>

char reveral(char c)
{
	unsigned char result = '\0';
	for (int i = 0; i < 8; i++)
	{
		result <<= 1;
		result |= (c & 1);
		c >>= 1;
	}
	printf("result:%x\n", result);
	return result;
}

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	char A[n], B[n];
	for (int i = 0; i < n; i++)
		scanf("%c", &A[i]);

	for (int i = 0; i < n; i++)
		printf("%x ", A[i]);
	printf("\n");

	for (int i = 0; i < n; i++)
		B[i] = reveral(A[i]);
	for (int i = 0; i < n; i++)
		printf("%x ", B[i]);

	printf("\n");

	return 0;
}