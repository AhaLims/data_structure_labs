#pragma once


/*
1.check the heap class by making more examples
2.encapsulate the class into a priority queue
*/
template <typename T>
class Heap
{
private:
	T * data;
	int maxsize;//max size of the heap
	int size_;//actually size
	void ShiftDown(int pos)
	{
		int child;
		while (!isLeaf(pos))
		{
			child = LeftChild(pos);

			if (RightChild(pos) < size_ && Comp::Compare(data[RightChild(pos)], data[LeftChild(pos)]))
				child = RightChild(pos);
			if (Comp::Compare(data[child], data[pos]))
				//if (data[pos] < data[child])
			{
				T tmp = data[pos];
				data[pos] = data[child];
				data[child] = tmp;
				pos = child;
			}
			else break;
		}
	}
public:
	Heap(T * d, int num, int Max) :size_(num), maxsize(Max)
	{
		data = new T[Max];
		for (int i = 0; i < num; i++)
		{
			data[i] = d[i];
		}
		bulidHeap();
	}
	Heap():size_(0),maxsize(255)
	{

	};
	//Heap();
	~Heap() {delete[] data; };
	int size()const { return n; };
	bool isLeaf(int pos)const
	{
		if ((pos + 1) * 2 <= size_)return false;//wrong?
		else return true;
	}
	int LeftChild(int pos)const
	{
		if (isLeaf(pos))return -1;// does have leftchild;
		return (pos + 1) * 2;
	}
	int RightChild(int pos)const
	{
		if (isLeaf(pos))return -1;
		return (pos + 1) * 2 - 1;
	}
	int parent(int pos)const
	{
		if (pos == 0)return -1;
		return (pos + 1) / 2 - 1;
	}
	void bulidHeap()
	{
		for (int i = size_ / 2 - 1; i >= 0; i--)
		{

			ShiftDown(i);
			cout << "i = " << i << " " << data[i] << "\n";
		}
	}
	void push(const T & item)
	{
		int curr = size_++;
		data[curr] = item;
		//shift up
		//大根堆 就是
		int father = (curr + 1) / 2 - 1;
		//while (curr > 0 && data[curr] > data[father])
		while (curr > 0 && Comp::Compare(data[curr], data[father]))
		{
			T tmp = data[father];
			data[father] = data[curr];
			data[curr] = tmp;
			curr = father;
			father = (curr + 1) / 2 - 1;
		}
	}
	T pop()//remove the top element of the Heap
	{
		T tmp = data[0];
		data[0] = data[--size_];
		ShiftDown(0);
		return tmp;
	};
	T remove(int pos);//remove any pos of the heap

	void show()const
	{
		for (int i = 0; i < size_; i++)
			cout << data[i] << " ";
		cout << std::endl;
	}
	//search find
	//change





};


namespace Comp
{
	template<typename T>
	bool Compare(const T & a, const T & b)//if want to get a small root heap,just need to change the compare rule
	{
		if (a > b) return true;
		return false;
	}

}
