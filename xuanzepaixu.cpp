#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define MAX 80000
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
		for (int j = i + 1; j < MAX; j++)
			if (a[i] > a[j])
				sswap(a[i], a[j]);
	}

	timeend = clock();
	double endtime = (double)(timeend - start);

	cout << endl;
	cout << "Total time:" << endtime << "ms";
}
