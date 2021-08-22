#include <string>
#include <iostream>
using namespace std;

class Teacher
{
public:
	Teacher(int num,string name,string sex);
	void display();
private:
	int num;
	string name;
	string sex;
};

Teacher::Teacher(int num,string name,string sex):num(num),name(name),sex(sex) {}

void Teacher::display()
{
	cout<<num<<","<<name<<","<<sex<<endl;
}

class BirthDate
{
public:
    BirthDate(int year,int month,int day);
	void display();
	void change(int y,int m,int d);
private:
	int year;
	int month;
	int day;
};

BirthDate::BirthDate(int year,int month,int day):year(year),month(month),day(day) {}

void BirthDate::display()
{
    cout<<year<<","<<month<<","<<day<<endl;
}

void BirthDate::change(int y,int m,int d)
{
	year = y;
	month = m;
	day = d;
}

class Professor:public Teacher
{
public:
	Professor(int a,string b,string c,BirthDate d);
	void display();
	void changebirth(int y1,int m1,int d1);
private:
	BirthDate birthday;
};

Professor::Professor(int a,string b,string c,BirthDate d):Teacher(a,b,c),birthday(d) {}

void Professor::display()
{
     Teacher::display();
	 birthday.display();
}

void Professor::changebirth(int y1,int m1,int d1)
{
    birthday.change(y1,m1,d1);
}

int main()
{
	BirthDate d(1982,9,20);
	Professor prof1(1234,"ºú¸è","ÄÐ",d);
    prof1.display();
	prof1.changebirth(2018,4,8);
	prof1.display();
	return 0;
}

