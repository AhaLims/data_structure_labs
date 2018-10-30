#include<iostream>
using std::endl;
using std::cout;
using std::cin;
void swap(int & a, int & b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void Fix(int *n, int *b, int left, int right)
{
	if (left >= right)return;

	int temp = n[left];//取一个nuts 将bolts划分成两个子数组
	int i = left, j = right;
	while (i < j)//类似快速排序的过程，不同的是pivot不是bolts数组中的 而是nuts中的一个元素
	{
		while (i < j && b[i] < temp)
		{
			i++;
		}
		while (i < j && b[j] > temp)
		{
			j--;
		}
		if (i < j)
		{
			swap(b[i], b[j]);
		}
	}
	b[i] = temp;
	swap(b[left], b[i]);
	//一趟下来，i=j的tmp的位置。以tmp为界限，左右分别是小于和大于它的元素

	//再用bolts中的一个元素将nuts数组划分为两个子数组
	temp = b[left + 1];
	i = left + 1, j = right;
	while (i < j)
	{
		while (i < j && n[i] < temp)
		{
			i++;
		}
		while (i < j && n[j] > temp)
		{
			j--;
		}
		if (i < j)
		{
			swap(n[i], n[j]);
		}
	}
	n[i] = temp;
	swap(n[left + 1], n[i]);
	//分为两个数组之后，递归的调用函数
	Fix(n, b, left + 2, i);
	Fix(n, b, i + 1, right);
}

void print(int * a, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int main()
{
	int nuts[10] = { 5,7,1,3,6,4,2,9,10,8 };
	int bolts[10] = { 10,8,4,2,9,6,3,1,5,7 };
	int size = 8;
	Fix(nuts, bolts, 0, 9);
	print(nuts, 10);
	print(bolts, 10);
	system("pause");
	return 0;
	//sort(nuts, bolts, 0,size - 1);
}