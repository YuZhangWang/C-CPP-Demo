#include <stdio.h>
#include <math.h>
int main()
{     
	int i, j;  //循环变量
	int m, n=0;  // m为平方根，n为计数器
	for (i=101;  i<=199;  i +=2)
	{    
		m = (int)sqrt(i);
		for (j=2;  j<=m;  j++)
		{    
		     if (i%j == 0)  
		     break;    
		}
		if (j == m+1)  
		{  
		    printf("%d ",i);  
		    n=n+1;  
		}
		if (n%10 == 0)  
		   printf("\n");   /*控制每行输出10个数*/
	}
	printf ("\n");
	return 0;
}