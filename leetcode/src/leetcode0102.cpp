// leetcode102.cpp : 定义控制台应用程序的入口点。
//

#include <queue>
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
	vector<vector<int> > levelOrder(TreeNode *root)
	{
		TreeNode * pNode = NULL;
		queue<TreeNode*> traversalQueue;
		queue<TreeNode*> next;
		queue<TreeNode*> outputQueue;
		if ( root )
		{
			traversalQueue.push( root );
		}
		while ( !traversalQueue.empty() )
		{
			while( !traversalQueue.empty() )
			{
				pNode = traversalQueue.front();
				traversalQueue.pop();
				if ( pNode->left )
				{
					next.push( pNode->left );
				}
				if ( pNode->right )
				{
					next.push( pNode->right );
				}
				outputQueue.push( pNode );
			}
			swap( traversalQueue, next );
			outputQueue.push( NULL );
		}
		vector<int> item;
		vector<vector<int> > ret;
		int i = 1;
		while( ! outputQueue.empty() )
		{
			pNode = outputQueue.front();
			outputQueue.pop();
			if ( pNode )
			{
				item.push_back( pNode->val );
			}else{
				if ( i++ % 2 == 0 )
				{
					reverse( item.begin(), item.end() );
				}
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
	ret = s.levelOrder( root );

	return 0;
}
