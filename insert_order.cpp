#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
#define MAX 80000
clock_t start, timeend;

void sswap(int &a, int &b)
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

	for (int i = 1; i < MAX; i++)
	{
		int interval = a[i];
		for (int j = i; j > 0; j--)
		{
			if (interval < a[j - 1])
			{
				a[j] = a[j - 1];
			}
			else
			{
				a[j] = interval;
				break;
			}
		}

	}

	timeend = clock();
	double endtime = (double)(timeend - start);



	cout << endl;
	cout << "Total time:" << endtime << "ms";

	/*for (int i = 0; i < MAX; i++)
	{
		cout << a[i] << " ";
	}*/
}
