// leetcode124.cpp : 定义控制台应用程序的入口点。
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
	int maxPathSum( TreeNode *root )
	{
		max_sum = INT_MIN;
		dfs( root );
		return max_sum;
	}

private:
	int max_sum;
	int dfs( TreeNode * item )
	{
		if ( item == NULL )
		{
			return 0;
		}
		int l = dfs( item->left );
		int r = dfs( item->right );
		int sum = item->val;
		if ( l > 0 )
		{
			sum += l;
		}
		if ( r > 0 )
		{
			sum += r;
		}
		max_sum = max( max_sum, sum );
		return max( item->val, item->val + max( l, r ) );
	}
};

int main()
{
	TreeNode * pRoot = new TreeNode(-3);
	pRoot->left = new TreeNode(2);
	pRoot->right = new TreeNode(3);
	pRoot->left->left = new TreeNode(0);
	pRoot->left->right = new TreeNode(0);
	pRoot->right->left = new TreeNode(6);
	pRoot->right->right = new TreeNode(7);

	Solution s;
	int L = s.maxPathSum( pRoot );

	return 0;
}
