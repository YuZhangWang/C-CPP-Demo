#include <stdio.h>
char g_a[100];
int my_strlen(char *str);

int main()
{
	char *str=g_a;
	int length=0;
	printf("������һ���ַ���:");
	gets(g_a);
    length=my_strlen(str);
	printf("�ַ�������:%d",length);
	printf("\n");
    return 0;
}

int my_strlen(char *str)
{
    int length =0;
	while(*str != '\0')
	{
		str++;
		length++;
	}
	return length;
}