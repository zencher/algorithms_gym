// leetcode160.cpp : 定义控制台应用程序的入口点。
//

// Intersection of Two Linked Lists
// Write a program to find the node at which the intersection of two singly linked lists begins.
// 
// 
// For example, the following two linked lists:
// 
// A:		a1 → a2
//					↘
// 					 c1 → c2 → c3
// 					↗            
// B:	b1 → b2 → b3
//		begin to intersect at node c1.
// 
// 
// Notes:
// 
// 		If the two linked lists have no intersection at all, return null.
// 		The linked lists must retain their original structure after the function returns.
// 		You may assume there are no cycles anywhere in the entire linked structure.
// 		Your code should preferably run in O(n) time and use only O(1) memory.


#include "stdafx.h"
#include <map>
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		stack<ListNode*> sA, sB;
		ListNode * pRet = NULL;
		ListNode * pTmp = headA;
		while( pTmp )
		{
			sA.push( pTmp );
			pTmp = pTmp->next;
		}

		pTmp = headB;
		while( pTmp )
		{
			sB.push( pTmp );
			pTmp = pTmp->next;
		}

		while( !sA.empty() && !sB.empty() )
		{
			ListNode * p1 = sA.top();
			ListNode * p2 = sB.top();
			sA.pop();
			sB.pop();
			if ( p1 == p2 )
			{
				pRet = p1;
			}else{
				break;
			}
		}
		return pRet;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

