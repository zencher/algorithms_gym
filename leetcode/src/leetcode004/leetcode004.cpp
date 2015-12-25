// leetcode004.cpp : 定义控制台应用程序的入口点。
//
// Add Two Numbers
//
// 	You are given two linked lists representing two non-negative numbers.
//	The digits are stored in reverse order and each of their nodes contain a single digit.
//	Add the two numbers and return it as a linked list.
// 
// 	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// 	Output: 7 -> 0 -> 8

#include "stdafx.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution
{
public:
	ListNode * addTwoNumbers( ListNode *l1, ListNode *l2 )
	{
		int carry = 0;
		ListNode dummy(-1);
		ListNode * prev = &dummy;
		for (	ListNode * tmp1 = l1, * tmp2 = l2;
			tmp1 != nullptr || tmp2 != nullptr;
			tmp1 = tmp1 ? tmp1->next : nullptr,
			tmp2 = tmp2 ? tmp2->next : nullptr,
			prev = prev->next )
		{
			int v1 = tmp1 ? tmp1->val : 0;
			int v2 = tmp2 ? tmp2->val : 0;
			int v = ( v1 + v2 + carry ) % 10;
			carry = ( v1 + v2 + carry ) / 10;
			prev->next = new ListNode(v);
		}
		if ( carry > 0 )
		{
			prev->next = new ListNode(carry);
		}
		return dummy.next;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;

//test case 1
	ListNode * t1l1 = new ListNode(1);
	ListNode * t1l2 = new ListNode(9);
	ListNode * v1 = s.addTwoNumbers( t1l1, t1l2 );

//test case 2
	ListNode * v2 = s.addTwoNumbers( NULL, NULL );

//test case 3
	ListNode * t3l1 = new ListNode( 1 );
	t3l1->next = new ListNode(2);
	t3l1->next->next = new ListNode(3);
	ListNode * t3l2 = new ListNode(9);
	ListNode * v3 = s.addTwoNumbers( t3l1, t3l2 );

//test case 4
	ListNode * t4l1 = new ListNode(9);
	ListNode * t4l2 = new ListNode( 1 );
	t4l2->next = new ListNode(2);
	t4l2->next->next = new ListNode(3);
	ListNode * v4 = s.addTwoNumbers( t4l1, t4l2 );

//test case 5
	ListNode * t5l1 = new ListNode( 1 );
	ListNode * t5l2 = new ListNode( 1 );
	t5l1->next = new ListNode( 8 );
	t5l1->next->next = new ListNode( 3 );
	t5l2->next = new ListNode( 8 );
	t5l2->next->next = new ListNode( 3 );
	ListNode * v5 = s.addTwoNumbers( t5l1, t5l2 );

	return 0;
}

