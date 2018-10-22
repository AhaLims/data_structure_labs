


template<typename T>
void MergeSort_r(T * a,T * temp,int left,int right) //merge sort using recursion
{
	if (right - left == 1)return;
	int mid = (right + left) / 2;
	MergeSort_r(a,temp, left, mid);
	MergeSort_r(a, temp,mid, right);
	int ii = left,i1 = left, i2 = mid;
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
void MergeSort_nr(T * a,int amount)//use stack to implement merge sort
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



