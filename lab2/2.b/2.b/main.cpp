#define DEBUG
#include<iostream>
using namespace std;
template<typename T>
class binNode//树的节点类
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
	//三种遍历方式
	void preorder(binNode<T> * r)
	{
		if (r == nullptr)return;
		r->visit();
		preorder(r->left());
		preorder(r->right());
	}
	void inorder(binNode<T> * r)
	{
		if (r == nullptr) return;
		inorder(r->left());
		r->visit();
		inorder(r->right());
	}
	void postorder(binNode <T> * r)
	{
		if (r == nullptr)return;
		postorder(r->left());
		postorder(r->right());
		r->visit();
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

//封装成 binTree类
template<typename T>
class binTree
{
public:
	void buildTree(T * pre, T * in, int len)//建树
	{
		root = buildhelp(root ,pre, in, len, 0, 0, len);
	};
	void preorder()const//前序遍历
	{
		root->preorder(root);
	}
	void postorder()const
	{
		root->postorder(root);
	}
	void inorder()const
	{
		root->inorder(root);
	}
private:
	binNode<T> * root;

	int findPosition(T * seq,int start,int end,const T & targe)//寻找targe在seq中的位置(seq的起始位置为 start 结束位置为end  [start,end))
	{
		for (int i = start; i < end; i++)
		{
			if (targe == seq[i])
				return i;
		}
		return -1;//没有找到则返回 -1
	};

	// r是当前树（也有可能是子树）的起始节点 pre是前序遍历的数组 in是中序遍历的数组 ,len是元素的个数 
	//pos是当前pre[]数组index的位置，left right表示的是中序遍历数组index的范围
	binNode<T> * buildhelp(binNode<T> * r,T * pre, T * in, int len, int pos, int left, int right)//pos is the position of preorder sequence
	{
		if (right - left <= 1)
		{
			if (right - left == 1)//如果只有一个元素 那就直接new进去就行了
			{
				r = new binNode<T>(in[left]);
				return r;
			}
			//如果没有元素 说明是空子树
			else return nullptr;
		}
		//p表示的是pre[pos] 这个元素 在in数组中的位置
		//以此为中界限 把in的数组划分为两个子数组 in[left->p) in[p + 1->right)
		//然后再递归的建树
		int p = findPosition(in, left, right, pre[pos]);
		while (p == -1 && p < len && pos < len - 1)
		{
			p = findPosition(in, left, right,pre[++pos]);
		}
		//used to debug
#ifdef DEBUG
		cout << "p is:" << p << endl;
#endif
		//pos is the position of pre
		//p is the position of in
		//注意 此时in[p](也就是pre[pos])就是当前节点的值 这里要new
		r = new binNode<T> (in[p]);

		//递归到左孩子 和右孩子
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
	cout << "preorder : ";
	tree.preorder();
	cout << endl;
	cout << "inorder : ";
	tree.inorder();
	cout << endl;
	cout << "postorder : ";
	tree.postorder();
	cout << endl;
	system("pause");
	return 0;
}


