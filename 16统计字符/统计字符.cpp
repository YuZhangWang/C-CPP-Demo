#include <stdio.h>
#include <string.h>
int g_English=0;
int g_Space=0;
int g_Number=0;
int g_Others=0;

void sum(char a[]);

int main()
{
	char a[100];
	printf("ÇëÊäÈëÒ»´®×Ö·û:");
	gets(a);
	sum(a);
	printf("Englishi=%d\n",g_English);
	printf("Space=%d\n",g_Space);
	printf("Number=%d\n",g_Number);
	printf("Others=%d\n",g_Others);
	return 0;
}

void sum(char a[])
{
	int i;
	int n=strlen(a);
	for(i=0;i<n;i++)
	{
		if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
			g_English++;
		else if(a[i]==' ')
			g_Space++;
		else if(a[i]>='0'&&a[i]<='9')
			g_Number++;
		else
			g_Others++;
	}
}