#include <iostream>
using namespace std;

class Shape
{
public:
	virtual double area()=0;
};

class Rectangle:public Shape
{
private:
	double width;
	double heigth;
public:
	Rectangle(double w,double h):width(w),heigth(h) {}

	double area()
	{
		return (width*heigth);
	}
};

class Triangle:public Shape
{
private:
	double width;
	double heigth;
public:
	Triangle(double w,double h):width(w),heigth(h) {}
	double area()
	{
        return (0.5*width*heigth);
	}
};

class Trapezoid:public Shape
{
private:
	double top;
	double bottom;
	double heigth;
public:
	Trapezoid(double t,double b,double h):top(t),bottom(b),heigth(h) {}
    double area()
	{
		return ((top+bottom)*0.5*heigth);
	}
};

int main()
{
	Rectangle a(1,2);
	Triangle b(3,4);
	Trapezoid c(5,6,7);
	Shape *p[3]={&a,&b,&c};
	cout<<"The Rectangle's area is:"<<p[0]->area()<<endl
        <<"The Triangle's area is:"<<p[1]->area()<<endl
		<<"The Trapezoid's area is:"<<p[2]->area()<<endl;
	return 0;
}