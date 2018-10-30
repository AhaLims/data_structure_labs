
//冒泡排序

template<typename T>
void swap(T & a1, T & a2)
{
	T temp = a1;
	a1 = a2;
	a2 = temp;
}


template<typename T>
void BubbleSort(T * a, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j < amount - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}



//归并排序

template<typename T>
void MergeSort_r(T * a, T * temp, int left, int right) //merge sort using recursion
{
	if (right - left == 1)return;
	int mid = (right + left) / 2;
	MergeSort_r(a, temp, left, mid);
	MergeSort_r(a, temp, mid, right);
	int ii = left, i1 = left, i2 = mid;
	for (int i = left; i < right; i++)
		temp[i] = a[i];
	while (i1 < mid && i2 < right)// if want to change the rule of sort ,attention here
	{
		if (temp[i1] > temp[i2])
		{
			a[ii++] = temp[i1++];
		}
		else a[ii++] = temp[i2++];
	}
	while (i1 < mid)
	{
		a[ii++] = temp[i1++];
	}
	while (i2 < right)
	{
		a[ii++] = temp[i2++];
	}
	return;


}


#include<stack>
using std::stack;
struct subarray
{
	subarray(int l, int r)
	{
		right = r;
		left = l;
		ifSort = false;
	};
	bool ifSort;
	int right, left;
};
template <typename T>
void MergeSort_nr(T * a, int amount)//use stack to implement merge sort
{
	T * temp = new T[amount];
	stack<subarray>s;
	subarray current(0, amount);
	s.push(current);
	while (!s.empty())
	{
		current = s.top();
		if (current.right - current.left == 1)
		{
			s.pop();
			continue;
		}
		int mid = (current.left + current.right) / 2;
		if (current.ifSort == false)//make sure we solve it when meet it twice
		{
			s.pop();
			current.ifSort = true;
			s.push(current);
			s.push(subarray(current.left, mid));
			s.push(subarray(mid, current.right));
			continue;
		}

		//merge sort part
		int ii = current.left, i1 = current.left, i2 = mid;
		for (int i = current.left; i < current.right; i++)
			temp[i] = a[i];
		while (i1 < mid && i2 < current.right)
		{
			if (temp[i1] > temp[i2])// if want to change the rule of sort ,attention here
			{
				a[ii++] = temp[i1++];
			}
			else a[ii++] = temp[i2++];
		}
		while (i1 < mid)
		{
			a[ii++] = temp[i1++];
		}
		while (i2 < current.right)
		{
			a[ii++] = temp[i2++];
		}
		s.pop();
	}
}

template<typename T>
void MergeSort(T * a, int amount)
{
	int * temp = new T[amount];
	MergeSort_r(a, temp, 0, amount);

	delete[] temp;
}



//插入排序


template<typename T>
void InsertSort(T * a, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j < amount; j++)
		{
			if (a[j] < a[i])swap(a[j], a[i]);
		}
	}
}



//选择排序

template<typename T>
void SelectSort(T a[], int n) //选择排序
{
	T mix, temp;
	for (int i = 0; i<n - 1; i++) //每次循环数组，找出最小的元素，放在前面，前面的即为排序好的
	{
		mix = i; //假设最小元素的下标
		for (int j = i + 1; j<n; j++) //将上面假设的最小元素与数组比较，交换出最小的元素的下标
			if (a[j]<a[mix])
				mix = j;
		//若数组中真的有比假设的元素还小，就交换
		if (i != mix)
		{
			temp = a[i];
			a[i] = a[mix];
			a[mix] = temp;
		}
	}
	return;
}











//快速排序



template<typename T>
class QS//make quicksort into a class,the only surface is QuickSort function
{
public:
	static void QuickSort(T * a, int amount)
	{
		qsort(a, 0, amount - 1);
	}
private:
	static int findpivot(T * a, int left, int right)
	{

		return (left + right) / 2;
	}

	static void swap_(T * a, int i, int j)
	{
		T tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}

	static int partition(T * a, int left, int right, const T & pivot)
	{
		do
		{
			while (a[++left] < pivot);
			while ((left < right) && pivot < a[--right]);
			swap_(a, left, right);
		} while (left < right);
		return left;
	}

	static void qsort(T * a, int left, int right)
	{
		if (right <= left)return;
		int pivot = findpivot(a, left, right);
		swap_(a, pivot, right);//swap pivot element and the last element
		int k = partition(a, left - 1, right, a[right]);// becasue use ++l so give i - 1 instead of i

		swap_(a, k, right);//put the pivot in place!

		qsort(a, left, k - 1);//now pivot index is k!!
		qsort(a, k + 1, right);
	}
};


#include<iostream>
#include<stdlib.h>
#include <time.h> 
const int rand_max = 10000;//数据范围 0-10000
const int maxn = 10000;//10000个数据
using namespace std;
int main()
{
	int a[5][maxn];
	for (int i = 0; i < maxn; i++)
	{
		a[0][i] = rand() % rand_max;
		a[1][i] = a[0][i];
		a[2][i] = a[0][i];
		a[3][i] = a[0][i];
		a[4][i] = a[0][i];
	}
	clock_t start, finish;
	double totaltime;
	start = clock();
	InsertSort(a[0], maxn);
	finish = clock();
	totaltime = finish - start;
	cout << "insert sort time: " << totaltime  << " ms\n";

	start = clock();
	BubbleSort(a[1], maxn);
	finish = clock();
	totaltime = finish - start;
	cout << "bubble sort time: " << totaltime << " ms\n";

	start = clock();
	SelectSort(a[2], maxn);
	finish = clock();
	totaltime = finish - start;
	cout << "select sort time: " << totaltime << " ms\n";

	start = clock();
	QS<int>::QuickSort(a[3], maxn);
	finish = clock();
	totaltime = finish - start;
	cout << "quick sort time: " << totaltime << " ms\n";

	start = clock();
	MergeSort(a[4], maxn);
	finish = clock();
	totaltime = finish - start;
	cout << "merge sort time: " << totaltime << " ms\n";


	system("pause");
	return 0;
}