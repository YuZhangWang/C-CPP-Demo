#include<iostream>
using namespace std;
void sort(int &a,int &b,int &c);

int main()
{
	int a,b,c;
	cout<<"��������������:"<<endl;
	cin>>a>>b>>c;
    sort(a,b,c);
	cout<<"��������С��������Ϊ:"<<endl;
	cout<<a<<'\t'<<b<<'\t'<<c<<endl;
	return 0;
}

void sort(int &a,int &b,int &c)
{
	int temp;
	if(a>b)
	{
		temp=a;
		a=b;
		b=temp;
	}
    if(a>c)
	{
		temp=a;
		a=c;
		c=temp;
	}
	if(b>c)
	{
		temp=b;
		b=c;
		c=temp;
	}
}