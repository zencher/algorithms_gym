// leetcode025.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>
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
	ListNode *reverseKGroup(ListNode *head, int k)
	{
		if ( !head || k <= 1 )
		{
			return head;
		}

		stack<ListNode*> st;
		ListNode * pHead = head;
		ListNode * pTmp = head;
		ListNode * pNext = NULL;
		ListNode * pPrv = NULL;
		int i = 0;
		while ( pTmp )
		{
			st.push( pTmp );
			i++;
			pTmp = pTmp->next;

			if ( i == k )
			{
				pNext = pTmp;
				i = 0;
				if ( !pPrv )
				{
					pHead = st.top();
				}else{
					pPrv->next = st.top();
				}
				pPrv = st.top();
				st.pop();
				while ( !st.empty() )
				{
					pPrv->next = st.top();
					st.pop();
					pPrv = pPrv->next;
				}
				pPrv->next = pNext;
			}
		}

		return pHead;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;

	ListNode * p1 = new ListNode(1);
	p1->next = new ListNode(2);
	p1->next->next = new ListNode(3);
	p1->next->next->next = new ListNode(4);
	p1->next->next->next->next = new ListNode(5);

	ListNode * pTmp = s.reverseKGroup( p1, 2 );


	return 0;
}