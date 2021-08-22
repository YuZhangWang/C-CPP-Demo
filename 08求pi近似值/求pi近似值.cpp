#include <stdio.h>
#include <math.h>
int main()
{   
	int sign = 1;
	double n = 1; //分母
	double term = 1; //当前数据项
	double pi = 0;
	while (fabs(term) >= 1e-6)
	{ 	
pi = pi + term; //累加当前数据项
sign = -sign;  //计算下一项的分子
n = n + 2;  //计算下一项的分母
term = sign/n;  //计算下一项
	}
	pi=pi*4;
	printf("pi=%.16f\n", pi);
	return 0;
}
