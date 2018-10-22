template<typename T>
class QS
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

		qsort(a, left, k - 1);
		qsort(a, k + 1, right);
	}
};


#include<iostream>
using namespace std;
int main()
{
	int a[10] = { 1,67,3,2,5,7,3,232,45,233 };
	QS<int>::QuickSort(a, 10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	system("pause");
	return 0;
}