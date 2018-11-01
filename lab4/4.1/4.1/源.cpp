#include<iostream>
using namespace std;

void swap(char & a, char & b)
{
	char temp;
	temp = a;
	a = b;
	b = temp;
}

//use count way
int counter(char * a,int size, char v,int * time) //return compare time
{
	int compare_time = 0;//每一轮比较的次数
	for (int i = 0; i < size; i++)
	{
		compare_time++;
		if (v == a[i])
		{
			time[i]++;
			for (int j = i; j > 0; j--)
				if (time[j] > time[j - 1])
				{
					swap(a[j], a[j - 1]);
					swap(time[j], time[j - 1]);
				}
			return compare_time;
		}
	}

	return -1;

	
}
struct node
{
	node(char d)
	{
		data = d;
	}
	node(char d, node * n)
	{
		data = d;
		next = n;
	}
	char data;
	node * next;
};
int move_to_front(char * a, int a_size, char * v, int v_size)//找到一条记录就将他放在最前端
{
	int compare_time = 0;
	//first : make a list
	node * head = new node(a[0]);
	node * cur = head;
	for (int i = 1; i < a_size; i++) 
	{
		cur->next = new node(a[i]);
		cur = cur->next;
	}
	cur->next = head;
	cur = head;

	for (int i = 0; i < v_size; i++)
	{
		compare_time++;
		while (cur->data != v[i])
		{
			compare_time++;
			cur = cur->next;
		}
	}
	head = cur;
	int i = 0;
	a[i++] = cur->data;
	//cout << cur->data << " ";
	cur = cur->next;
	while (cur != head)
	{
		a[i++] = cur->data;
		//cout << cur->data << " ";
		cur = cur->next;
	}
	return compare_time;
}

int transpose(char * a, int a_size, char * v, int v_size)
{
	int compare_time = 0;
	for (int i = 0; i < v_size; i++)
	{
		for (int j = 0; j < a_size; j++)
		{
			compare_time++;
			if (a[j] == v[i])
			{
				if (j != 1)swap(a[j], a[j - 1]);
				break;
			}
		}
		
	}
	return compare_time;
}


void visit(char * c, int size)//output the final linear table
{
	for (int i = 0; i < size; i++)
		cout << c[i] << " ";
	cout << endl;
}

int main()
{
	char l[] = { 'A','B','C','D','E','F','G','H' };
	int time[8] = {0};
	//char visit_char[] = { "DHHGHEGHGHECEHG" };
	char visit_char[] = { "HGHGFEFEHGHG" };
	int size = 8;
	int visit_time = 12;//16
	int compare_time = 0;
	//使用计数方法:
	//for (int i = 0; i < visit_time; i++)
	//{
		//compare_time += counter(l, size, visit_char[i],time);
		
		
	//}
	//使用转置方法：
	//compare_time += transpose(l, size, visit_char, visit_time);

	//使用移至前端方法：
	compare_time += move_to_front(l, size, visit_char, visit_time);
	cout << "compare time is: " << compare_time << "\n";
	visit(l, size);
	system("pause");
	return 0;
}