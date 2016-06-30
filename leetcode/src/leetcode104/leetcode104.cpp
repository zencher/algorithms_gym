// leetcode104.cpp : 定义控制台应用程序的入口点。
//

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
	int maxDepth(TreeNode *root)
	{
		if ( root )
		{
			return hanlde( root, 1, INT_MIN );
		}
		return 0;	
	}

private:
	int hanlde( TreeNode * node, int level, int maxLevel )
	{
		if ( !node->left && !node->right )
		{
			return max( level, maxLevel );
		}
		if ( node->left )
		{
			maxLevel = hanlde( node->left, level+1, maxLevel );
		}
		if ( node->right )
		{
			maxLevel = hanlde( node->right, level+1, maxLevel );
		}
		return maxLevel;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

