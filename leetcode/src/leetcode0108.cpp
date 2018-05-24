// leetcode108.cpp
//

#include <queue>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
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
	TreeNode * sortedListToBST( ListNode *head )
	{
		if ( !head )
		{
			return NULL;
		}

		ListNode * pTmp = head;
		int count = 0;
		while ( pTmp )
		{
			pTmp = pTmp->next;
			count++;
		}

		return generate( head, count );
	}

private:
	TreeNode * generate( ListNode * pNode, int count )
	{
		if ( count == 0 )
		{
			return NULL;
		}
		if ( count == 1 )
		{
			return new TreeNode( pNode->val );
		}
		TreeNode * node = new TreeNode( 0 );
		node->left = generate( pNode, count/2 );
		pNode = moveNode( pNode, count/2 );
		node->val = pNode->val;
		pNode = moveNode( pNode, 1 );
		node->right = generate( pNode, count - count/2 - 1 );
		return node;
	}

	ListNode * moveNode( ListNode * pNode, int count )
	{
		int i = count;
		while( i > 0 )
		{
			pNode = pNode->next;
			--i;
		}
		return pNode;
	}
};

int main()
{
// 	ListNode * head = new ListNode(1);
// 	head->next = new ListNode(2);
// 	head->next->next = new ListNode(3);
// 	head->next->next->next = new ListNode(4);
// 	head->next->next->next->next = new ListNode(5);
// 
// 	Solution s;
// 	TreeNode * pTree = s.sortedListToBST( head );

	ListNode * head = new ListNode(1);
	head->next = new ListNode(3);

	Solution s;
	TreeNode * pTree = s.sortedListToBST( head );

	return 0;
}

