// leetcode096.cpp : 定义控制台应用程序的入口点。
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
	vector<int> inorderTraversal( TreeNode *root )
	{
		vector<int> ret;
		dfs( root, ret );
		return ret;
	}
private:
	void dfs( TreeNode * node, vector<int> & ret )
	{
		if ( !node )
		{
			return;
		}
		dfs( node->left, ret );
		ret.push_back( node->val );
		dfs( node->right, ret );
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

