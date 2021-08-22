#include <iostream>  
using namespace std;

class Test
{
public:
	Test() 
	{
		n += 10; 
		cout << "A constructor" << endl; 
	}
	
	~Test() 
	{
		n -= 5; 
		cout << "A destructor" << endl;
	}
	
	static int getNum() 
	{ 
		return n; 
	}
	
private:
	static int n;
};

int Test::n = 1;

int main()
{
	Test t;
	cout << "n=" << Test::getNum() << endl;
	Test* p = new Test;
	delete p;
	cout << "n=" << Test::getNum() << endl;
	
	//system("pause");
	
	return 0;
}

