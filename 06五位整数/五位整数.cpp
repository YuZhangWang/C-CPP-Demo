#include <stdio.h>
int main()
{
	int a, b;
	
	do
	{
		printf("������һ��������5λ��������:");
        scanf("%d",&a);
	}while((a<0)||(a>99999));
	
	if (a<=9)
	{
		printf("λ��Ϊ1λ\n");
		b=1;
	}
	else if (a<=99)
	{
		printf("λ��Ϊ2λ\n");
		b=2;
	}
	else if (a<=999)
	{
		printf("λ��Ϊ3λ\n");
		b=3;
	}
	else if (a<=9999)
	{
		printf("λ��Ϊ4λ\n");
		b=4;
	}
	else
	{
		printf("λ��Ϊ5λ\n");
		b=5; 
	}
	
	switch(b)
	{
	case 1:
		printf("��λ����=%d\n",a);
        printf("��������=%d\n",a);
		break;
    case 2:
		printf("ʮλ����=%d\n",a/10);
        printf("��λ����=%d\n",a%10);
		printf("��������=%d\n",(a%10)*10+a/10);
		break;
    case 3:
		printf("��λ����=%d\n",a/100);
        printf("ʮλ����=%d\n",(a/10)%10);
		printf("��λ����=%d\n",a%10);
		printf("��������=%d\n",(a%10)*100+((a/10)%10)*10+a/100);
		break;
	case 4:
		printf("ǧλ����=%d\n",a/1000);
        printf("��λ����=%d\n",(a/100)%10);
		printf("ʮλ����=%d\n",(a/10)%10);
        printf("��λ����=%d\n",a%10);
		printf("��������=%d\n",(a%10)*1000+((a/10)%10)*100+((a/100)%10)*10+a/1000);
		break;
	case 5:
		printf("��λ����=%d\n",a/10000);
        printf("ǧλ����=%d\n",(a/1000)%10);
		printf("��λ����=%d\n",(a/100)%10);
        printf("ʮλ����=%d\n",(a/10)%10);
        printf("��λ����=%d\n",a%10);
		printf("��������=%d\n",(a%10)*10000+((a/10)%10)*1000+((a/100)%10)*100+((a/1000)%10)*10+a/10000);
		break;
	default:
		break;
	}
	return 0;
}


