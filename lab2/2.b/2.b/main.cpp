#define DEBUG
#include<iostream>
using namespace std;
template<typename T>
class binNode
{
public:
	binNode()//root
	{
		Element = -1;
	};
	binNode(T e)
	{
		Element = e;
	};
	~binNode() {};
	void visit()const
	{
		if (this == nullptr) return;
		cout << element() << " ";
	};
	void preorder(binNode<T> * r)
	{
		if (r == nullptr)return;
		r->visit();
		preorder(r->left());
		preorder(r->right());
	}
	void postorder(binNode <T> * r)
	{
		postorder(r->left());
		postprder(r->right());
		visit(r);
	};
	binNode * left()
	{
		return lc;
	};
	binNode * right()
	{
		return rc;
	};
	binNode * setLeft(const T & t)
	{
		lc = new binNode(t);
		return lc;
	}
	binNode * setLeft( binNode<T> * ll)
	{
		lc = ll;
		return lc;
	}
	binNode * setRight(const T & t)
	{
		rc = new binNode(t);
		return rc;
	}
	binNode * setRight( binNode<T> * rr)
	{
		rc = rr;
		return rc;
	}
	T element()const
	{
		return Element;
	}

//private:

	binNode * lc, *rc;
	T Element;
};
template<typename T>
class binTree
{
public:
	void buildTree(T * pre, T * in, int len)
	{
		root = buildhelp(root ,pre, in, len, 0, 0, len);
	};
	void preorder()const
	{
		root->preorder(root);
	}
private:
	binNode<T> * root;

	int findPosition(T * seq,int start,int end,const T & targe)
	{
		for (int i = start; i < end; i++)
		{
			if (targe == seq[i])
				return i;
		}
		return -1;
	};
	binNode<T> * buildhelp(binNode<T> * r,T * pre, T * in, int len, int pos, int left, int right)//pos is the position of preorder sequence
	{
		if (right - left <= 1)
		{
			if (right - left == 1)
			{
				r = new binNode<T>(in[left]);
				return r;
			}
			else return nullptr;
		}
		int p = findPosition(in, left, right, pre[pos]);
		while (p == -1 && p < len && pos < len - 1)
		{
			p = findPosition(in, left, right,pre[++pos]);
		}
#ifdef DEBUG
		cout << "p is:" << p << endl;
#endif
		//pos is the position of pre
		//p is the position of in
		r = new binNode<T> (in[p]);
		r->setLeft(buildhelp(r->lc,pre,in,len,pos + 1,left,p));
		r->setRight(buildhelp(r->rc,pre,in,len,pos + 1,p + 1,right));
		return r;
	};
};



int main()
{
	int size = 10;
	int pre[] = { 1, 2, 4, 5, 8, 9, 3, 6, 7, 10 };
	int in[] = { 4, 2, 8, 5, 9, 1, 6, 3, 7, 10 };
	binTree<int> tree;
	tree.buildTree(pre, in, size);
	tree.preorder();
	system("pause");
	return 0;
}


