#include <iostream>
using namespace std;
class Point3D
{
private:
	float x,y,z;
public:
	void ShowPoint()
	{
		cout<<"��ά����Ϊ:"<<"("<<x<<","<<y<<","<<z<<")"<<endl;
	}
	
	Point3D()
	{
		x=0;
		y=0;
		z=0;
		cout<<"����ȱʡ����:"<<"("<<x<<","<<y<<","<<z<<")"<<endl;
	}
	
	Point3D(float a,float b,float c)
	{
		x=a;
		y=b;
		z=c;
		cout<<"���ô��κ���:"<<"("<<x<<","<<y<<","<<z<<")"<<endl;
	}
	
	Point3D (const Point3D &right);
	
	Point3D &operator =(const Point3D &right);
	
	~Point3D()
	{
        cout<<"������������:"<<"("<<x<<","<<y<<","<<z<<")"<<endl;
	}
};

Point3D::Point3D (const Point3D &right)
{
	x=right.x;
	y=right.y;
	z=right.z;
	cout<<"���ÿ������캯��:"<<"("<<x<<","<<y<<","<<z<<")"<<endl;
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
	cout<<"���ø�ֵ���������:"<<"("<<x<<","<<y<<","<<z<<")"<<endl;
	return *this;
}

void main()
{
	float m,n,k;
	cout<<"��������������:"<<endl;
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
	cout<<"�˳�������\n";
}