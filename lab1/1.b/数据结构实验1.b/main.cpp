#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class Node
{
public:
	Node(int e)
	{
		element_ = e;
		//next_ = n;
	}
	int element_;
	Node * next_;
};


class LinkLine
{
public:
	LinkLine()
	{
		//cin >> length;
		int e;
		cin >> e;
		Node * tmp = head = new Node(e % 10);
		e /= 10;
		while(e != 0)
		//for (int i = 1; i < length; i++)
		{
			
			//cin >> e;
			tmp->next_ = new Node(e % 10);
			e /= 10;
			tmp = tmp->next_;
		}
	};
	LinkLine(int e)
	{
		Node * tmp = head = new Node(e % 10);
		e /= 10;
		while (e != 0)
			//for (int i = 1; i < length; i++)
		{

			//cin >> e;
			tmp->next_ = new Node(e % 10);
			e /= 10;
			tmp = tmp->next_;
		}
	};
	int getValue()
	{
		Node *tmp = head;
		int index = 1;
		int ans = 0;
		while (tmp != nullptr)
		{
			ans += index * tmp->element_;
			tmp = tmp->next_;
			index *= 10;
		}
		return ans;
	}
	void show()
	{
		Node * tmp = head;
		while (tmp != nullptr)
		{
			cout << tmp->element_ ;
			tmp = tmp->next_;
			if (tmp != nullptr)cout << "->";
		}
		cout << endl;
	}
private:
	Node * head;
	int length;
};


int main()
{
	while (true)
	{
		LinkLine a1, a2;
		a1.show();
		a2.show();
		LinkLine ans(a1.getValue() + a2.getValue());
		ans.show();
		//cout << a1.getValue() + a2.getValue() << endl;
	}
	return 0;
}