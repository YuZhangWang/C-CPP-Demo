#include <stdio.h>

int main()
{
	int a,b,c,m;
	printf("������������a,b,c");
	scanf("%d,%d,%d",&a,&b,&c);
    m=a;
	if(m>b)
	    m=b;
	if(m>c)
        m=c;
	printf("m=%d\n",m);
	return 0;
}