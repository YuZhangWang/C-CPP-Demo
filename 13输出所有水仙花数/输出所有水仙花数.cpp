#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, c, d;
	for(a=100; a<1000 ; a++)
	{
		b = a/100;
		c = (a/10)%10;
		d = a%10;
		if (a == pow(b,3)+pow(c,3)+pow(d,3))
		{
			printf("%6d\n",a);
		}
	}
	return 0;
}