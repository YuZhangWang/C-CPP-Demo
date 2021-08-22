
#include <string>
#include <iostream>
using namespace std;

class Course
{
public:
    Course(string t,float c,float g);
	void print();
private:
	string title;
	float credit,grade;
};

Course::Course(string t,float c,float g):title(t),credit(c),grade(g) {}

void Course::print()
{
	cout<<"课程:"<<title<<" "<<"学分:"<<credit<<" "<<"成绩:"<<grade<<endl;
}

class Student
{
public:
	Student(string n,char s,int i);
	void show();
private:
	string name;
	int id;
	char sex;
};

Student::Student(string n,char s,int i):name(n),sex(s),id(i) {}

void Student::show()
{
    cout<<"姓名:"<<name<<" "<<"学号:"<<id<<" "<<"性别:"<<sex<<" ";
}

class Undergraduate:public Student
{
public:
    Undergraduate(string n,char s,int i,string t,float c,float g);
	void show();
private:
	Course cour;
};

Undergraduate::Undergraduate(string n,char s,int i,string t,float c,float g):Student(n,s,i),cour(t,c,g) {}

void Undergraduate::show()
{
	Student::show();
	cour.print();
}


int main()
{
    Undergraduate s("zhang",'m',20180001,"cs",2.5,90);
    s.show();
	return 0;
}