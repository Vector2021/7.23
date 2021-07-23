#include<iostream>
using namespace std;


void swap(int* p, int* q)
{
	int* temp = p;
	p = q;
	q = temp;
}

//八大排序之选择排序
void selectSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i) //外层循环负责控制循环次数
	{
		int min = i;
		for (int j = i + 1; j < n; ++j) //内层循环负责寻找最小值
		{
			if (a[min] > a[j])
			{
				min = j;
			}

			if (min != i)
			{
				swap(a[i], a[min]);
			}
		}
	}
}


//八大排序值插入排序
void insretSort(int* a, int n)
{
	for (int i = 1; i < n; ++i)
	{
		for (int j = i; j > 0; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
			}
		}
	}
}


//八大排序之快速排序
void Qsort(int* a, int left, int right)
{
	int i = left;
	int j = right;
	int key = a[i];
	if (i >= j) return;
	while (i < j)
	{
		while (i < j && a[j]>=key)
		{
			--j;
		}
		a[i] = a[j];
		while (i < j && a[i] <= key)
		{
			++i;
		}
		a[j] = a[i];
	}
	a[i] = key;
	Qsort(a, left, i - 1);
	Qsort(a, i + 1, right);
}


void display(int* a,int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
}

int main()
{
	int a[8] = { 5,1,3,2,8,6,9,4 };
	//selectSort(a, 8);
	//insretSort(a, 8);
	Qsort(a, 0, 7);
	display(a, 8);
	return 0;
}


