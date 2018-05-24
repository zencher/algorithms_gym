// leetcode142.cpp
//

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

int main()
{
	return 0;
}
