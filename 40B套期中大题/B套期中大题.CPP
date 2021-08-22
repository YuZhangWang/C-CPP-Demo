#include <string.h>
#include <iostream>
using namespace std;
class Date
{
	int year,month,day;
public:
	Date(int y,int m,int d);
	void print();
};

Date::Date(int y,int m,int d):year(y),month(m),day(d) {}

void Date::print()
{
	cout<<"日期为:"<<year<<"-"<<month<<"-"<<day<<endl;
}

class PC
{
	char brand[40];
	Date buyDate;
	int cost;
public:
	PC(char *brand,int buyy,int buym,int buyd,int cost);
	virtual void show();
};

PC::PC(char *brand,int buyy,int buym,int buyd,int cost):buyDate(buyy,buym,buyd),cost(cost)
{
	strcpy(this->brand,brand);
}

void PC::show()
{
	buyDate.print();
	cout<<"品牌为:"<<brand<<endl
		<<"价格为:"<<cost<<endl;
}

class NoteBook:public PC
{
	int batteryCapacity;
public:
	NoteBook(char *brand,int buyy,int buym,int buyd,int cost,int battCap):PC(brand,buyy,buym,buyd,cost),batteryCapacity(battCap) {}
	void show();
};

void NoteBook::show()
{
	PC::show();
	cout<<"电池容量为:"<<batteryCapacity<<endl;
}

int main()
{
	NoteBook a("戴尔",2019,4,24,5000,10000);
	a.show();
	return 0;
}
