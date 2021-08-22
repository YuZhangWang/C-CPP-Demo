#include <string.h>

#include <iostream>

using namespace std;

class MyString

{

public:

MyString(); //缺省构造函数

MyString(const char *str); //带参数的构造函数

MyString(const MyString &str); //拷贝构造函数

~MyString(); //析构函数

MyString & operator=(const MyString &right); //赋值运算符函数

void ShowString(); //显示字符串内容

friend int Compare(MyString &left, MyString &right);

friend MyString & MaxSizeString(MyString &left, MyString &right);

private:

char *data; //字符串

int size; //长度

};

//缺省构造函数

MyString::MyString()

{

size = 0;

data = new char[1];

if (NULL == data) //判断内存是否申请成功

{

exit(1);

}

*data = '\0';

}

MyString::MyString(const char *str)//带参数的构造函数

{

if (NULL == str)

{

size = 0;

data = new char[1];

if (NULL == data) //判断内存是否申请成功

{

exit(1);

}

*data = '\0';

}

else

{

size = strlen(str);

data = new char[size+1];

if (NULL == data) //判断内存是否申请成功

{

exit(1);

}

strcpy(data, str);

}

}

//拷贝构造函数在函数入口处无需与NULL进行比较

MyString::MyString(const MyString &str)

{

cout << "Copy Constructor!" << endl;

size = str.size;

data = new char[size + 1];

if (NULL == data) //判断内存是否申请成功

{

exit(1);

}

strcpy(data, str.data);

}

MyString::~MyString()//析构函数

{

cout << "Destructor!" << endl;

delete []data;

//data = NULL; //内存释放后置为NULL，防止野指针

size = 0;

}

MyString & MyString::operator=(const MyString &str)

{

//cout << "operator= function!" << endl;

if (this == &str) // (1) 检查自赋值

{

return *this;

}

delete []data; // (2) 释放原有的内存资源

// （3）分配新的内存资源，并复制内容

size = str.size;

data = new char[size + 1];

if (NULL == data) //判断内存是否申请成功

{

exit(1);

}

strcpy(data, str.data);

return *this; // （4）返回本对象的引用

}

void MyString::ShowString()

{

cout << data << endl;

}

//基于ASCII码比较字符串，例如：“ABC” < "abc"

int Compare(MyString &left, MyString &right)

{

int cmp;

cmp = strcmp(left.data, right.data);

if (cmp > 0 )

return 1;

else if (cmp == 0)

return 0;

else

return -1;

}

//获取两个字符串中最长的一个

MyString & MaxSizeString(MyString &left, MyString &right)

{

if (left.size >= right.size)

return left;

else

return right;

}

int main()

{

int ret = 0;

MyString a("abcd"), b("ABC"), c;

c = MaxSizeString(a, b);

c.ShowString();

return 0;

}