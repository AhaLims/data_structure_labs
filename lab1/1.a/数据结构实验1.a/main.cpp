//use link list 
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
template<typename T>
class LinearTable
{
public:
	T * getElement(int pos)//no check
	{
		return head[pos];
	}
	void setElement(const T e, int pos)
	{
		head[pos] = e;
	}
	int size()
	{
		return Size_;
	}
	int maxsize()
	{
		return MaxSize;
	}
	LinearTable()//set MaxSize = 100 as default
	{
		MaxSize = 100;
		Size_ = 0;
		head = new T[MaxSize];
	}
	LinearTable(int size)
	{
		head = new T[size + 10];
		//for (int i = 0; i < size; i++)
		//{
			//cin >> head[i];
		//}
		Size_ = size;
		MaxSize = size + 10;
	}
	LinearTable(T * e,int size)
	{
		head = new T[size + 10];
		for (int i = 0; i < size; i++)
		{
			head[i] = e[i];
		}
		Size_ = size;
		MaxSize = size + 10;
	}
	~LinearTable()
	{
		delete[] head;
	}
	void resize(int size_)//allocate more space but do nothing on data
	{
		if (size_ > MaxSize)
		{
			MaxSize = size_;
			T * tmp = head;
			head = new T[size_];
			for (int i = 0; i < Size_; i++)
				head[i] = tmp[i];
			delete[] tmp;
			
		}
	}
	void traverse()
	{
		for (int i = 0; i < Size_; i++)
			cout << head[i] << " ";
	}
	void append(const T & e)//add element on the tail
	{
		resize(Size_ + 1);
		head[Size_++] = e;
	}
	int findElement(const T & e)//if find->return 1 ,else return -1
	{
		for (int i = 0; i < Size_; i++)
		{
			if (e == head[i])return i;
		}
		return -1;
	}
	bool deleteElement(int pos)
	{
		if (pos >= Size_)return false;
		for (int i = pos; i < Size_ - 1; i++)
		{
			head[i] = head[i + 1];
		}
		Size_--;
		return true;
	}
	bool insertElement(const T e, int pos)
	{
		if (pos > Size_)return false;
		resize(Size_ + 1);					//allocate more space if necessary
		
		for (int i = pos;i < Size_; i++)
		{
			head[i + 1] = head[i];
		}
		Size_++;
		head[pos] = e;
		return true;
	}
	//how to define the compare rule ? Use function pointer or use default rule?


	//static LinearTable<T> * merge(const LinearTable<T> * a1,const LinearTable<T> * a2)			//merge two sequential linear table
	//{
	//	LinearTable<T> * tmp = new LinearTable(a1->size() + a2->size());
	//	int i = 0, j = 0,pos = 0;
	//	while (i < a1->size() && j < a2->size)
	//	{
	//		if ()//
	//		{
	//			tmp->setElement( a1->getElement(i++),pos++);
	//		}
	//		else tmp->setElement(a2->getElement(j++), pos++);
	//	}
	//	while (i < a1->size)
	//	{
	//		tmp->setElement(a1->getElement(i++), pos++);
	//	}
	//	while (j < a2->size)
	//	{
	//		tmp->setElement(a2->getElement(j++), pos++);
	//	}
	//	return tmp;
	//}
private:
	T * head;
	int Size_;
	int MaxSize;
};

//an simplified shell
int main()
{
	int order,pos,tmp;
	bool ifBuild = false;
	LinearTable<int> * a  = nullptr, * b = nullptr;
	while (true) 
	{
		cout << "---------------------------------------------------------------------------------\n";
		cout << "enter order\n";
		cout << "1.build a linear table\n";
		cout << "2.traverse\n";
		cout << "3.search an element and show whether this element is in the linear table\n";
		cout << "4.insert an element\n";
		cout << "5.delete an element\n";
		cout << "6.merge two sequential linear table\n";
		cin >> order;
		switch (order - 1)
		{
		case 0:
			if (a != nullptr)delete a;
			cout << "the size is\n";
			cin >> order;
			a = new LinearTable<int>(order);
			cout << "enter element of the linear table\n";
			for (int i = 0; i < order; i++)
			{
				cin >> tmp;
				a->setElement(tmp, i);
			}
			break;
		case 1:
			if (a == nullptr)
			{
				cout << "wrong!\nHas not bulit the linear table\n";
				continue;
			}
			a->traverse();
			cout << endl;
			break;
		case 2:
			if (a == nullptr)
			{
				cout << "wrong!\nHas not bulit the linear table\n";
				continue;
			}
			cout << "enter the element you want to search\n";
			cin >> tmp;
			pos = a->findElement(tmp);
			if (pos == -1)cout << "can not be found\n";
			else
			{
				cout << "has been found\nthis element is in\n" << pos + 1 << endl;
			}
			break;
		case 3:
			if (a == nullptr)
			{
				cout << "wrong!\nHas not bulit the linear table\n";
				continue;
			}
			cout << "enter the place and the element you want to insert\n";
			cin >> pos >> tmp;
			if (a->insertElement(tmp, pos - 1))cout << "success!\n";
			else cout << "failed\n";
			break;
		case 4:
			if (a == nullptr)
			{
				cout << "wrong!\nHas not bulit the linear table\n";
				continue;
			}
			cout << "enter the place and the element you want to insert\n";
			
			cin >> pos;
			if (a->deleteElement(pos - 1))cout << "success!\n";
			else cout << "failed\n";
			break;
		case 5:
			if (a == nullptr)
			{
				cout << "wrong!\nHas not bulit the linear table\n";
				continue;
			}
			cout << "has not built\n";
			break;
		default:
			cout << "you have enter wrong order,please try again\n";
		}
	}
	if (a != nullptr)delete a;
	if (b != nullptr)delete b;
}
