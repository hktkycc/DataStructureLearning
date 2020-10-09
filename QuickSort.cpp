#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
#define MAX 80000
clock_t start, timeend;

int n, a[MAX];
void Quick_Sort(int left, int right)
{
	if (left > right)
		return;
	int temp = a[left];
	int i = left, j = right;
	while (left != right)
	{
		while (a[right] >= temp && right > left)
			right--;
		while (a[left] <= temp && left < right)
			left++;
		swap(a[left], a[right]);
	}
	a[i] = a[left];
	a[left] = temp;
	Quick_Sort(i, left - 1);
	Quick_Sort(left + 1, j);
}

int main()
{
	int* ip = a;
	for (int i = 0; i < MAX; i++)
	{
		ip[i] = rand();
		//cout << a[i] << " ";
	}
	cout << endl;
	cout << "#";

	start = clock();
	Quick_Sort(0, MAX - 1);

	timeend = clock();
	double endtime = (double)(timeend - start);

	cout << endl;
	cout << "Total time:" << endtime << "ms" << endl;
}
