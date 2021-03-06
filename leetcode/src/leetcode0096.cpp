// leetcode096.cpp
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

int main()
{
	return 0;
}

