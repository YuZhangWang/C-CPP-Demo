#include <stdio.h>
#include <math.h>
int main()
{   
	int sign = 1;
	double n = 1; //��ĸ
	double term = 1; //��ǰ������
	double pi = 0;
	while (fabs(term) >= 1e-6)
	{ 	
pi = pi + term; //�ۼӵ�ǰ������
sign = -sign;  //������һ��ķ���
n = n + 2;  //������һ��ķ�ĸ
term = sign/n;  //������һ��
	}
	pi=pi*4;
	printf("pi=%.16f\n", pi);
	return 0;
}
