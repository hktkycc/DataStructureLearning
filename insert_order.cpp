#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
#define MAX 80000
clock_t start, timeend;


void insert_sort(int a[])
{
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
}

int main()
{

	int a[MAX];
	for (int i = 0; i < MAX; i++)
	{
		a[i] = rand();
		//cout << a[i] << " ";
	}
	cout << endl;
	cout << "#";

	start = clock();

	for (int i = 1; i < MAX; i++)
	{
		int j;
		int tmp = a[i];
		for (j = i; j >= 0 && tmp < a[j - 1]; j--) {
			a[j] = a[j - 1];
		}
		a[j] = tmp;

	}

	timeend = clock();
	double endtime = (double)(timeend - start);

	cout << endl;
	cout << "Total time:" << endtime << "ms";
}
