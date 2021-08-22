#include <stdio.h>
int main()
{
	int m, i, n, a;
	scanf("%d",&m);
    for ( i=1 ; i<=m ; i++,a=1 )
	{
		for ( n = 2 ; n<i ; n++ )
		{
			if ( i%n == 0 )
			{
				a = 0;
				break;
			}
			else
				a = 1;
		}
		if ( a == 1 )
			printf("%d\n",i);
	}
	return 0;
}

