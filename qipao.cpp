#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 8000

void sswap(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

int main()
{

	int a[MAX];
	for (int i = 0; i < MAX; i++)
	{
		a[i] = rand();
		cout << a[i] << " ";
	}
	cout << endl;

	for (int x = MAX; x >= 0; x--)
		for (int y = 0; y < x - 1; y++)
		{
			if (a[y] > a[y + 1])
			{
				sswap(a[y], a[y + 1]);
			}
		}
	for (int i = 0; i < MAX; i++)
	{
		cout << a[i] << " ";
	}
}
