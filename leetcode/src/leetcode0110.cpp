// leetcode110.cpp : 定义控制台应用程序的入口点。
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
	bool isBalanced( TreeNode *root )
	{
		int height = 0;
		bool bFlag = true;
		if ( root )
		{
			height = handle( root, 1, bFlag );
		}
		return bFlag;
	}

private:
	int handle( TreeNode * note, int height, bool & bRet )
	{
		if ( !note->right && !note->left )
		{
			return height;
		}
		int lh = height;
		int rh = height;
		if ( note->left )
		{
			lh = handle( note->left, height+1, bRet );
		}
		if ( note->right )
		{
			rh = handle( note->right, height+1, bRet );
		}
		if ( abs(lh - rh) > 1 )
		{
			bRet = false;
		}
		return max(lh, rh);
	}
};


int main()
{
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	
	Solution s;
	s.isBalanced( root );

	return 0;
}

