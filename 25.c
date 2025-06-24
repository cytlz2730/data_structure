#include <stdio.h>

void strip()
{
	char str[100]={0};
	scanf("%[^\n]",str);
	int i,j;
	for(int i=0;i<100;i++)
	{
		if(str[i]=='\0') break;
		if(str[i]==' ') continue;
		temp[j]=str[i];
		j++;
	}
	printf("%s\n",temp);
}

int main()
{
	strip();
}