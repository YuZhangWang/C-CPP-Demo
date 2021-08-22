#include <stdio.h>

void input(int *p,int n);
void output(int *p,int n);
void process(int *p,int n);

int main()
{
	int a[10];
	int *p = a;
	printf("Please put 10 numbers:");
	input(p,10);
	process(p,10);
	output(p,10);
	return 0;
}

void input(int *p,int n)
{
	int i;
	for(i = 0;i<n;i++,p++)
	{
		scanf("%d",p);
	}
}

void output(int *p,int n)
{
	int i;
	for(i = 0;i<n;i++,p++)
	{
		printf("%d ",*p);
	}
	printf("\n");
}

void process(int *p,int n)
{
	int min = *p,max = *p;
	int *q = p;
	int m = 0,k = 0;
	int temp,i;
	for(i = 0;i<n;i++,p++)
	{
		if(*p<min)
		{
			min=*p;
			m = i;
		}
		
		if(*p>max)
		{
			max = *p;
			k = i;
		}
	}

    if(m==9&&k==0)
	{
	temp = *(q+9);
	*(q+9) = *q;
	*q = temp;
	}

	else if(m == 0)
	{
	temp = *q;
	*q = *(q+m);
	*(q+m) = temp;
	
	temp = *(q+9);
	*(q+9) = *(q+k);
	*(q+k) = temp;
	}

	else if(k == 0)
	{
    temp = *(q+9);
	*(q+9) = *(q+k);
	*(q+k) = temp;

	temp = *q;
	*q = *(q+m);
	*(q+m) = temp;
	}

	else
	{	
	temp = *q;
	*q = *(q+m);
	*(q+m) = temp;
	
	temp = *(q+9);
	*(q+9) = *(q+k);
	*(q+k) = temp;

	}

}