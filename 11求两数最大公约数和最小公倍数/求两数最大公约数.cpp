#include <iostream>
using namespace std;

int main()
{
	int m, n, i;
	int temp, r=1;
	cin>> m>>n;

	if (m < n)
	{
		temp = m;
		m = n;
		n = temp;
	}

	for (i = m; i > 0; i++)
	{
		if (i%m == 0 && i%n == 0)
		{
			break;
		}
	}

	while (r != 0)
	{
		r = m % n;
		m = n;
		n = r;
	}

	cout<< m<<endl<<i;
	return 0;
}