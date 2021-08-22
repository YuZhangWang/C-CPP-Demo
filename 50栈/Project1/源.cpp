#include<iostream>
using namespace std;
#define initstacksize 100
#define increment 10

class stack
{
	int *base;
	int stacksize;
	int *top;
public:
	stack();
	void initstackn(int n);
	void push(int e); //压栈
	void pop(int &e); //退栈
	int emptystack(); //派空
	void conversion(int n); //进制转换
};

stack::stack()
{
	base = new int[initstacksize];
	top = base;
	stacksize = initstacksize;
}

void stack::initstackn(int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> base[i];
		top++;
	}
}

void stack::push(int e)
{
	if (top - base == stacksize)
	{
		int *base1 = new int[stacksize + increment];
		for (int i = 0; i < stacksize; i++)
			base1[i] = base[i];
		delete[]base;
		base = base1;
		top = base + stacksize;
		stacksize += increment;
	}
	*top++ = e;
}

void stack::pop(int &e)
{
	if (top == base)
		return;
	e = *--top;
}

int stack::emptystack()
{
	if (top == base)
		return 1;
	else
		return 0;
}

void stack::conversion(int n) //进制转换
{
	while (n)
	{
		push(n % 8);
		n / 8;
	}

	int e;

	while (!emptystack())
	{
		pop(e);
		cout << e;
	}
}

int main()
{

	return 0;
}