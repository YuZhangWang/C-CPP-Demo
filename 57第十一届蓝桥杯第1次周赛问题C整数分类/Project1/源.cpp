#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a = 1, b = 0, c = 0;
	int sum = 0;
	float h = 0;
	int d[100] = { 0 };
	int e;
	cin >> e;

	for (int f = 0; f < e; f++)
	{
		cin >> d[f];
	}

	for (int g = 0; g < e; g++)
	{
		if (d[g] % 3 == 0)
		{
			if (d[g] >= a)
				a = d[g];
		}
		if (d[g] % 3 == 1)
			b += 1;
		if (d[g] % 3 == 2)
		{
			sum += d[g];
			c += 1;
		}
	}

	if (a != 1)
	{
		cout << a << " ";
	}
	else
	{
		cout << "NONE" << " ";
	}

	if (b != 0)
	{
		cout << b << " ";
	}
	else
	{
		cout << "NONE" << " ";
	}

	if (c != 0)
	{
		h = (double)sum;
		cout << setiosflags(ios::fixed) << setprecision(1) << (double)(h / c);
	}
	else
	{
		cout << "NONE" << " ";
	}

	return 0;
}