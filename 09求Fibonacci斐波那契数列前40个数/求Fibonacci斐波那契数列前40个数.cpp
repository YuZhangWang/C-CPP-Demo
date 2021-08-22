#include <stdio.h>
int main()
{ 
	int f1 = 1, f2 = 1;
	int i; //循环控制变量
	for (i=1; i<=20; i++)
	{  
		printf("%12d%12d", f1, f2);//输出当前的2个数
		if (i%2==0) 
		    printf("\n");  //控制换行
		f1 = f1+f2; //求下两个数中的第一个给f1
		f2 = f2+f1; //求下两个数中的第二个给f2
	}
	return 0;
} 
