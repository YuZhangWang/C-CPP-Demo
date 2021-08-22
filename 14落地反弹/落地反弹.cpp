#include <stdio.h>
int main()
{
	int i;
    double m=100, n;
	for (i=1,n=100;i<=9;i++)
	{
		m+=(n/2.0)*2;
		n=n/2.0;
	}
	printf("第十次落地共经过米数=%lf\n",m);
	printf("第十次反弹高度=%lf\n",n/2.0);
	return 0;
} 