// leetcode098.cpp
//
// Validate Binary Search Tree
//	Given a binary tree, determine if it is a valid binary search tree (BST).
//	Assume a BST is defined as follows:
//	The left subtree of a node contains only nodes with keys less than the node's key.
// 	The right subtree of a node contains only nodes with keys greater than the node's key.
// 	Both the left and right subtrees must also be binary search trees.

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
	bool isValidBST(TreeNode *root)
	{
		if ( !root )
		{
			return true;
		}
		vector<int> arr;
		dfs( root, arr );
		for ( int i = 0; i < arr.size()-1; ++i )
		{
			if ( arr[i] >= arr[i+1] )
			{
				return false;
			}
		}
		return true;
	}

private:
	void dfs( TreeNode * node, vector<int> & arr )
	{
		if ( !node )
		{
			return;
		}
		dfs( node->left, arr );
		arr.push_back( node->val );
		dfs( node->right, arr );
	}
};

int main()
{
	TreeNode * root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(15);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(20);
	//root->left->left = new TreeNode(1);
	Solution s;
	s.isValidBST( root );

	return 0;
}

