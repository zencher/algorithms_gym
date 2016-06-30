// leetcode144.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <stack>

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
	vector<int> preorderTraversal(TreeNode *root)
	{
		vector<int> ret;
		stack<TreeNode*> s;
		TreeNode * cur = NULL;
		if ( root )
		{
			s.push( root );
		}

		while ( !s.empty() )
		{
			cur = s.top();
			s.pop();
			ret.push_back( cur->val );
			if ( cur->right )
			{
				s.push( cur->right );
			}
			if ( cur->left )
			{
				s.push( cur->left );
			}
		}

		return ret;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}