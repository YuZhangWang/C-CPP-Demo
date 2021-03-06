#include <iostream>
using namespace std;

class MyString
{
public:
	MyString();
	MyString(const char *str);
	MyString(const MyString &right);
	MyString & operator= (const MyString &right);
	~MyString();
	void ShowString();
	friend int Compare(MyString &left,MyString &right);
	friend MyString & MaxSizeString(MyString &left,MyString &right);
private:
	char *data;
	int size;
};

MyString::MyString()
{
	cout<<"调用缺省构造函数"<<endl;
	size=0;
	
	data=new char[1];
	if(NULL == data)
	{
		exit(1);
	}
	*data = '\0';
}

MyString::MyString(const char *str)
{
	cout<<"调用带参构造函数"<<endl;
	if(NULL == str)
	{
		size=0;
		data=new char[1];
		if(NULL == data)
		{
			exit(1);
		}
		*data='\0';
	}
	else
	{
		size=strlen(str);
		data=new char[size+1];
		if(NULL == data)
		{
			exit(1);
		}
		strcpy(data,str);
	}
}

MyString::MyString(const MyString &str)
{
	cout<<"调用拷贝构造函数"<<endl;
    size=str.size;
	data=new char[size+1];
	if(NULL == data)
	{
		exit(1); 
	}
	strcpy(data,str.data);
}

MyString & MyString :: operator= (const MyString &str)
{
	cout<<"调用赋值运算符函数"<<endl;
	if(this == &str)
	{
		return *this;
	}
	
	delete []data;
	
	size=str.size;
	data=new char[size+1];
	if(NULL == data)
	{
		exit(1);
	}
	
	strcpy(data,str.data);
	
	return *this;
}

MyString::~MyString()
{
	cout<<"调用析构函数"<<endl;
	delete []data;
}

void MyString::ShowString()
{
	cout<<data<<endl;
}

int Compare(MyString &left,MyString &right)
{
	int cmp;
	cmp=strcmp(left.data,right.data);
	if(cmp>0)
	{
		return 1;
	}
	else if(cmp==0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

MyString & MaxSizeString(MyString &left,MyString &right)
{
	if(left.size>=right.size)
	{
		return left;
	}
	else
	{
		return right;
	}
}


int main()
{
    MyString str1;
    MyString str2("C++");
	MyString str3(str2);
	str1=str3;
	str1.ShowString();
	str2.ShowString();
	str3.ShowString();

	MyString a("abcd"),b("ABC"),c;
	int ret = Compare(a,b);
	cout<<ret<<endl;
	int ret1 =0;
	c=MaxSizeString(a,b);
	c.ShowString();
	return 0;
}




