// leetcode107.cpp
//

#include <queue>
#include <stack>
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
	vector<vector<int> > levelOrderBottom(TreeNode *root)
	{
		TreeNode * pNode = NULL;
		queue<TreeNode*> traversalQueue;
		queue<TreeNode*> next;
		stack<TreeNode*> outputQueue;
		if ( root )
		{
			traversalQueue.push( root );
		}
		while ( !traversalQueue.empty() )
		{
			outputQueue.push( NULL );
			while( !traversalQueue.empty() )
			{
				pNode = traversalQueue.front();
				traversalQueue.pop();
				if ( pNode->right )
				{
					next.push( pNode->right );
				}
				if ( pNode->left )
				{
					next.push( pNode->left );
				}
				outputQueue.push( pNode );
			}
			swap( traversalQueue, next ); 
		}
		vector<int> item;
		vector<vector<int> > ret;
		while( ! outputQueue.empty() )
		{
			pNode = outputQueue.top();
			outputQueue.pop();
			if ( pNode )
			{
				item.push_back( pNode->val );
			}else{
				ret.push_back( item );
				item.clear();
			}
		}
		return ret;
	}
};

int main()
{
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
 	root->right = new TreeNode(3);
// 	root->left->right = new TreeNode(4);
// 	root->right = new TreeNode(5);

	vector<vector<int> > ret;
	Solution s;
	ret = s.levelOrderBottom( root );

	return 0;
}

