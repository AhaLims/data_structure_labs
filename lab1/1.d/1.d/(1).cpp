////#include<iostream>
////#include<time.h>
////using std::cin;
////using std::cout;
////using std::endl;
//////maybe with the problem of memory let out.
//////without delete
////template <typename T>
////class Node
////{
////public:
////	Node()
////	{
////		next_ = nullptr;
////	}
////	Node(T e)
////	{
////		element_ = e;
////		//next_ = n;
////	}
////	T element_;
////	Node * next_;
////};
////
////
//////give the head of the link lined and the length of the link line
////template <typename T>
////bool solve(T * head)
////{
////	T * fast = head, * slowly = head;
////	//use two pointer.One is faster and the other is slow
////
////	//if they meet in the loof, this link line has loop
////	while (fast != nullptr)
////	{
////		fast = fast->next_;
////		if (fast == nullptr)break;
////		fast = fast->next_;
////		slowly = slowly->next_;
////		if (fast == slowly)return true;
////	}
////	return false;
////	
////}
////
////template<typename T>
////Node<T> *loop_link(int size_)//return the head of a linked line with a loop
////{
////	Node<T> * current;
////	Node<T> * loop;
////	current = loop = new Node<T>();
////	for (int i = 0; i < size_; i++)
////	{
////		current->next_ = new Node<T>();
////		current = current->next_;
////	}
////
////	//this is a link line with a loop
////	current->next_ = loop;
////	return loop;
////}
////
////template<typename T>
////Node<T> * non_loop_link(int size_)
////{
////	Node<T> * current;
////	Node<T> * non_loop;
////	current = non_loop = new Node<T>();
////	for (int i = 0; i < size_; i++)
////	{
////		current->next_ = new Node<T>();
////		current = current->next_;
////	}
////	return non_loop;
////}
////
////
////int main()
////{
////	//srand((int)time(0));
////	//int x;
////	//Node<int> * loop, * non_loop;
////	//Node<int> * current;
////	//current = loop = new Node<int>(0);
////	//for (int i = 1; i < rand() % x; i++)
////	//{
////	//	current->next_ = new Node<int>(i);
////	//	current = current->next_;
////	//}
////
////	////this is a link line with a loop
////	//current->next_ = loop;
////
////	////link line without loop
////	//current = non_loop = new Node<int>(10);
////	//for (int i = 11; i < 20; i++)
////	//{
////	//	current->next_ = new Node<int>(i);
////	//	current = current->next_;
////	//}
////	int time = 1000;
////	while (time--)
////	{
////
////
////		Node<int> * loop, *non_loop;
////		loop = loop_link<int>(rand() % 100);
////		non_loop = non_loop_link<int>(rand() % 100);
////		if (solve(loop) == 1 && solve(non_loop) == 0)continue;
////		else cout << "wrong";
////		//test part.
////		//wrong will be input
////		//continue to make a non-loop + loop
////		
////	}
////	system("pause");
////	return 0;
////}