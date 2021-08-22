
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
	cout<<"�γ�:"<<title<<" "<<"ѧ��:"<<credit<<" "<<"�ɼ�:"<<grade<<endl;
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
    cout<<"����:"<<name<<" "<<"ѧ��:"<<id<<" "<<"�Ա�:"<<sex<<" ";
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