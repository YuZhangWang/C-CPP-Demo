#include <stdio.h>
int GetOrderDay(int year, int month, int day); 
int LeapYear(int year);   
int main()
{	
	int year, month, day; // ������
	int orderDay = 0;  // һ��ڼ���

	printf("Please input date (for example: 2018-11-29):\n ");
	scanf("%d-%d-%d", &year, &month, &day);
	
	orderDay = GetOrderDay(year, month, day);
	printf("%d-%d-%d is the %dth day in this year.\n", 
		    year, month, day, orderDay);
	return 0;
}

// ���㵱���˳����
int GetOrderDay(int year, int month, int day)       
{

	int i;  // ѭ������
	int orderDay = 0; // ˳����
	int monthList[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	// ���Ϊ���꣬���·�Ϊ29��
	if (LeapYear(year))
	{
		monthList[1] = 29;
	}

	for (i=0; i<month-1; i++)  // �ۼ�������֮ǰ���� 
	{
		orderDay += monthList[i];   
	}

    orderDay += day;  // �ۼӱ�������

	return  orderDay;
}                        

// �ж��Ƿ�Ϊ����
int LeapYear(int year)
{
	int ret = 0;
	if ((year%4==0 && year%100!=0) || (year%400==0))
	{
		ret = 1;
	}
	
	return ret;
}
