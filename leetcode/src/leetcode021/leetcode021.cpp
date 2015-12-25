// leetcode021.cpp : 定义控制台应用程序的入口点。
//
// Merge Two Sorted Lists
// 	Merge two sorted linked lists and return it as a new list.
// 	The new list should be made by splicing together the nodes of the first two lists.

#include "stdafx.h"
#include <vector>
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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
	{
		ListNode head(-1);
		for (ListNode* p = &head; l1 != nullptr || l2 != nullptr; p = p->next)
		{
			int val1 = l1 == nullptr ? INT_MAX : l1->val;
			int val2 = l2 == nullptr ? INT_MAX : l2->val;
			if (val1 <= val2)
			{
				p->next = l1;
				l1 = l1->next;
			} else {
				p->next = l2;
				l2 = l2->next;
			}
		}
		return head.next;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

