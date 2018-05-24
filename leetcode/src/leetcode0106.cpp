// leetcode106.cpp : 定义控制台应用程序的入口点。
//

#include <vector>
#include <algorithm>

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
	TreeNode* buildTree( vector<int>& preorder, vector<int>& inorder )
	{
		return buildTree( begin(preorder), end(preorder), begin(inorder), end(inorder) );
	}

	TreeNode * buildTree(	vector<int>::iterator pre_first, vector<int>::iterator pre_last,
							vector<int>::iterator in_first, vector<int>::iterator in_last )
	{
		if ( in_first == in_last )
		{
			return nullptr;
		}
		if ( pre_first == pre_last )
		{
			return nullptr;
		}
		int val = *pre_first;
		TreeNode * root = new TreeNode( val );
		vector<int>::iterator in_root = find( in_first, in_last, val );
		int left_size = distance( in_first, in_root );
		root->left = buildTree( next(pre_first), pre_last, in_first, in_root );
		root->right = buildTree( next(pre_first,left_size+1), pre_last, next(in_root), in_last );
		return root;
	}

// 	template<typename BidiIt>
// 	TreeNode * buildTree( BidiIt pre_first, BidiIt pre_last, BidiIt in_first, BidiIt in_last )
// 	{
// 		if ( in_first == in_last )
// 		{
// 			return nullptr;
// 		}
// 		if ( pre_first == pre_last )
// 		{
// 			return nullptr;
// 		}
// 		auto val = *pre_first;
// 		TreeNode * root = new TreeNode(val);
// 
// 		auto in_root = find( in_first, in_last, val );
// 		auto left_size = distance( in_first, in_root );
// 
// 		root->left = buildTree( next(pre_first), pre_last, in_first, in_root );
// 		root->right = buildTree( next(pre_first,left_size+1), pre_last, next(in_root), in_last );
// 		return root;
// 	}
};

int main()
{
	vector<int> in;
	vector<int> pre;
	in.push_back( 1 );
	in.push_back( 2 );
	in.push_back( 3 );
	pre.push_back( 2 );
	pre.push_back( 1 );
	pre.push_back( 3 );

	Solution s;
	TreeNode * root = s.buildTree( pre, in );
	return 0;
}
