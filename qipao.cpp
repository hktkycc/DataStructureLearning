#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
#define MAX 80000
clock_t start,timeend;

void sswap(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

int main()
{
	start = clock();
	int a[MAX];
	for (int i = 0; i < MAX; i++)
	{
		a[i] = rand();
		//cout << a[i] << " ";
	}
	cout << endl;
	cout << "#";



	for (int x = MAX; x >= 0; x--)
	{
		int flag1 = 0;
		for (int y = 0; y < x - 1; y++)
		{
			if (a[y] > a[y + 1])
			{
				sswap(a[y], a[y + 1]);
				flag1++;
			}
		}
		if (flag1 == 0)
			x = -1;
	}

	timeend = clock();
	double endtime = (double)(timeend - start);

	for (int i = 0; i < MAX; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;
	cout << "Total time:" << endtime << "ms";
}
