#include <iostream>
using namespace std;
class Student
{
private:
	int Number;
	float Grade;
public:
	
	Student():Number(0),Grade(0){}
	
	Student(int a,float b)
	{
		Number=a;
		Grade=b;
	}
	
	Student(const Student &right);
	
    Student &operator =(const Student &right);
	
	~Student() {};
	
	int GetNumber()
	{
		return Number;
	}
	
	float GetGrade()
	{
		return Grade;
	}
	
	void Set(int num,float grade);
};

Student::Student(const Student &right)
{
	Number=right.Number;
	Grade=right.Grade;
}

Student &Student::operator =(const Student &right)
{
	if(this == &right)
	{
		return *this;
	}
	
	Number=right.Number;
	Grade=right.Grade;
	
	return *this;
}

void Student::Set(int num,float grade)	
{
	Number=num;
	Grade=grade;
}

int max(Student *arr);

int main()
{
	int i,j;
	int a;
    float b;
	Student arr[5];
	
	for(j=0;j<5;j++)
	{
		cout<<"请输入第"<<j+1<<"个学生的学号与成绩:"<<endl;
		cin>>a>>b;
		arr[j].Set(a,b);
	}
	
	i=max(arr);
	cout<<"成绩最高者学号为:"<<arr[i].GetNumber()<<endl;
	return 0;
}

int max(Student *arr)
{
	int max=0;
    int i;
	for(i=1;i<5;i++)
	{
		if(arr[i].GetGrade()>arr[max].GetGrade())
		{
			max=i;
		}
	}
	return max;
}
