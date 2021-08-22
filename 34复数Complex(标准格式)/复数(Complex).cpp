#include <iostream>

using namespace std;

class Complex //������

{

public:

Complex():real(0), imag(0) {} //ȱʡ���캯��

Complex(double real, double imag); //�������Ĺ��캯��

Complex(const Complex &c); //�������캯��

~Complex() {} //��������

//��1�� = () [] ->ֻ������Ϊ��Ա��������ֵ�����ֻ�����س�Ա������

Complex & operator=(Complex &right);

//��2�����е�һԪ�������������Ϊ��Ա����

Complex & operator++(); //ǰ������� ++c

Complex operator++(int); //��������� c++

Complex & operator--(); //ǰ������� --c

Complex operator--(int); //��������� c--

//��3�������Ը�ֵ�Ķ�Ԫ�������������Ϊ��Ա����

//+= -= /= *= &= |= ~= %= >>= <<=

Complex & operator+=(const Complex &right);

Complex & operator-=(const Complex &right);

//��4��������Ԫ�������������Ϊ��Ԫ������+ - * / < >��)

friend Complex operator+(const Complex &left, const Complex &right);

friend Complex operator-(const Complex &left, const Complex &right);

//��5������/����������ֻ������Ϊ��Ԫ����

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

//�������캯��

Complex::Complex(const Complex &c)

{

//cout << "Complex copy constructor!" << endl;

real = c.real;

imag = c.imag;

}

//��1�� = () [] ->ֻ������Ϊ��Ա��������ֵ�����ֻ�����س�Ա������

Complex & Complex::operator=(Complex &right)

{

if (this == &right) //����Ը�ֵ

{

return *this;

}

real = right.real;

imag = right.imag;

return *this;

}

//��2�����е�һԪ�������������Ϊ��Ա����

Complex& Complex::operator++()

{

++real;

++imag;

return *this;

}

Complex Complex::operator++(int)

{

Complex temp = *this; //���ÿ������캯��

++real;

++imag;

return temp; //�ֲ������ܷ������ã�reference��

}

Complex& Complex::operator--()

{

--real;

--imag;

return *this;

}

Complex Complex::operator--(int)

{

Complex temp = *this; //���ÿ������캯��

--real;

--imag;

return temp;

}

//��3�������Ը�ֵ�Ķ�Ԫ�������������Ϊ��Ա����

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

//��4����Ԫ�������������Ϊ��Ԫ����

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

//��5������/����������ֻ������Ϊ��Ԫ����

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

if ((c.imag > 0) && (c.real != 0)) //�鲿Ϊ�����м䡰+����

output << "+";

output << c.imag << "i";

}

return output;

}

#if 0

int main( )

{

Complex c1, c2, c3;

cout <<"������1������:";

cin >> c1; // (operator>>(cin, c1)

cout << "c1=" << c1 << endl;

cout <<"������2������:";

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

a1 += a2; //�����+=

cout << "a1=" << a1 << endl;

b1 -= b2; //�����-=

cout << "b1=" << b1 << endl;

return 0;

}

#endif

#if 0 //��֤��ֵ���������������������= >> <<

int main()

{

Complex a, b(20, 20);

//�������� <<

Complex c ;

c = b; //���ø�ֵ���������

cout << "c=" << c << endl;

//��������� >>

cout<< "Please input complex number:";

cin >> a ;

//�������� <<

cout << "a=" << a << endl;

return 0;

}

#endif

#if 0 //��֤һԪ��������ܣ�++ --,

int main()

{

Complex a(10, 10), b(20, 20);

Complex c1, c2;

c1 = ++a; //ǰ���Լ�

cout << "a: " << a << endl;

cout << "c1: " << c1 << endl;

c2 = b++; //�����Լ�

cout << "b " << b << endl;

cout << "c2 " << c2 << endl;

return 0;

}

#endif