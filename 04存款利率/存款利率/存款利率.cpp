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
	printf("һ�δ����걾Ϣ��p=%f\n",k);
	printf("�ȴ�2���ڣ��ٴ�3���ڱ�Ϣ��p=%f\n",g);
	printf("�ȴ�3���ڣ��ٴ�2���ڱ�Ϣ��p=%f\n",h);
	printf("��1��������5�걾Ϣ��p=%f\n",i);
	printf("����ڴ�Ϣ��p=%f\n",j);
	return 0;
}