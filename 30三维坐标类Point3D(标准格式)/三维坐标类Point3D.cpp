#include <iostream>
using namespace std;

class  Point3D  //三维坐标类
{     
public:
    Point3D();  //缺省构造函数
    Point3D(double x, double y, double z);  //带参数的构造函数
    Point3D(const Point3D &right);  //拷贝构造函数
	~Point3D();    //析构函数
    Point3D& operator=(const Point3D &right);  //赋值运算符函数
    void ShowPoint() ; //自定义的显示函数
	
private:
	double  x, y, z;
};

Point3D::Point3D():x(0), y(0), z(0)
{
    cout << "Default constructor!" << endl;
}

Point3D::Point3D(double x, double y, double z)
{	
	cout << "General constructor!" << endl;
	this->x = x;
	this->y = y;
	this->z = z;
}

Point3D::~Point3D()   
{
    cout << "Destructor: ~Point3D(), x="  << x << endl;
}

Point3D::Point3D(const Point3D &right)  //Copy constructor
{
    cout << "Copy constructor!" << endl;
    x=right.x;
    y=right.y;
    z=right.z;
}

Point3D& Point3D::operator=(const Point3D& right)
{
	cout << "operator= function!" <<endl;
	
	//在operator=中检查是否"自己赋值给自己"
	if (this == &right)
		return *this;
	
	x = right.x;
	y = right.y;
	z = right.z;
	
	return *this;	
}

void Point3D::ShowPoint()
{  
	cout << x <<", " << y << ", " << z << endl;
    return;
}

int main( )
{  
	Point3D  a(10, 11, 12); //调用带参数构造函数
    cout << "Point3D a: ";
    a.ShowPoint();
	
    Point3D  b(a);  //调用拷贝构造函数
    cout << "Point3D b: ";
    b.ShowPoint();
	
    Point3D  c = a; //调用拷贝构造函数
    cout << "Point3D c: ";
    c.ShowPoint();
    return 0;
}