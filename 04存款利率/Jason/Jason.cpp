#include <stdio.h>
int main()
{
    int n,m=2,x=0,y=0,z=1,Fn=0;
	scanf("%d",&n);
	if(n==1)
		Fn=1;
	else
	{
        while(m<=n)
		{
		    y=x;
	        x=z;
		    z=x+y;
	        m++;
		}
	}
	Fn=z%10007;
	printf("%d\n",Fn);
	return 0;
}