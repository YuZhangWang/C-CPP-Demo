#include<stdio.h>
void copy(char *string,int n,int m);

int main()
{ 
    int n,m;
    char string[100];
	
    printf("�������ַ�������:\n");
    scanf("%d",&n);
	printf("������һ���ַ���:\n");
    scanf("%s",&string);
	printf("������ӵڼ�����ʼ����:\n");
    scanf("%d",&m);
	
	copy(string,n,m); 
	return 0;
}

void copy(char *str,int n,int m)
{
	int i,j;
	char string[100];
	char *p = string;
	for(i = m-1,j = 0;i<n;i++,j++)
	{
		*(p+j) = *(str+i);
		printf("%c ",*(p+j) );
	}
	printf("\n");
}



