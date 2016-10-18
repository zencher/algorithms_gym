// leetcode100.cpp : 定义控制台应用程序的入口点。
//

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
	bool isSameTree( TreeNode *p, TreeNode *q )
	{
		// 		if ( !p && !q )
		// 		{
		// 			return true;
		// 		}
		// 		if ( !p || !q )
		// 		{
		// 			return false;
		// 		}
		// 		return p->val == q->val && isSameTree( p->left, q->left ) && isSameTree( p->right, q->right );

		stack<TreeNode*> s;
		s.push(p);
		s.push(q);
		while ( !s.empty() )
		{
			p = s.top(); s.pop();
			q = s.top(); s.pop();
			if ( !p && !q )
			{
				continue;
			}
			if ( !p || !q )
			{
				return false;
			}
			if ( p->val != q->val )
			{
				return false;
			}
			s.push( p->left );
			s.push( q->left );
			s.push( p->right );
			s.push( q->right );
		}
		return true;
	}
};

int main()
{
	TreeNode * root1 = new TreeNode(1);
	root1->left = new TreeNode(2);
	root1->right = new TreeNode(3);

	TreeNode * root2 = new TreeNode(1);
	root2->left = new TreeNode(2);
	root2->right = new TreeNode(3);

	Solution s;
	s.isSameTree( root1, root2 );

	return 0;
}
