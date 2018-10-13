#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
//....
template<typename T>
class HNode
{
public:
	~HNode() {};
	virtual int weight() = 0;
	virtual bool isLeaf() = 0;
};
template<typename T>
class LeafNode :public HNode<T>
{
public:
	LeafNode(int weight,T e)
	{
		it = e;
		w = weight;
	}
	int weight()
	{
		return w;
	}
	T val()
	{
		return it;
	}
	bool isLeaf()
	{
		return true;
	}
	~LeafNode() {};
private:
	int w;
	T it;
};

template<typename T>
class InNode : public HNode<T>
{
public:
	bool isLeaf() { return false; };
	int weight() { return w; }
	InNode(HNode<T> *lc, HNode<T> * rc)
	{
		lChild = lc;
		rChild = rc;
		w = lc->weight() + rc->weight();
	}
	HNode<T> * leftChild() { return lChild; };
	HNode<T> * rightChild() { return rChild; };
	void setRight(HNode<T> r)
	{
		rchild =(HNode<T> *) r;//why must be tranlated?
	}
	void setLeft(HNode<T> l)
	{
		lChild = (HNode<T> *)l;
	}
private:
	int w;
	HNode<T> * lChild, rChild;
};

template <typename T>
class HuffTree
{
public:
	bool operator <(const HuffTree<T> & p)//use it when building heap 
	{
		return this->weight() < p.weight();
	}
	HuffTree(const T & val, int w)
	{
		Root = new LeafNode<T>(w, val);
	}
	HuffTree(HuffTree<T> * l, HuffTree<T> * r)
	{
		Root = new InNode<T>(l, r);
	}
	~HuffTree()
	{
		delete Root;
	}
	HuffTree<T> * root()
	{
		return Root;
	}
	string HuffCode(T element)
	{
		return "-1";//wrong val get -1
	}
	int weight()
	{
		return root->weight();
	}

private:
	HNode<T> * Root;
};

//template<typename T>
//void sort_(HNode<T> *,int len)
//{
//	
//}
//
//
//template<typename T>
//HNode<T> * BuildHuffTree(int weight[], T val[],int len)//return the root of the hauffTree
//{
//	HNode<T> ** leaf = new HNode<T> * [len];
//	for (int i = 0; i < len; i++)
//	{
//		leaf[i] = new LeafNode<T>(weight[i], val[i]);
//	}
//	sort_(leaf, len);
//	for (int i = 2; i < len; i++)
//	{
//
//	}
//
//}
//use heap to get the min weight node each time 
//so we should define what means the tree is small

template<typename T>
bool minTreeComp(HuffTree<T> a, HuffTree<T> b)
{
	return a.weight() < b.weight();
}


template <typename T>
HuffTree<T> buildHuff(HuffTree<T>**TreeArray, int count)
{
	//priority_queue<int,vector<int>,greater<int> >q;
	priority_queue<HuffTree<T> , vector<HuffTree<T> >, greater<HuffTree<T> > >  forest;
	for (int i = 0; i < count; i++)
	{
		forest.push(*TreeArray[i]);// HuffTree 
	}
	//priority_queue<HuffTree<T> *, minTreeComp> * forest = new priority_queue<HuffTree<T> *, minTreeComp>(TreeArray, count, count);
	HuffTree<T> * temp1, *temp2, *temp3 = nullptr;
	while (forest.size() > 1)
	{
		temp1 = new HuffTree<T>(forest.top());
		forest.pop();
		temp2 = new HuffTree<T>(forest.top());
		forest.pop();
		temp3 = new HuffTree<T>(temp1, temp2);
		forest.push(*temp3);
		delete temp1;
		delete temp2;
	}
	//delete forest;
	return *temp3;
}


//每次合并两个 所以一共合并 n - 1 次
//并且每次合并要new InNode
int main()
{
	char word[] = { 'a','b','c','d','e','f' };
	int weight[] = { 1,2,3,4,5,6 };
	int size = 6;
	HuffTree<char> ** TreeArray = new HuffTree<char>*[size];
	for (int i = 0; i < size; i++)
	{
		TreeArray[i] = new HuffTree<char>(word[i], weight[i]);
		buildHuff(TreeArray, size);
	}
}