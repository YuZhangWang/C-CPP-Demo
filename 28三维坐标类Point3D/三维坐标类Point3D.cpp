#include <iostream>
using namespace std;
class Point3D
{
private:
	float x,y,z;
public:
	void ShowPoint()
	{
		cout<<"三维坐标为:"<<"("<<x<<","<<y<<","<<z<<")"<<endl;
	}
	
	Point3D()
	{
		x=0;
		y=0;
		z=0;
		cout<<"调用缺省函数:"<<"("<<x<<","<<y<<","<<z<<")"<<endl;
	}
	
	Point3D(float a,float b,float c)
	{
		x=a;
		y=b;
		z=c;
		cout<<"调用带参函数:"<<"("<<x<<","<<y<<","<<z<<")"<<endl;
	}
	
	Point3D (const Point3D &right);
	
	Point3D &operator =(const Point3D &right);
	
	~Point3D()
	{
        cout<<"调用析构函数:"<<"("<<x<<","<<y<<","<<z<<")"<<endl;
	}
};

Point3D::Point3D (const Point3D &right)
{
	x=right.x;
	y=right.y;
	z=right.z;
	cout<<"调用拷贝构造函数:"<<"("<<x<<","<<y<<","<<z<<")"<<endl;
}

Point3D &Point3D::operator =(const Point3D &right)
{
	if(this ==&right)
	{
		return *this;
	}
	
	x=right.x;
	y=right.y;
	z=right.z;
	cout<<"调用赋值运算符函数:"<<"("<<x<<","<<y<<","<<z<<")"<<endl;
	return *this;
}

void main()
{
	float m,n,k;
	cout<<"请输入三个坐标:"<<endl;
	cin>>m>>n>>k;
	Point3D a(m,n,k);
	Point3D b1(a);
	Point3D b2=a;
	Point3D c;
	c=a;
    a.ShowPoint();
    b1.ShowPoint();
	b2.ShowPoint();
    c.ShowPoint();
	cout<<"退出主函数\n";
}