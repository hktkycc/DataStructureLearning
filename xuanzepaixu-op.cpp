#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define MAX 10000
clock_t start, timeend;

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
		a[i] = rand();


	start = clock();
	for (int i = 0; i < MAX; i++)
	{
		int min = a[i], flag = i;
		for (int j = i + 1; j < MAX; j++)
		{
			if (a[flag] > a[j])
			{
				min = a[j];
				flag = j;
			}
		}
		a[flag] = a[i];
		a[i] = min;

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
