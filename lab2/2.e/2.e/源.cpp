#include<iostream>
using namespace std;

//˼· �ȵݹ鵽Ҷ�ӽڵ� �ٻ���
class TreeNode
{
public:
	TreeNode(int ww)
	{
		val = ww;
	}
	TreeNode * left, *right;
	int val;
};
class Solution 
{
public:
	int maxPathSum(TreeNode * root)
	{
		int res = INT_MIN;
		solve(root, res);


		return res;
	}
	//Ҫ�õ��Ĵ���res
	//��Ϊ���
	int solve(TreeNode* node, int & res)// ���ص� �� �Ե�ǰ���Ϊ����㣬��Ҷ�ڵ�����·��֮��(Ҳ����˵ֻ��ȡ��һ�ߵ�ֵ)

	{
		if (node == nullptr) return 0;

		//max_ ȡ���� 0 left_ right_����֮������ֵ
		int left_ = solve(node->left, res);
		int right_ = solve(node->right, res);
		if (left_ < 0)left_ = 0;
		if (right_ < 0)right_ = 0;
		int max_ = left_ > right_ ? left_ : right_;//get the max of left_ right_ 0 
		//max���ϵ�ǰ�Ľڵ��ֵ
		max_ += node->val;
		if (res < (left_ + right_ + node->val))res = left_ + right_ + node->val;	
		return max_;
	}
};



#include<string>
using namespace std;
bool input()
{
	string s;
	cin >> s;
	bool start = false;
	for (int i = 1; i < s.length(); i++)
	{
		/*if (start == false)
		{
			while (s[i++] != '[' && i < s.length())continue;
			if (s[i] == '[')start = true;
			
		}*/
		
	}
	return 1;
}


int main()
{/*
	TreeNode * root = new TreeNode(4);
	TreeNode * temp = new TreeNode(11);
	root->left = temp;
	temp = new TreeNode(7);
	root->left->left = temp;
	temp = new TreeNode(2);
	root->left->right = temp;
	temp = new TreeNode(13);
	root->right = temp;*/
	TreeNode * root = new TreeNode(-10);
	TreeNode * temp = new TreeNode(9);
	root->left = temp;
	temp = new TreeNode(20);
	root->right = temp;
	root = root->right;
	temp = new TreeNode(15);
	root->left = temp;
	temp = new TreeNode(7);
	root->right = temp;
	Solution s;
	cout << "max is " << s.maxPathSum(root) << endl;
	system("pause");
	return 0;
}