#include <stdio.h>
#include <math.h>
int main()
{     
	int i, j;  //ѭ������
	int m, n=0;  // mΪƽ������nΪ������
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
		   printf("\n");   /*����ÿ�����10����*/
	}
	printf ("\n");
	return 0;
}