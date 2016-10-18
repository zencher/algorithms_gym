// leetcode061.cpp : 定义控制台应用程序的入口点。
//
// Rotate List
// 	Given a list, rotate the list to the right by k places, where k is non-negative.
// 	For example:
// 	Given 1->2->3->4->5->NULL and k = 2,
// 	return 4->5->1->2->3->NULL.


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *rotateRight(ListNode *head, int k)
	{
		if ( head == nullptr || k == 0 )
		{
			return head;
		}

		ListNode * pTmp = head, * pRet = NULL;
		int len = 1;
		while ( pTmp->next )
		{
			len++;
			pTmp = pTmp->next;
		}
		k = len - k % len;

		pTmp->next = head;
		for ( int i = 0; i < k; ++i )
		{
			pTmp = pTmp->next;
		}
		head = pTmp->next;
		pTmp->next = nullptr;
		return head;
	}
};

int main()
{
	ListNode * pNode = new ListNode(1);
	pNode->next = new ListNode(2);
	pNode->next->next = new ListNode(3);
	pNode->next->next->next = new ListNode(4);
	pNode->next->next->next->next = new ListNode(5);

	Solution s;

	ListNode * pNew = s.rotateRight( pNode, 1 );

	return 0;
}

