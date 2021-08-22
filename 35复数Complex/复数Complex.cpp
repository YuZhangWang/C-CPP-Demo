#include <iostream>
using namespace std;
#include <math.h>

class Complex
{
public:
	Complex():real(0),imag(0) {}
	Complex(double real, double imag); 
	Complex(const Complex &c); 
	~Complex() {}
	Complex & operator=(Complex &right);

	Complex & operator++(); 
    Complex operator++(int index); 
	
    Complex & operator+=(const Complex &right);
    Complex & operator-=(const Complex &right);
	
	friend Complex operator+(const Complex &left, const Complex &right);
	friend Complex operator-(const Complex &left, const Complex &right);
	
	friend bool operator>=(const Complex &left, const Complex &right);
	friend bool operator<=(const Complex &left, const Complex &right);
	
	friend istream & operator>>(istream &input, Complex &c);
	friend ostream & operator<<(ostream &output, const Complex &c);
	
private:
	double real; 
	double imag;
};

Complex::Complex(double real,double imag)
{
	this->real=real;
	this->imag=imag;
}

Complex::Complex(const Complex &c)
{	
	real=c.real;
	imag=c.imag;
}

Complex & Complex::operator=(Complex &right)
{
	if(this==&right)
	{
		return *this;
	}
	
	real=right.real;
	imag=right.imag;
	
	return *this;
}

Complex& Complex::operator++()
{
    ++real;
    ++imag;

    return *this;
}

Complex Complex::operator++(int index)
{
    Complex temp = *this; 
    ++real;
    ++imag;

    return temp; 
}

Complex & Complex::operator+=(const Complex &right)
{

    real+=right.real;
    imag+=right.imag;

    return *this;
}

Complex & Complex::operator-=(const Complex &right)
{

    real-=right.real;
    imag-=right.imag;

    return *this;
}

Complex operator+(const Complex &left,const Complex &right)
{
	Complex temp;
	temp.real=left.real+right.real;
	temp.imag=left.imag+right.imag;
	
	return temp;
}

Complex operator-(const Complex &left,const Complex &right)
{
	Complex temp;
	temp.real=left.real-right.real;
	temp.imag=left.imag-right.imag;
	
	return temp;
}

bool operator>=(const Complex &left, const Complex &right)
{
    if(sqrt(pow(left.real,2)+pow(left.imag,2)) >= sqrt(pow(right.real,2)+pow(right.imag,2)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator<=(const Complex &left, const Complex &right)
{
    if(sqrt(pow(left.real,2)+pow(left.imag,2)) <= sqrt(pow(right.real,2)+pow(right.imag,2)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

istream & operator>>(istream &input, Complex &c)
{
	input>>c.real>>c.imag;
	
	return input;
}

ostream & operator<<(ostream &output,const Complex &c)
{
	if((c.real==0 && c.imag==0)||(c.real != 0))
	{
		output<<c.real;
	}
	
	if(c.imag != 0)
	{
		if ((c.imag>0)&&(c.real != 0)) 
		{
			output<<"+";
		}
		output<<c.imag<<"i";
	}
	
	return output;
}

int main()
{
	Complex a1,b1;
	cout<<"请输入2个复数:"<<endl;
	cin>>a1>>b1;
	cout<<endl;
	
	cout<<"验证重载输入输出运算符:"<<endl;
	cout<<"a1="<<a1<<endl; 
	cout<<"b1="<<b1<<endl;
	cout<<endl;
	
	cout<<"验证重载大于等于和小于等于运算符:"<<endl;
	if(a1>=b1)
	{
		cout<<"a1大于等于b1"<<endl;
	}
	else if(a1<=b1)
	{
        cout<<"a1小于等于b1"<<endl;
	}
	cout<<endl;
	
	cout<<"验证重载赋值运算符函数:"<<endl;
    Complex c1;
	c1=a1;
	cout<<"c1="<<c1<<endl;
	cout<<endl;
	
	cout<<"验证重载加减运算符:"<<endl;
	Complex c2,c3;
	c2=a1+b1; 
	cout<<"c2="<<c2<<endl;
	c3=a1-b1; 
	cout<<"c3="<<c3<<endl;
	cout<<endl;
	
	cout<<"验证重载自赋值运算符:"<<endl;
    Complex c4(0,0),c5(0,0);
	c4+=a1; 
	cout<<"c4="<<c4<<endl;
	c5-=b1;
	cout<<"c5="<<c5<<endl;
	cout<<endl;

	cout<<"验证重载自加运算符:"<<endl;
	Complex c6,c7;
	c6=++a1; 
    cout<<"a1="<<a1<<endl;
    cout<<"c6="<<c6<<endl;
    c7=b1++;
    cout<<"b1="<<b1<<endl;
    cout<<"c7="<<c7<<endl;
	
	return 0;
}

