#include <stdio.h>
int main()
{
	int a, b;
	
	do
	{
		printf("请输入一个不多于5位的正整数:");
        scanf("%d",&a);
	}while((a<0)||(a>99999));
	
	if (a<=9)
	{
		printf("位数为1位\n");
		b=1;
	}
	else if (a<=99)
	{
		printf("位数为2位\n");
		b=2;
	}
	else if (a<=999)
	{
		printf("位数为3位\n");
		b=3;
	}
	else if (a<=9999)
	{
		printf("位数为4位\n");
		b=4;
	}
	else
	{
		printf("位数为5位\n");
		b=5; 
	}
	
	switch(b)
	{
	case 1:
		printf("个位数字=%d\n",a);
        printf("倒序数字=%d\n",a);
		break;
    case 2:
		printf("十位数字=%d\n",a/10);
        printf("个位数字=%d\n",a%10);
		printf("倒序数字=%d\n",(a%10)*10+a/10);
		break;
    case 3:
		printf("百位数字=%d\n",a/100);
        printf("十位数字=%d\n",(a/10)%10);
		printf("个位数字=%d\n",a%10);
		printf("倒序数字=%d\n",(a%10)*100+((a/10)%10)*10+a/100);
		break;
	case 4:
		printf("千位数字=%d\n",a/1000);
        printf("百位数字=%d\n",(a/100)%10);
		printf("十位数字=%d\n",(a/10)%10);
        printf("个位数字=%d\n",a%10);
		printf("倒序数字=%d\n",(a%10)*1000+((a/10)%10)*100+((a/100)%10)*10+a/1000);
		break;
	case 5:
		printf("万位数字=%d\n",a/10000);
        printf("千位数字=%d\n",(a/1000)%10);
		printf("百位数字=%d\n",(a/100)%10);
        printf("十位数字=%d\n",(a/10)%10);
        printf("个位数字=%d\n",a%10);
		printf("倒序数字=%d\n",(a%10)*10000+((a/10)%10)*1000+((a/100)%10)*100+((a/1000)%10)*10+a/10000);
		break;
	default:
		break;
	}
	return 0;
}


