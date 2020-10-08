#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
#define MAX 80000
clock_t start, timeend, start1, timeend1;

void shell_sort_switch(int a[], int length)
{
	int h = 1;
	int n = 2;
	while (h < length / n)
	{
		h = n * h + 1;
	}
	while (h >= 1) {
		for (int i = h; i < length; i++)
		{
			for (int j = i; j >= h && a[j] < a[j - h]; j -= h)
			{
				swap(a[j], a[j - h]);
			}
		}
		h = h / n;
	}
}//交换法希尔排序

void shell_sort_insert(int a[], int length)
{
	int h = 1;
	int n = 2;
	int temp = 0;
	while (h < length / n)
	{
		h = n * h + 1;
	}
	while (h >= 1) {
		for (int i = h; i < length; i += h)
		{
			temp = a[i];
			for (int j = i; j > 0; j -= h)
			{
				if (temp < a[j - h])
				{
					a[j] = a[j - h];
				}
				else
				{
					a[j] = temp;
					break;
				}
			}
		}
		h = h / n;
	}
}//插入法希尔排序

void shell_sort_insert2(int a[], int length)
{
	int h = 1;
	int n = 2;
	int temp = 0;
	int i;
	for (int gap = length / 2; gap > 0; gap /= 2) { //增量序列
		/*
		* 下面就是插入排序*/
		for (int j = gap; j < length; j++) {   //从当前增量序列处开始向后遍历
			int tmp = a[j];
			for (i = j; i >= gap && tmp<a[i - gap]; i -= gap) {
				a[i] = a[i - gap];
			}
			a[i] = tmp;
		}
	}
}//插入法希尔排序
int main()
{

	int a[MAX],insert[MAX];
	for (int i = 0; i < MAX; i++)
	{
		a[i] = rand();
		insert[i] = a[i];
		//cout << a[i] << " ";
	}
	cout << endl;
	cout << "#";

	start = clock();
	shell_sort_switch(a, MAX);
	timeend = clock();
	double endtime = (double)(timeend - start);

	start1 = clock();
	shell_sort_insert2(insert, MAX);
	timeend1 = clock();
	double endtime1 = (double)(timeend1 - start1);

	cout << endl;
	cout << "switch time:" << endtime << "ms";
	cout << endl;
	cout << "insert time:" << endtime1 << "ms";


}
