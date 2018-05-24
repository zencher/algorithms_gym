// leetcode082.cpp
//
//	Remove Duplicates from Sorted List II
// 	Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
// 	For example,
// 	Given 1->2->3->3->4->4->5, return 1->2->5.
// 	Given 1->1->1->2->3, return 2->3.

#include <unordered_map>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *deleteDuplicates( ListNode *head )
	{
		if ( !head || !head->next )
			return head;
		
		ListNode *p = head->next;
		if ( head->val == p->val )
		{
			while ( p && head->val == p->val )
			{
				ListNode *tmp = p;
				p = p->next;
				delete tmp;
			}
			delete head;
			return deleteDuplicates( p );
		} else {
			head->next = deleteDuplicates( head->next );
			return head;
		}
	}
};

int main()
{
	ListNode * pHead = new ListNode(1);
	pHead->next = new ListNode(2);

	Solution s;
	ListNode * pNewHead = s.deleteDuplicates( pHead );

	return 0;
}

