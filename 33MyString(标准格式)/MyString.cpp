#include <string.h>

#include <iostream>

using namespace std;

class MyString

{

public:

MyString(); //ȱʡ���캯��

MyString(const char *str); //�������Ĺ��캯��

MyString(const MyString &str); //�������캯��

~MyString(); //��������

MyString & operator=(const MyString &right); //��ֵ���������

void ShowString(); //��ʾ�ַ�������

friend int Compare(MyString &left, MyString &right);

friend MyString & MaxSizeString(MyString &left, MyString &right);

private:

char *data; //�ַ���

int size; //����

};

//ȱʡ���캯��

MyString::MyString()

{

size = 0;

data = new char[1];

if (NULL == data) //�ж��ڴ��Ƿ�����ɹ�

{

exit(1);

}

*data = '\0';

}

MyString::MyString(const char *str)//�������Ĺ��캯��

{

if (NULL == str)

{

size = 0;

data = new char[1];

if (NULL == data) //�ж��ڴ��Ƿ�����ɹ�

{

exit(1);

}

*data = '\0';

}

else

{

size = strlen(str);

data = new char[size+1];

if (NULL == data) //�ж��ڴ��Ƿ�����ɹ�

{

exit(1);

}

strcpy(data, str);

}

}

//�������캯���ں�����ڴ�������NULL���бȽ�

MyString::MyString(const MyString &str)

{

cout << "Copy Constructor!" << endl;

size = str.size;

data = new char[size + 1];

if (NULL == data) //�ж��ڴ��Ƿ�����ɹ�

{

exit(1);

}

strcpy(data, str.data);

}

MyString::~MyString()//��������

{

cout << "Destructor!" << endl;

delete []data;

//data = NULL; //�ڴ��ͷź���ΪNULL����ֹҰָ��

size = 0;

}

MyString & MyString::operator=(const MyString &str)

{

//cout << "operator= function!" << endl;

if (this == &str) // (1) ����Ը�ֵ

{

return *this;

}

delete []data; // (2) �ͷ�ԭ�е��ڴ���Դ

// ��3�������µ��ڴ���Դ������������

size = str.size;

data = new char[size + 1];

if (NULL == data) //�ж��ڴ��Ƿ�����ɹ�

{

exit(1);

}

strcpy(data, str.data);

return *this; // ��4�����ر����������

}

void MyString::ShowString()

{

cout << data << endl;

}

//����ASCII��Ƚ��ַ��������磺��ABC�� < "abc"

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

//��ȡ�����ַ��������һ��

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