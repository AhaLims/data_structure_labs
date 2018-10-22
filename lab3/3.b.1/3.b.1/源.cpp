


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
template<typename T>
void MergeSort(T * a, int amount)
{
	int * temp = new T[amount];
	MergeSort_r(a, temp, 0, amount);

	delete[] temp;
}


template<typename T>
T solve(T * a,int amount)
{
	MergeSort(a, amount);
	int time = 1;
	for (int i = 0; i < amount; i++)cout << a[i] << " ";
	for (int i = 0; i < amount - 1; i++)
	{
		if (a[i] == a[i + 1])
		{
			time++;
			if (time > (amount / 2))
			{
				return a[i];
			}
		}
		else time = 1;
		
	}
}

//attention: must make sure that there are at least one answer!!!
#include<iostream>
using namespace std;
int main()
{
	int *a;
	int length;
	while (true)
	{
		cout << "enter the length of the array";
		cin >> length;
		a = new int[length];
		for (int i = 0; i < length; i++)
			cin >> a[i];
		cout << "the answer is :"<<solve<int>(a, length) << endl;
		delete[] a;
	}
}



