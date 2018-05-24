// leetcode101.cpp : 定义控制台应用程序的入口点。
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
	bool isSymmetric( TreeNode *root )
	{
		return root ? isSymmetric( root->left, root->right ) : true;
	}

private:
	bool isSymmetric( TreeNode * left, TreeNode * right )
	{
		if ( !left && !right )
		{
			return true;
		}
		if ( !left || !right )
		{
			return false;
		}
		return left->val == right->val && isSymmetric( left->left, right->right ) && isSymmetric( left->right, right->left );
	}
};

int main()
{
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);

	Solution s;
	s.isSymmetric( root );

	return 0;
}

