#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using std::cout;
using std::cin;
using std::endl;
using std::min;



//assume that a_amount is smaller
int find(int *a, int a_amount,int *b,int b_amount,int pos_k)
{
	if (a_amount > b_amount)return (b, b_amount, a, a_amount, pos_k);//make sure a_amount is smaller

	if (pos_k == 1)return a[0] < b[0] ? a[0] : b[0];//return the smaller 
	if (a_amount == 0)return b[pos_k];//a array is empty ,so number k is b[k]

	int tmp_a = min(pos_k / 2 - 1,a_amount - 1);
	int tmp_b = min(pos_k / 2 - 1, b_amount - 1);

	if (a[tmp_a] < b[tmp_b])return find(a + tmp_a, a_amount - tmp_a, b, b_amount, pos_k - tmp_a);

	else if (a[tmp_a] > b[tmp_b]) return find(a, a_amount, b + tmp_b, b_amount - tmp_b, pos_k - tmp_a);

	else return a[tmp_a];
}




double solve(int a[], int b[], int size_A, int size_B)
{
	int sum_ = size_A + size_B;
	if ((sum_ % 2) == 0) //sum % 2 == 0
		return double(find(a, size_A, b, size_B, sum_ / 2 )+ find(a, size_A, b, size_B, (sum_ / 2) ) + 1 )/ 2.0;
	else
		return find(a, size_A, b, size_B, sum_ / 2 + 1);
	
}


int main()
{
	int *a = nullptr, *b = nullptr;
	int size_A, size_B;
	while (cin>>size_A>>size_B)
	{
		if (a != nullptr)delete[] a;
		if (b != nullptr)delete[] b;
		a = new int[size_A];
		b = new int[size_B];
		for (int i = 0; i < size_A; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < size_B; i++)
		{
			cin >> b[i];
		}
		//input a,b
		cout<<"the answer is : "<<solve(a, b, size_A, size_B)<<endl;
		cout << "enter amount of two array\n";
	}
}