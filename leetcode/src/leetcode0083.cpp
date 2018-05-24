// leetcode083.cpp
//
//	Remove Duplicates from Sorted List
// 	Given a sorted linked list, delete all duplicates such that each element appear only once.
// 	For example,
// 	Given 1->1->2, return 1->2.
// 	Given 1->1->2->3->3, return 1->2->3.

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution
{
public:
	ListNode *deleteDuplicates(ListNode *head)
	{
		if ( head == nullptr )
			 return nullptr;
		
		for ( ListNode * pre = head, * cur = head->next; cur; cur = cur->next )
		{
			if ( pre->val == cur->val )
			{
				pre->next = cur->next;
				delete cur;
				cur = pre;
			}else{
				pre = cur;
			}
		}
		return head;
	}
};

int main()
{
	ListNode * pHead = new ListNode(1);
	pHead->next = new ListNode(1);
	pHead->next->next = new ListNode(1);
	pHead->next->next->next = new ListNode(2);
	pHead->next->next->next->next = new ListNode(2);

	Solution s;
	pHead = s.deleteDuplicates( pHead );

	return 0;
}

