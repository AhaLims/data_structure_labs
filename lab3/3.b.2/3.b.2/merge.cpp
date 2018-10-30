template<typename T>
void MergeSort_r(T * a, T * temp, int left, int right, int & ans) //merge sort using recursion
{
	if (right - left == 1)return;//���ֻ��һ��Ԫ�� ��ֱ�ӷ���
	int mid = (right + left) / 2;
	MergeSort_r(a, temp, left, mid, ans);//�ݹ�ķ�ʽ �������
	MergeSort_r(a, temp, mid, right, ans);//�����ұ�
	int ii = left, i1 = left, i2 = mid;
	for (int i = left; i < right; i++)//copy
		temp[i] = a[i];

	while (i1 < mid && i2 < right)
	{
		//�Ƚ������������
		if (temp[i1] <= temp[i2])// if want to change the rule of sort ,attention here
		{
			a[ii++] = temp[i1++];
			//ans += mid - i1 + 1;
		}
		else
		{
			a[ii++] = temp[i2++];
			ans += mid - i1;//�������Դ���ѧ����
										   //time++;
		}
	}
	//���������ѭ��ֻ�����һ��
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
void MergeSort(T * a, int amount, int & ans)//ʹ�ù鲢���� ֻ��Ҫ�����������
{
	ans = 0;
	int * temp = new T[amount];
	MergeSort_r(a, temp, 0, amount, ans);
	delete[] temp;
}

#include<iostream>
using namespace std;
int main()
{
	int len;
	int * a = nullptr;
	while (true)
	{
		cout << "enter the length of the array :";
		cin >> len;
		a = new int[len];
		int ans;
		for (int i = 0; i < len; i++)
			cin >> a[i];
		MergeSort<int>(a, len, ans);
		for (int i = 0; i < len; i++)
			cout << a[i] << " ";
		cout << "the answer of the question is :" << ans;
		cout << endl;

		//cout << ans;

		delete[] a;

	}
}



