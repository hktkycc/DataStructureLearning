#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
#define MAX 80000
clock_t start,timeend;

void sswap(int *a, int *b)
{
	int *c;
	c = a;
	a = b;
	b = c;
}

int main()
{
	start = clock();
	int a[MAX];
	int* ip = a;
	for (int i = 0; i < MAX; i++)
	{
		ip[i] = rand();
		//cout << a[i] << " ";
	}
	cout << endl;
	cout << "#";


	int n = 0;
	for (int x = MAX; x >= 0; x--)
	{
		int m = MAX - x;
		int flag1 = 0;
		for (int y = 0; y < x - 1; y++)
		{
			if (ip[y] > ip[y + 1])
			{
				sswap(&ip[y], &ip[y + 1]);
				flag1++;
			}
		}
		if (flag1 == 0)
			x = -1;
		if (m % (MAX/100) == 0)
		{
			n++;
			cout << n << "%";
		}
	}

	timeend = clock();
	double endtime = (double)(timeend - start);

	cout << endl;
	cout << "Total time:" << endtime << "ms";
}
