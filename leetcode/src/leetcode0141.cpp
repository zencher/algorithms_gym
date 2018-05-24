// leetcode141.cpp
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
	bool hasCycle(ListNode *head)
	{
		bool bRet = false;
		set<ListNode*> aSet;
		ListNode * pTmp = head;
		while ( pTmp )
		{
			if ( aSet.count( pTmp ) != 0 )
			{
				bRet = true;
				break;
			}
			aSet.insert( pTmp );
			pTmp = pTmp->next;
		}
		return bRet;
	}
};

int main()
{
	return 0;
}
