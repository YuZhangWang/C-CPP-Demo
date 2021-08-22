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
private:
	char *data;
	int size;
};

MyString::MyString()
{
	cout<<"����ȱʡ���캯��"<<endl;
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
	cout<<"���ô��ι��캯��"<<endl;
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
	cout<<"���ÿ������캯��"<<endl;
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
	cout<<"���ø�ֵ���������"<<endl;
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
	cout<<"������������"<<endl;
	delete []data;
}

void MyString::ShowString()
{
	cout<<data<<endl;
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
	return 0;
}




