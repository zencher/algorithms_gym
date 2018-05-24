// leetcode113.cpp
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
	vector<vector<int> > pathSum(TreeNode *root, int sum)
	{
		vector<int> item;
		vector<vector<int> > ret;
		if ( root )
		{
			handle( root, root->val, sum, item, ret );
		}
		return ret;
	}

private:
	void handle( TreeNode * node, int sum, int target, vector<int> & result, vector<vector<int> > & ret )
	{
		result.push_back( node->val );
		if ( !node->left && !node->right )
		{
			if ( sum == target )
			{
				ret.push_back( result );
			}
		}
		if ( node->left )
		{
			handle( node->left, sum + node->left->val, target, result, ret );
		}
		if ( node->right )
		{
			handle( node->right, sum + node->right->val, target, result, ret );
		}
		result.pop_back();
	}
};

int main()
{
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(5);
	root->right->right = new TreeNode(1);

	vector<vector<int> > ret;
	Solution s;
	ret = s.pathSum( root, 7 );

	return 0;
}
