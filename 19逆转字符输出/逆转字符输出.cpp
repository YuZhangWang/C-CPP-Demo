#include <stdio.h>
#include <string.h>

void reverse(char a[]);

int main()
{
	char a[100];
	getchar(a);
	reverse(a);
	printf("%s\n",a);
	return 0;
}

void reverse(char a[])
{
	int i;
	char temp;
	int n=strlen(a);
	for (i=0;i<n;i++,n--)
	{
		temp = a[i];
		a[i] = a[n-1];
		a[n-1] = temp;
	}
}