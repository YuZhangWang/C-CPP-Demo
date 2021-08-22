#include <iostream>
using namespace std;

class  Point3D  //��ά������
{     
public:
    Point3D();  //ȱʡ���캯��
    Point3D(double x, double y, double z);  //�������Ĺ��캯��
    Point3D(const Point3D &right);  //�������캯��
	~Point3D();    //��������
    Point3D& operator=(const Point3D &right);  //��ֵ���������
    void ShowPoint() ; //�Զ������ʾ����
	
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
	
	//��operator=�м���Ƿ�"�Լ���ֵ���Լ�"
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
	Point3D  a(10, 11, 12); //���ô��������캯��
    cout << "Point3D a: ";
    a.ShowPoint();
	
    Point3D  b(a);  //���ÿ������캯��
    cout << "Point3D b: ";
    b.ShowPoint();
	
    Point3D  c = a; //���ÿ������캯��
    cout << "Point3D c: ";
    c.ShowPoint();
    return 0;
}