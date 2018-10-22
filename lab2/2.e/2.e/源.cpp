#include<iostream>
using namespace std;


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
	int solve(TreeNode* node, int & res)
	{
		if (node == nullptr) return 0;

		//max_ 取的是 0 left_ right_三者之间的最大值
		int left_ = solve(node->left, res);
		int right_ = solve(node->right, res);
		if (left_ < 0)left_ = 0;
		if (right_ < 0)right_ = 0;
		int max_ = left_ > right_ ? left_ : right_;//get the max of left_ right_ 0 
		//max加上当前的节点的值
		max_ += node->val;
		if (res < (left_ + right_ + node->val))res = left_ + right_ + node->val;	
		return max_;
	}
};

int main()
{
	TreeNode * root = new TreeNode(4);
	TreeNode * temp = new TreeNode(11);
	root->left = temp;
	temp = new TreeNode(7);
	root->left->left = temp;
	temp = new TreeNode(2);
	root->left->right = temp;
	temp = new TreeNode(13);
	root->right = temp;
	Solution s;
	cout << "max is " << s.maxPathSum(root) << endl;
	system("pause");
	return 0;
}