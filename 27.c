#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void move(char str[], int n)
{
	for (int i = 0; i < n; i++)
	{
		char temp1;
		int j = 0;
		while (1)
		{
			if (str[j + 1] == '\0')
			{
				str[0] = temp1;
				break;
			}
			if (j == 0)
			{
				temp1 = str[1];
				str[1] = str[0];
				//printf("%s\n", str);
			}
			else
			{
				char temp2 = str[j + 1];
				str[j + 1] = temp1;
				temp1 = temp2;
				// printf("%s\n", str);
			}
			j++;
		}
	}
}

int main(void)
{
	char str[] = "abcdefghi";
	move(str, 6);
	printf("%s\n", str);
	return 0;
}
