// leetcode146.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *insertionSortList( ListNode *head )
	{
		if ( !head )
		{
			return NULL;
		}

		ListNode * pLeft = head;
		ListNode * pRight = head->next;
		head->next = NULL;

		ListNode * pTmp1 = NULL, * pPreTmp1 = NULL, * pTmp2 = NULL;
		while ( pRight != NULL )
		{
			pTmp2 = pRight;
			pRight = pRight->next;
			for ( pPreTmp1 = NULL, pTmp1 = pLeft; pTmp1 != NULL;  pTmp1 = pTmp1->next )
			{
				if ( pTmp2->val < pTmp1->val )
				{
					if ( pPreTmp1 == NULL )
					{
						pLeft = pTmp2;
						pLeft->next = pTmp1;
					}else{
						pPreTmp1->next = pTmp2;
						pTmp2->next = pTmp1;
					}
					break;
				}else if ( pTmp1->next == NULL )
				{
					pTmp1->next = pTmp2;
					pTmp2->next = NULL;
					break;
				}
				pPreTmp1 = pTmp1;
			}	
		}

		return pLeft;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	ListNode * pHead = new ListNode(4);
	pHead->next = new ListNode(19);
	pHead->next->next = new ListNode(14);
	pHead->next->next->next = new ListNode(5);
	pHead->next->next->next->next = new ListNode(-3);
	pHead->next->next->next->next->next = new ListNode(1);
	pHead->next->next->next->next->next->next = new ListNode(8);
	pHead->next->next->next->next->next->next->next = new ListNode(5);
	pHead->next->next->next->next->next->next->next->next = new ListNode(11);
	pHead->next->next->next->next->next->next->next->next->next = new ListNode(15);

	Solution s;
	pHead = s.insertionSortList( pHead );

	return 0;
}