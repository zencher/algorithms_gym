// leetcode099.cpp : 定义控制台应用程序的入口点。
//
// Recover Binary Search Tree:
//	Two elements of a binary search tree (BST) are swapped by mistake.
//	Recover the tree without changing its structure.
//	Note:
//	A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

#include "stdafx.h"
#include <vector>
using namespace std;

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
	void recoverTree(TreeNode *root)
	{
		vector<TreeNode*> arr;
		InorderTraversal( root, arr );

		int i = 0;
		for ( ; i < arr.size()-1; ++i )
		{
			if ( arr[i]->val > arr[i+1]->val )
			{
				break;
			}
		}
		int j = arr.size()-1;
		for ( ; j > 0; --j )
		{
			if ( arr[j]->val < arr[j-1]->val )
			{
				break;
			}
		}
		if ( i >= 0 && j >= 0 )
		{
			int tmp = arr[i]->val;
			arr[i]->val = arr[j]->val;
			arr[j]->val = tmp;
		}
	}

private:
	void InorderTraversal( TreeNode * root, vector<TreeNode *> & arr )
	{
		if ( !root )
		{
			return;
		}
		InorderTraversal( root->left, arr );
		arr.push_back( root );
		InorderTraversal( root->right, arr );
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode * root1 = new TreeNode(2);
	root1->left = new TreeNode(3);
	root1->right = new TreeNode(1);

	Solution s;
	s.recoverTree( root1 );

	return 0;
}