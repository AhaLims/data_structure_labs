#include<iostream>
using std::endl;
using std::cout;
using std::cin;
//need test
//preorder postorder inorder
template<typename T>

class binNode
{
public:
	binNode();//root
	binNode(const T &);//root
	binNode(const T &, binNode<T> * f);
	binNode(binNode * f);
	~binNode();

	binNode<T> * setLeft(const T &);
	binNode<T> * setRight(const T &);
	binNode * LeftChild() { return leftChild; };
	binNode * RightChild() { return rightChild; };

	T * left();
	T * right();
	T& element() { return Element; };
	bool ifLeaf();//判断是否叶子节点
	void visit();
	void preorder(binNode <T> *);
	void postorder(binNode <T> *);
	void inorder(binNode <T> *);
	binNode * leftChild, *rightChild, *father;
	T Element;
	int level;//root is level 0
};

template<typename T>
binNode<T>::binNode()
{
	leftChild = rightChild = nullptr;
	Element = 0;
	level = 0;
	father = nullptr;
}

template<typename T>
binNode<T>::binNode(const T & e)
{
	level = 0;
	father = nullptr;
	Element = e;
	leftChild = rightChild = nullptr;
}
template<typename T>
binNode<T>::binNode(const T & e, binNode<T> * f)
{
	leftChild = rightChild = nullptr;
	Element = e;
	father = f;
}

template<typename T>
binNode<T>::binNode(binNode * f)
{
	leftChild = rightChild = nullptr;
	Element = 0;
	father = f;
}

template<typename T>
binNode<T>::~binNode()//delete tree
{
	if (leftChild != nullptr)delete leftChild;
	if (rightChild != nullptr)delete rightChild;
}

template<typename T>
binNode<T> * binNode<T>::setLeft(const T & e)
{
	if (leftChild == nullptr)
		leftChild = new binNode(e, this);
	//else leftChild->setLeft(e);
	else leftChild->Element = e;
	leftChild->level = level + 1;
	return leftChild;
}

template<typename T>
binNode<T> * binNode<T>::setRight(const T & e)
{
	if (rightChild == nullptr)
		rightChild = new binNode(e, this);
	//else rightChild->setRight(e);
	else rightChild->Element = e;
	rightChild->level = level + 1;
	return rightChild;
}

template<typename T>
T * binNode<T>::left()
{
	return leftChild;
}

template<typename T>
T * binNode<T>::right()
{
	return rightChild;
}

template<typename T>
bool binNode<T>::ifLeaf()
{
	if (leftChild == nullptr && rightChild == nullptr)
		return true;
	return false;
}


template<typename T>
void binNode<T>::visit()
{
	std::cout << element() << " ";
}

template<typename T>
void binNode<T>::preorder(binNode <T> * r)//递归的方式 访问节点
{
	if (r == nullptr) return;
	r->visit();
	preorder(r->leftChild);
	preorder(r->rightChild);
}

template<typename T>
void binNode<T>::postorder(binNode <T> * r)
{
	if (r == nullptr) return;
	postorder(r->leftChild);
	postorder(r->rightChild);
	r->visit();
}

template<typename T>
void binNode<T>::inorder(binNode <T> * r)
{
	if (r == nullptr) return;
	inorder(r->leftChild);
	r->visit();
	inorder(r->rightChild);
}

template<typename T>
binNode<T> * buildTree( binNode<T> * root)//用例子建了一棵树
{
	binNode<T> * right = root->setRight(4);
	binNode<T> * left = root->setLeft(5);
	left->setRight(2);
	left->setLeft(8);

	right = right->setLeft(7);
	right->setRight(10);
	return root;
	
}

int main()
{
	binNode<int> tree(1);
	buildTree<int>(&tree);
	cout << "preorder is :";
	tree.preorder(&tree);
	cout << endl;
	cout << "inorder is :";
	tree.inorder(&tree);
	cout << endl;
	cout << "post order is :";
	tree.postorder(&tree);
	cout << endl;
	system("pause");
	return 0;


}