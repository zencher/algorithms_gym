// leetcode114.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	void flatten( TreeNode *root )
	{
		if ( !root )
		{
			return;
		}
		handle( root );
	}
private:
	TreeNode * handle( TreeNode * node )
	{
		if ( !node->left && !node->right )
		{
			return node;
		}

		TreeNode * left = node->left;
		TreeNode * right = node->right;
		TreeNode * temp = node;
		node->left = NULL;
		if ( left )
		{
			node->right = left;
			temp = handle( left );
		}
		if ( right )
		{
			temp->right = right;
			temp = handle( right );
		}
		return temp;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(5);
	root->right->right = new TreeNode(6);

	Solution s;
	s.flatten( root );

	return 0;
}