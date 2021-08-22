#include <stdio.h>
int GetOrderDay(int year, int month, int day); 
int LeapYear(int year);   
int main()
{	
	int year, month, day; // 年月日
	int orderDay = 0;  // 一年第几天

	printf("Please input date (for example: 2018-11-29):\n ");
	scanf("%d-%d-%d", &year, &month, &day);
	
	orderDay = GetOrderDay(year, month, day);
	printf("%d-%d-%d is the %dth day in this year.\n", 
		    year, month, day, orderDay);
	return 0;
}

// 计算当年的顺序天
int GetOrderDay(int year, int month, int day)       
{

	int i;  // 循环变量
	int orderDay = 0; // 顺序天
	int monthList[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	// 如果为瑞年，二月份为29天
	if (LeapYear(year))
	{
		monthList[1] = 29;
	}

	for (i=0; i<month-1; i++)  // 累加所在月之前天数 
	{
		orderDay += monthList[i];   
	}

    orderDay += day;  // 累加本月天数

	return  orderDay;
}                        

// 判断是否为闰年
int LeapYear(int year)
{
	int ret = 0;
	if ((year%4==0 && year%100!=0) || (year%400==0))
	{
		ret = 1;
	}
	
	return ret;
}
