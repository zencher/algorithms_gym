// leetcode111.cpp : 定义控制台应用程序的入口点。
//

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
	int minDepth( TreeNode *root )
	{
		if ( root )
		{
			return hanlde( root, 1, INT_MAX );
		}
		return 0;	
	}

private:
	int hanlde( TreeNode * node, int level, int minLevel )
	{
		if ( !node->left && !node->right )
		{
			return min( level, minLevel );
		}
		if ( node->left )
		{
			minLevel = hanlde( node->left, level+1, minLevel );
		}
		if ( node->right )
		{
			minLevel = hanlde( node->right, level+1, minLevel );
		}
		return minLevel;
	}
};

int main()
{
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	// 	root->left->left = new TreeNode(3);
	// 	root->left->right = new TreeNode(4);
	// 	root->right = new TreeNode(5);

	Solution s;
	s.minDepth( root );

	return 0;
}
