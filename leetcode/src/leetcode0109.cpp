// leetcode109.cpp
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
	TreeNode * sortedArrayToBST( vector<int> &num )
	{
		return generate( num, 0, num.size() );
	}

private:
	TreeNode * generate( vector<int> & num, int index, int count )
	{
		if ( count == 0 )
		{
			return NULL;
		}
		if ( count == 1 )
		{
			return new TreeNode( num[index] );
		}
		TreeNode * node = new TreeNode(0);
		node->left = generate( num, index, count/2 );
		node->val = num[index+count/2];
		node->right = generate( num, index+count/2+1, count-count/2-1);
		return node;
	}
};

int main()
{
	vector<int> num;
	num.push_back( 1 );
	num.push_back( 2 );
	num.push_back( 3 );

	Solution s;
	TreeNode * pTree = s.sortedArrayToBST( num );
	return 0;
}

