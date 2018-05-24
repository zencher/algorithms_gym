// leetcode112.cpp
//

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
	bool hasPathSum(TreeNode *root, int sum)
	{
		if ( !root )
		{
			return false;
		}
		return handle( root, root->val, sum );
	}

private:
	bool handle( TreeNode * node, int sum, int target )
	{
		if ( !node->left && !node->right )
		{
			if ( sum == target )
			{
				return true;
			}
			return false;
		}
		if ( node->left )
		{
			if ( handle( node->left, sum + node->left->val, target ) )
			{
				return true;
			}
		}
		if ( node->right )
		{
			if ( handle( node->right, sum + node->right->val, target ) )
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(5);
	root->right->right = new TreeNode(6);

	Solution s;
	s.hasPathSum( root, 6 );

	return 0;
}

