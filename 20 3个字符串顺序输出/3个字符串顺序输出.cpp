#include <stdio.h>
#include <string.h>
void swap(char *p1,char *p2,char *p3);

int main()
{
	char str1[100],str2[100],str3[100];
    char *p1=str1,*p2=str2,*p3=str3;
	printf("ÇëÊäÈëÈý¸ö×Ö·û´®:");
	printf("\n");

	
	gets(str1);
	gets(str2);
	gets(str3);
	
	swap(p1,p2,p3);
	
	printf("%s  %s  %s",str1,str2,str3);
	printf("\n");
	return 0;
}

void swap(char *p1,char *p2,char *p3)
{
	char temp[100];
	
	if(strcmp(p1,p2)>0)
	{
        strcpy(temp,p1);
        strcpy(p1,p2);
        strcpy(p2,temp);
	}
	
	if(strcmp(p1,p3)>0)
	{
        strcpy(temp,p1);
        strcpy(p1,p3);
        strcpy(p3,temp);
	}
	
	if(strcmp(p2,p3)>0)
	{
        strcpy(temp,p2);
        strcpy(p2,p3);
        strcpy(p3,temp);
	}
}