#include <iostream>
using namespace std;

int main()
{

	int a[100] = { 0 };
	int i;
	int m;
	cin >> i;

	for (int k = 0; k < i; k++)
	{
		cin >> a[k];
	}

	int c = 0;
	int e = 0;

	for (int b = 0; b < i; b++)
	{
		int flag = 0;

		if (c > e)
		{
			e = c;
			c = 0;
		}
		else
		{
			c = 0;
		}

		if (a[b] == a[b + 1])
		{
		}
		else if (a[b] > a[b + 1])
		{
			c += 1;
			int d = b + 1;
			while (flag == 0 && d < 8)
			{
				if (a[d] > a[d + 1])
				{
					c += 1;
					d += 1;
				}
				else if (a[d] == a[d + 1])
				{
					d += 1;
				}
				else
				{
					e = c;
					flag = 1;
				}
			}
		}

		else
		{
			c += 1;
			int f = b + 1;
			int flag1 = 0;
			while (flag1 == 0 && f < 8)
			{
				if (a[f] < a[f + 1])
				{
					c += 1;
					f += 1;
				}
				else if (a[f] == a[f + 1])
				{
					f += 1;
				}
				else
				{
					c += 1;
					int g = f + 1;
					while (flag == 0 && g < 8)
					{
						if (a[g] > a[g + 1])
						{
							c += 1;
							g += 1;
						}
						else if (a[g] == a[g + 1])
						{
							g += 1;
						}
						else
						{
							e = c;
							flag = 1;
						}
					}
					flag1 = 1;
				}
			}
		}
	}

	cout << e + 1;

	return 0;
}