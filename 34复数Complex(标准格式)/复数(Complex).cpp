#include <iostream>

using namespace std;

class Complex //复数类

{

public:

Complex():real(0), imag(0) {} //缺省构造函数

Complex(double real, double imag); //带参数的构造函数

Complex(const Complex &c); //拷贝构造函数

~Complex() {} //析构函数

//（1） = () [] ->只能重载为成员函数（赋值运算符只能重载成员函数）

Complex & operator=(Complex &right);

//（2）所有的一元运算符建议重载为成员函数

Complex & operator++(); //前置运算符 ++c

Complex operator++(int); //后置运算符 c++

Complex & operator--(); //前置运算符 --c

Complex operator--(int); //后置运算符 c--

//（3）具有自赋值的二元运算符建议重载为成员函数

//+= -= /= *= &= |= ~= %= >>= <<=

Complex & operator+=(const Complex &right);

Complex & operator-=(const Complex &right);

//（4）其他二元运算符建议重载为友元函数（+ - * / < >等)

friend Complex operator+(const Complex &left, const Complex &right);

friend Complex operator-(const Complex &left, const Complex &right);

//（5）输入/输出流运算符只能重载为友元函数

friend istream & operator>>(istream &input, Complex &c);

friend ostream & operator<<(ostream &output, const Complex &c);

private:

double real; // real number

double imag; // imaginary number

};

Complex::Complex(double real, double imag)

{

//cout << "Complex General Construnctor!" << endl;

this->real = real;

this->imag = imag;

}

//拷贝构造函数

Complex::Complex(const Complex &c)

{

//cout << "Complex copy constructor!" << endl;

real = c.real;

imag = c.imag;

}

//（1） = () [] ->只能重载为成员函数（赋值运算符只能重载成员函数）

Complex & Complex::operator=(Complex &right)

{

if (this == &right) //检查自赋值

{

return *this;

}

real = right.real;

imag = right.imag;

return *this;

}

//（2）所有的一元运算符建议重载为成员函数

Complex& Complex::operator++()

{

++real;

++imag;

return *this;

}

Complex Complex::operator++(int)

{

Complex temp = *this; //调用拷贝构造函数

++real;

++imag;

return temp; //局部对象不能返回引用（reference）

}

Complex& Complex::operator--()

{

--real;

--imag;

return *this;

}

Complex Complex::operator--(int)

{

Complex temp = *this; //调用拷贝构造函数

--real;

--imag;

return temp;

}

//（3）具有自赋值的二元运算符建议重载为成员函数

//+= -= /= *= &= |= ~= %= >>= <<=

Complex & Complex::operator+=(const Complex &right)

{

real += right.real;

imag += right.imag;

return *this;

}

Complex & Complex::operator-=(const Complex &right)

{

real -= right.real;

imag -= right.imag;

return *this;

}

//（4）二元运算符建议重载为友元函数

Complex operator+(const Complex &left, const Complex &right)

{

Complex temp;

temp.real = left.real + right.real;

temp.imag = left.imag + right.imag;

return temp;

}

Complex operator-(const Complex &left, const Complex &right)

{

Complex temp;

temp.real = left.real - right.real;

temp.imag = left.imag - right.imag;

return temp;

}

//（5）输入/输出流运算符只能重载为友元函数

istream & operator>>(istream &input, Complex &c)

{

input >> c.real >> c.imag;

return input;

}

ostream & operator<<(ostream &output, const Complex &c)

{

if ((c.real == 0 && c.imag == 0) || (c.real != 0))

{

output << c.real;

}

if (c.imag != 0)

{

if ((c.imag > 0) && (c.real != 0)) //虚部为正，中间“+”号

output << "+";

output << c.imag << "i";

}

return output;

}

#if 0

int main( )

{

Complex c1, c2, c3;

cout <<"请输入1个复数:";

cin >> c1; // (operator>>(cin, c1)

cout << "c1=" << c1 << endl;

cout <<"请输入2个复数:";

cin >> c2 >> c3; //operator>>(operator>>(cin, c2), c3)

cout << "c2=" << c2 << endl;

cout << "c3=" << c3 << endl;

return 0;

}

#endif

#if 1

int main()

{

Complex a1(10, 10), a2(20, 20);

Complex b1(100, 100), b2(200, 200);

a1 += a2; //运算符+=

cout << "a1=" << a1 << endl;

b1 -= b2; //运算符-=

cout << "b1=" << b1 << endl;

return 0;

}

#endif

#if 0 //验证赋值运算符和输入输出运算符：= >> <<

int main()

{

Complex a, b(20, 20);

//输出运算符 <<

Complex c ;

c = b; //调用赋值运算符函数

cout << "c=" << c << endl;

//输入运算符 >>

cout<< "Please input complex number:";

cin >> a ;

//输出运算符 <<

cout << "a=" << a << endl;

return 0;

}

#endif

#if 0 //验证一元运算符功能：++ --,

int main()

{

Complex a(10, 10), b(20, 20);

Complex c1, c2;

c1 = ++a; //前置自加

cout << "a: " << a << endl;

cout << "c1: " << c1 << endl;

c2 = b++; //后置自加

cout << "b " << b << endl;

cout << "c2 " << c2 << endl;

return 0;

}

#endif