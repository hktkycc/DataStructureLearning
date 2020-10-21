#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
#define MAX 8 //序列长度

int a[MAX], F[MAX];
//快速排序算法
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
//各种查找算法
int Sequential_Search(int* a, int n, int key)
{
	int i;
	for (i = 1; i < n; i++)
	{
		if (a[i] == key)
			return i;
	}
	return -1;
}//序列查找
int Sequential_Search2(int* a, int n, int key)
{
	int i;
	a[0] = key;
	i = n;
	while (a[i] != key)
	{
		i--;
	}
	return i;//返回0则查找失败
}//序列查找改进
int Binary_Search(int* a, int n, int key)
{
	int low, high, mid;
	low = 0;
	high = n;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key < a[mid])
			high = mid - 1;
		else if (key > a[mid])
			low = mid + 1;
		else
			return mid;
	}
	return 0;
}//折半查找
int Interpolation_Search(int* a, int n, int key)
{
	int low, high, mid;
	low = 1;
	high = n;
	while (low <= high)
	{
		mid = low + (high - low) * (key - a[low]) / (a[high] - a[low]);
		if (key < a[mid])
			high = mid - 1;
		else if (key > a[mid])
			low = mid + 1;
		else
			return mid;
	}
	return 0;
}//插值查找
int Fibonacci_Search(int* a, int n, int key)
{
	int low, high, mid, i, k;
	low = 1;
	high = n;
	k = 0;
	while (n > F[k] - 1)
		k++;
	for (i = n; i < F[k] - 1; i++)
		a[i] = a[n];

	while (low < high)
	{
		mid = low + F[k - 1] - 1;
		if (key < a[mid])
		{
			high = mid - 1;
			k = k - 1;
		}
		else if (key > a[mid])
		{
			low = mid + 1;
			k = k - 2;
		}
		else
		{
			if (mid <= n)
				return mid;
			else
				return n;
		}
	}
	return 0;
}


int main()
{
	int* ip = a;
	for (int i = 0; i < MAX; i++)
	{
		ip[i] = rand();
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "#\n";
	//生成测试序列
	F[0] = 1;
	F[1] = 1;
	for (int i = 2; i < MAX; i++)
	{
		F[i] = F[i - 1] + F[i - 2];
	}

	int m1 = Sequential_Search(ip, MAX, 11478);
	int m2 = Sequential_Search2(ip, MAX, 11478);
	Quick_Sort(0, MAX - 1);
	int m3 = Binary_Search(ip, MAX, 11478);
	cout << "Sequential1:" << m1 << "\nSequential2:" << m2 << "\n" << "After Sort: ";
	for (int i = 0; i < MAX; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\nBinary:" << m3;
	int m4 = Interpolation_Search(ip, MAX, 11478);
	cout << "\nInterpolation:" << m4;
	int m5 = Fibonacci_Search(ip, MAX, 11478);
	cout << "\nFibonacci:" << m5;

}
