// leetcode117.cpp : 定义控制台应用程序的入口点。
//

#include <queue>
using namespace std;

struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
	void connect(TreeLinkNode *root)
	{
		if ( root == nullptr )
		{
			return;
		}

		queue<TreeLinkNode*> current;
		queue<TreeLinkNode*> next;
		current.push( root );

		while( !current.empty() )
		{
			TreeLinkNode * pPrvItem = NULL;
			TreeLinkNode * pTemp = NULL;
			while( !current.empty() )
			{
				pTemp = current.front();
				current.pop();

				if ( pPrvItem )
				{
					pPrvItem->next = pTemp;
				}
				pPrvItem = pTemp;
				if ( pTemp->left )
				{
					next.push( pTemp->left );
				}
				if ( pTemp->right )
				{
					next.push( pTemp->right );
				}
			}
			swap( current, next );
		}
	}
};


int main()
{
	TreeLinkNode *root = new TreeLinkNode(0);
	root->left = new TreeLinkNode(1);
	root->right = new TreeLinkNode(2);

	root->left->left = new TreeLinkNode(3);
	root->left->right = new TreeLinkNode(4);

	root->right->left = new TreeLinkNode(5);
	root->right->right = new TreeLinkNode(6);

	Solution s;
	s.connect( root );

	return 0;
}
