#include <stdio.h>
int main()
{ 
	int f1 = 1, f2 = 1;
	int i; //ѭ�����Ʊ���
	for (i=1; i<=20; i++)
	{  
		printf("%12d%12d", f1, f2);//�����ǰ��2����
		if (i%2==0) 
		    printf("\n");  //���ƻ���
		f1 = f1+f2; //�����������еĵ�һ����f1
		f2 = f2+f1; //�����������еĵڶ�����f2
	}
	return 0;
} 
