# include <stdio.h>
# include <math.h>
int main()
{
	double x,y,n,h;
    printf("������һ���������:");
    scanf("%lf,%lf",&x,&y);
    n=pow((pow(abs(x)-2,2)+pow(abs(y)-2,2)),0.5);
    if (n<=1)
		h=10;
	else
		h=0;
	printf("�õ�߶�:%.2lf\n",h);
    return 0;
}
