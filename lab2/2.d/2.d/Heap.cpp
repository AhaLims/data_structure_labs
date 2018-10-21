#include"Heap.h"
#include<iostream>
//自适应大小的

//template <typename T>
//void Heap<T>::ShiftDown(int pos)
//{
//	int child;
//	while (!isLeaf(pos))
//	{
//		child = LeftChild(pos);
//
//		if (RightChild(pos) < size_ && Comp::Compare(data[RightChild(pos)], data[LeftChild(pos)]) )
//			child = RightChild(pos);
//		if(Comp::Compare(data[child],data[pos]))
//		//if (data[pos] < data[child])
//		{
//			int tmp = data[pos];
//			data[pos] = data[child];
//			data[child] = tmp;
//			pos = child;
//		}
//		else break;
//	}
//}


//template <typename T>
//Heap<T>::Heap(T * d, int num, int Max):size_(num),maxsize(Max)
//{
//	data = new T[Max];
//	for (int i = 0; i < num; i++)
//	{
//		data[i] = d[i];
//	}
//	bulidHeap();
//}

//template <typename T>
//Heap::Heap()
//{
//	
//}

//template <typename T>
//bool Heap<T>::isLeaf(int pos)const
//{
//	if ((pos + 1) * 2 <= size_)return false;//wrong?
//	else return true;
//}

//template <typename T>
//int Heap<T>::LeftChild(int pos)const
//{
//	if (isLeaf(pos))return -1;// does have leftchild;
//	return (pos + 1) * 2;
//}

//template <typename T>
//int Heap<T>::RightChild(int pos)const
//{
//	if (isLeaf(pos))return -1;
//	return (pos + 1) * 2 - 1;
//}
//
//template <typename T>
//int Heap<T>::parent(int pos)const
//{
//	if (pos == 0)return -1;
//	return (pos + 1) / 2 - 1;
//}

//template <typename T>
//void Heap<T>::bulidHeap() //build heap from the bottom of node(not leaf)
//{
//	
//}

//template <typename T>
//void Heap<T>::push(const T & item)
//{
//	if (maxsize == size_)
//	{
//		std::cout << "now heap is full and automaic apply bigger space to contain this data\n";
//		T * tmp = new T[maxsize * 2];
//		for (int i = 0; i < size_; i++)
//			tmp[i] = data[i];
//		delete[] data;
//		data = tmp;	
//	}
//	int curr = size_++;
//	data[curr] = item;
//	//shift up
//	//大根堆 就是
//	int father = (curr + 1) / 2 - 1;
//	//while (curr > 0 && data[curr] > data[father])
//	while (curr > 0 && Comp::Compare(data[curr] , data[father]))
//	{
//		int tmp = data[father];
//		data[father] = data[curr];
//		data[curr] = tmp;
//		curr = father;
//		father = (curr + 1) / 2 - 1;
//	}
//}

//template <typename T>
//T Heap<T>::pop()
//{
//	int tmp = data[0];
//	data[0] = data[--size_];
//	ShiftDown(0);
//	return tmp;
//}

template <typename T>
T Heap<T>::remove(int pos)//maybe wrong...
{
	int tmp = data[pos];
	data[pos] = data[--size_];
	size_--;
	ShiftDown(pos);
	return tmp;
}
//
//
//using std::cout;
//using std::cin;
//int main()
//{
//	int d[] = { 5,9,7,1,3};
//	Heap<int> heap(d, 5, 10);
//	while (true)
//	{
//		int order;
//		int e;
//		cout << "enter order\n";
//		cout << "1.insert an element\n";
//		cout << "2.remove first element\n";
//		cout << "3.remove place i element and enter the element\n";
//		cout << "4.see this array\n";
//		cin >> order;
//		switch (order)
//		{
//		case 1:
//			cout << "enter the element\n";
//			cin >> e;
//			heap.insert(e);
//			break;
//		case 2:
//			heap.removeFirst();
//			break;
//		case 3:
//			cout << "enter the place\n";
//			cin >> e;
//			heap.remove(e);
//			break;
//		case 4:
//			heap.show();
//			break;
//		}
//	}
//}
