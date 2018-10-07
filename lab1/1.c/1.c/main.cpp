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
	}
	int element_;
	Node * next_;
};


class LinkLine
{
public:
	LinkLine()//enter the length and element of the link line
	{
		cout << "please enter the size of the link line\n";
		cin >> length;
		int e;
		cout << "please enter the element of the link line\n";
		cin >> e;
		Node * tmp = head = new Node(e);
		for (int i = 1; i < length; i++)
		{
			cin >> e;
			tmp->next_ = new Node(e);
			tmp = tmp->next_;
		}
	}
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
			cout << tmp->element_;
			tmp = tmp->next_;
			if (tmp != nullptr)cout << "->";
		}
		cout << endl;
	}
	int getLength() { return length; };

	bool remove(int pos)
	{
		if (pos > length)return false;
		Node * tmp1 = head,* tmp2 = head;
		for (int i = 2; i < pos; i++)
		{
			tmp2 = tmp2->next_;
			tmp1 = tmp1->next_;
		}
		if (pos != 1)
		{
			tmp1 = tmp1->next_;
			tmp2->next_ = tmp1->next_;
		}
		else
		{
			tmp1 = head;
			head = head->next_;
		}
		delete tmp1;
		length--;
		return true;
	};
private:
	Node * head;
	int length;
};


int main()
{
	int n;
	while (true)
	{
		LinkLine a;
		a.show();
		cout << "enter n:";
		cin >> n;
		while (n > a.getLength())//make sure n is smaller than length
		{
			cout << "false\nenter n again\n";
			cin >> n;
		}
		a.remove(a.getLength() - n + 1);//maybe some problem
		a.show();

	}
}