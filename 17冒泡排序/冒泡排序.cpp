#include <stdio.h>
#define sub 10
char g_a[10];

void bubble(char g_a[]);

int main()
{
	int i;
	printf("input %d characters :\n",sub);
	gets(g_a);
	printf("\n");
    printf("the sorted characters :\n");
    bubble(g_a);
    for(i=0;i<sub;i++)
	{
		printf("%c  ",g_a[i]);
	}
	printf("\n");
	return 0;
}

void bubble(char g_a[])
{
	int i,j;
	char temp;
    for (i=0;i<sub;i++)
	{
		for(j=0;j<sub-i-1;j++)
		{
			if(g_a[j]>g_a[j+1])
			{
				temp=g_a[j];
				g_a[j]=g_a[j+1];
				g_a[j+1]=temp;
			}
		}
	}
}