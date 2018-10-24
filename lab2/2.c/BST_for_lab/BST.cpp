//need to be test
#include<stdio.h>
#include<iostream>
using std::endl;
using std::cout;
using std::cin;



template <typename E>
class BinNode
{
public:
	virtual ~BinNode() {};

	virtual E  element()const = 0;

	virtual void setElement(const E &) = 0;

	virtual bool isLeaf()const = 0;
};

template<typename Key,typename E>
class BSTNode : public BinNode<E>
{
public:
	BSTNode()
	{
		lc = rc = nullptr;
	};
	BSTNode(Key kk, E e, BSTNode * l = nullptr, BSTNode * r = nullptr)
	{
		k = kk;
		it = e;
		lc = l;
		rc = r;
	};
	~BSTNode()
	{

	};
	//E & element() const////////////////////////////////why wrong??
	E element() const
	{
		return it;
	};
	void setElement(const E & e)
	{
		it = e;
	};
	Key & key()
	{
		return k;
	};
	void setKey(const Key & K)
	{
		k = K;
	};

	inline BSTNode * left()const
	{
		return lc;
	}

	inline BSTNode * right()const
	{
		return rc;
	}

	void setLeft(BinNode<E> * b)
	{
		//lc = (BSTNode *)b;
		lc = (BSTNode *)b;
	}
	void setRight(BinNode<E> * b)
	{
		rc = (BSTNode  *)b;
	}

	

	bool isLeaf()const
	{
		return(lc == nullptr && rc == nullptr);
	}

	void visit()const
	{
		cout << k << " " << it << endl;
	}

	//用递归的方式 实现前序中序后序遍历
	void preorder(BSTNode * r)const
	{
		if (r == nullptr)return ;
		r->visit();
		preorder(r->left());
		preorder(r->right());
	}
	void inorder(BSTNode * r)const
	{
		if (r == nullptr)return;
		inorder(r->left());
		r->visit();
		inorder(r->right());
	}
	void postorder(BSTNode * r)const
	{
		if (r == nullptr)return;
		postorder(r->left());
		postorder(r->right());
		r->visit();
	}



private:
	Key k;
	E it;
	BSTNode * lc;
	BSTNode * rc;


};

template<typename Key,typename E>
class BST //:public Dictionary<Key,E>
{
	//public 部分 封装了insert remove find 遍历的函数
public:
	BST()
	{
		root = nullptr;
	}
	~BST()
	{
		clearhelp(root);
	}
	BST(const Key & k,const E & e)
	{
		root = new BSTNode<Key, E>(k, e);
	}

	void insert(const Key & k, const E & e)
	{
		root = inserthelp(root, k, e);
		nodecount++;
	}

	E remove(const Key & k)
	{
		bool if_find = false;
		E temp = findhelp(root, k,if_find);
		if (temp != NULL) //???
		{
			root = removehelp(root, k);
			nodecount--;
		}
		return temp;
	}

	E removeAny()
	{
		if (root != nullptr)
		{
			E temp = root->element();
			root = removehelp(root, root->key());
			nodecount--;
			return temp;
		}
		else return nullptr;
	}

	void find(const Key & k)const
	{
		bool if_find = false;
		findhelp(root, k,if_find);
		if (if_find == true)
		{
			cout << "find\n";
		}
		else
		{
			cout << "cannot be found\n";
		}
	}

	int size()
	{
		return nodecount;
	}

	//void print()const
	//{
	//	if(root == nullptr)cout<<"The BST tree is empty";
	//	else printhelp(root,0);
	//}
	void preorder()const
	{
		root->preorder(root);
	}
	void inorder()const
	{
		root->inorder(root);
	}
	void postprder()const
	{
		root->postorder(root);
	}

private:
	BSTNode<Key, E>*root;
	int nodecount;

	void clearhelp(BSTNode<Key, E> * r)//delete所有的节点
	{
		if (r == nullptr)return;
		clearhelp(r->left());
		clearhelp(r->right());
		delete r;
	};

	BSTNode<Key, E>* inserthelp(BSTNode<Key, E> * root_, const Key & k, const E & it)
	{
		if (root_ == nullptr)//如果当前节点为空 new
		{
			BSTNode<Key, E> * temp = new BSTNode<Key, E>(k, it, nullptr, nullptr);
			return temp;
			//return new BSTNode<Key, E>(k, it, nullptr, nullptr);
		}
		if (k < root_->key())//根据关键值 选择进入左孩子 还是右孩子
		{
			root_->setLeft(inserthelp(root_->left(), k, it));
		}
		else root_->setRight(inserthelp(root_->right(), k, it));
		return root_;
		// do not understand
	}

	BSTNode<Key, E> * deletemin(BSTNode<Key, E> * rt)
	{
		if (rt->left() == nullptr)return rt->right();
		else
		{
			rt->setLeft(deletemin(rt->left()));
			return rt;
		}
	};

	BSTNode<Key, E> * getmin(BSTNode<Key, E> * rt)
	{
		if (rt->left() == nullptr)return rt;
		else return getmin(rt->left());
	};

	BSTNode<Key, E> * removehelp(BSTNode<Key, E> * rt,const Key & k)
	{
		if (rt == nullptr) return nullptr;
		else if (k < rt->key())rt->setLeft(removehelp(rt->left(), k));
		else if (k > rt->key())rt->setRight(removehelp(rt->right(), k));
		else
		{
			BSTNode<Key, E> * temp = rt;
			if (rt->left() == nullptr)
			{
				rt = rt->right();
				delete temp;
			}
			else if (rt->right() == nullptr)
			{
				rt = rt->left();
				delete temp;
			}
			else
			{
				BSTNode<Key, E> * temp = getmin(rt->right());
				rt->setElement(temp->element());
				rt->setKey(temp->key());
				rt->setRight(deletemin(rt->right()));
				delete temp;
			}
		}
		return rt;
	};

	E findhelp(BSTNode<Key, E>* root_,const Key & k,bool & if_find)const
	{
		if (root_ == nullptr)return NULL;
		if (k < root_->key())return findhelp(root_->left(), k,if_find);
		else if (k > root_->key())return findhelp(root_->right(), k,if_find);
		else
		{
			if_find = true;
			return root_->element();
		}
	};

	void printhelp(BSTNode<Key, E> * rt)
	{
		cout << "preorder is \n";
		if (rt == nullptr)return;
		cout << rt->element() << " ";
		printhelp(rt -> left());
		printhelp(rt->right());
	};
	

	

};



#include<iostream>
using namespace std;
int main()
{
	int order, element, key;
	BST<int, int> tree;
	while (true)
	{
		cout << "enter order\n";
		cout << "1.insert an element(enter key and element)\n";
		cout << "2.see the tree\n";
		cout << "3.find a certain element\n";
		cout << "4.delete an element\n";
		cin >> order;
		switch (order)
		{
		case 1:
			cout << "enter the key and element:";
			cin >> key >> element;
			tree.insert(key, element);
			break;
		case 2:
			cout << "preorder:\n";
			tree.preorder();
			cout << "\ninorder:\n";
			tree.inorder();
			cout << "\npostorder:\n";
			tree.postprder();
			cout << endl;
			break;
		case 3:
			cout << "please enter the key to find the element\n";
			cin >> key;
			tree.find(key);
			break;
		case 4:
			cout << "enter the key of the element\n";
			cin >> key;
			tree.remove(key);
		}
	}		
}