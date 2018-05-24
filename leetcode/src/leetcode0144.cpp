// leetcode144.cpp
//

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

int main()
{
	return 0;
}
