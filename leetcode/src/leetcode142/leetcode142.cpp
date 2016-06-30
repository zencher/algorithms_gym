// leetcode142.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <set>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head)
	{
		ListNode * pTmp = head;
		set<ListNode*> aSet;
		while ( pTmp )
		{
			if ( aSet.count( pTmp ) != 0 )
			{
				return pTmp;
			}
			aSet.insert( pTmp );
			pTmp = pTmp->next;
		}
		return NULL;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}