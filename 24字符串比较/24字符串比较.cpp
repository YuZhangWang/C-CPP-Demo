#include <stdio.h>
int my_strcmp(char *p1,char *p2);

int main()
{
	char s1[100],s2[100];
	char *p1=s1,*p2=s2;
	int ren=0;
	printf("ÇëÊäÈëÁ½¸ö×Ö·û´®:");
	printf("\n");
	gets(s1);
	gets(s2);
	ren=my_strcmp(p1,p2);
	printf("%d",ren);
	printf("\n");
	return 0;
}

int my_strcmp(char *p1,char *p2)
{
	while((*p1 == *p2)&&(*p1 != '\0'))
	{
		p1++;
		p2++;
	}
	return (int)(*p1-*p2);
}