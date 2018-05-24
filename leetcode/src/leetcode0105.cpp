// leetcode105.cpp
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
	TreeNode* buildTree( vector<int>& inorder, vector<int>& postorder )
	{
		return buildTree( begin(inorder), end(inorder), begin(postorder), end(postorder) );
	}

	TreeNode * buildTree(	vector<int>::iterator in_first, vector<int>::iterator in_last,
							vector<int>::iterator post_first, vector<int>::iterator post_last )
	{
		if ( in_first == in_last )
		{
			return nullptr;
		}
		if ( post_first == post_last )
		{
			return nullptr;
		}
		int val = *prev(post_last);
		TreeNode * root = new TreeNode(val);
		vector<int>::iterator in_root = find( in_first, in_last, val );
		int left_size = distance( in_first, in_root );
		vector<int>::iterator post_left_last = next( post_first, left_size );
		root->left = buildTree( in_first, in_root, post_first, post_left_last );
		root->right = buildTree( next(in_root), in_last, post_left_last, prev(post_last) );
		return root;
	}

// 	template<typename BidiIt>
// 	TreeNode * buildTree( BidiIt in_first, BidiIt in_last, BidiIt post_first, BidiIt post_last )
// 	{
// 		if ( in_first == in_last )
// 		{
// 			return nullptr;
// 		}
// 		if ( post_first == post_last )
// 		{
// 			return nullptr;
// 		}
// 		auto val = *prev(post_last);
// 		TreeNode * root = new TreeNode(val);
// 
// 		auto in_root_pos = find( in_first, in_last, val );
// 		auto left_size = distance( in_first, in_root_pos );
// 		auto post_left_last = next( post_first, left_size );
// 
// 		root->left = buildTree( in_first, in_root_pos, post_first, post_left_last );
// 		root->right = buildTree( next(in_root_pos), in_last, post_left_last, prev(post_last) );
// 
// 		return root;
// 	}
};

int main()
{
	vector<int> in;
	vector<int> post;
	in.push_back( 1 );
	in.push_back( 2 );
	post.push_back( 1 );
	post.push_back( 2 );

	Solution s;
	TreeNode * root = s.buildTree( in, post );
	return 0;
}

