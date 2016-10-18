// leetcode024.cpp : 定义控制台应用程序的入口点。
//
// Swap Nodes in Pairs
//
// 	Given a linked list, swap every two adjacent nodes and return its head.
// 	For example,
// 	Given 1->2->3->4, you should return the list as 2->1->4->3.
// 	Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
	ListNode *swapPairs( ListNode *head )
	{
		if ( !head )
		{
			return nullptr;
		}

		ListNode * pHead = head;
		ListNode * pPrv = nullptr;
		ListNode * pN1 = head;
		ListNode * pN2 = head->next;
		if ( pN1 && pN2 )
		{
			pN1->next = pN2->next;
			pN2->next = pN1;
			pHead = pN2;
			pPrv = pN1;
		}

		while ( pN1->next && pN1->next->next )
		{
			pN2 = pN1->next->next;
			pN1 = pN1->next;

			pN1->next = pN2->next;
			pN2->next = pN1;
			pPrv->next = pN2;
			pPrv = pN1;
		}

		return pHead;
	}
};


int main()
{
	Solution s;

	ListNode * p1 = new ListNode(1);
	p1->next = new ListNode(2);
	p1->next->next = new ListNode(3);
	p1->next->next->next = new ListNode(4);

	ListNode * pTmp = s.swapPairs( p1 );

	ListNode * p2 = nullptr;
	pTmp = s.swapPairs( p2 );

	ListNode * p3 =  new ListNode(1);
	pTmp = s.swapPairs( p3 );

	ListNode * p4 = new ListNode(1);
	p4->next = new ListNode(2);
	pTmp = s.swapPairs( p4 );

	ListNode * p5 = new ListNode(1);
	p5->next = new ListNode(2);
	p5->next->next = new ListNode(3);
	pTmp = s.swapPairs( p5 );


	return 0;
}