// leetcode129.cpp
//

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumNumbers( TreeNode *root )
	{
		return dfs( root, 0 );
	}

	int dfs( TreeNode * node, int sum )
	{
		if ( node == NULL )
		{
			return 0;
		}
		if ( node->left == NULL && node->right == NULL )
		{
			return sum * 10 + node->val;
		}
		return dfs( node->left, sum * 10 + node->val ) + dfs( node->right, sum * 10 + node->val );
	}
};

int main()
{
	return 0;
}
