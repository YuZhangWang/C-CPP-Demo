#include <stdio.h>
int main()
{
	int i,j;
	double m = 0,n;
	for(i = 1, n = 1 ; i <= 20; i++, n = 1)
	{
		for(j = 1 ; j <= i ; j++)
		{
            n *= j;
		}
		m += n;
	}
	printf("1!+2!+3!+...+20!=%.lf\n",m);
	return 0;
}





