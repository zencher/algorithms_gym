// leetcode095.cpp : 定义控制台应用程序的入口点。
//
// Unique Binary Search Trees II 
// 	Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
// 
// 		For example,
// 		Given n = 3, your program should return all 5 unique BST's shown below.
// 
// 		1         3     3      2      1
// 		 \       /     /      / \      \
// 		  3     2     1      1   3      2
// 		 /     /       \                 \
// 		2     1         2                 3

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
	vector<TreeNode *> generateTrees( int n )
	{
		if ( n == 0 ) return generate(1, 0);
		return generate(1, n);
	}

private:
	vector<TreeNode *> generate( int start, int end )
	{
		vector<TreeNode*> subTree;
		if ( start > end )
		{
			subTree.push_back( nullptr );
			return subTree;
		}
		for (int k = start; k <= end; k++)
		{
			vector<TreeNode*> leftSubs = generate( start, k - 1 );
			vector<TreeNode*> rightSubs = generate( k + 1, end );
			vector<TreeNode*>::iterator itleft;
			vector<TreeNode*>::iterator itright;
			for ( itleft = leftSubs.begin(); itleft != leftSubs.end(); ++itleft )
			{
				for ( itright = rightSubs.begin(); itright != rightSubs.end(); ++itright )
				{
					TreeNode *node = new TreeNode(k);
					node->left = *itleft;
					node->right = *itright;
					subTree.push_back(node);
				}
			}
		}
		return subTree;
	}
};

int main()
{
	Solution s;

	vector<TreeNode*> arr;
	arr = s.generateTrees( 3 );

	return 0;
}

