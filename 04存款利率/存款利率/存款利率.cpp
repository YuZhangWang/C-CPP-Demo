#include <stdio.h>
#include <math.h>
#define A 0.015
#define B 0.021
#define C 0.0275
#define D 0.03
#define E 0.0035
int main()
{
	double k,g,h,i,j;
	k=1000*(1+5*D);
	g=(1000*(1+2*B))*(1+3*C);
	h=(1000*(1+3*C))*(1+2*B);
	i=1000*pow(1+A,5);
	j=1000*pow(1+E/4,4*5);
	printf("一次存五年本息和p=%f\n",k);
	printf("先存2年期，再存3年期本息和p=%f\n",g);
	printf("先存3年期，再存2年期本息和p=%f\n",h);
	printf("存1年期连存5年本息和p=%f\n",i);
	printf("存活期存款本息和p=%f\n",j);
	return 0;
}