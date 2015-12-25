// leetcode023.cpp : 定义控制台应用程序的入口点。
//
// Merge k Sorted Lists
// 	Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

#include <vector>
#include <algorithm>
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
	ListNode * mergeKLists( vector<ListNode *> &lists )
	{
		if ( lists.size() == 0 ) return nullptr;
		if ( lists.size() > 100 )
		{
			vector<int> vec;
			for ( size_t i = 0; i < lists.size(); ++i )
			{
				ListNode * pNode = lists[i];
				while( pNode )
				{
					vec.push_back( pNode->val );
					pNode = pNode->next;
				}
			}

			sort( vec.begin(), vec.end() );

			ListNode * pHead = new ListNode( vec[0] );
			ListNode * pTmp = pHead;
			for ( size_t i = 1; i < vec.size(); ++i )
			{
				pTmp->next = new ListNode( vec[i] );
				pTmp = pTmp->next;
			}

			return pHead;
		}
        return nullptr;
	}
};

int main()
{
	Solution s;

	vector<ListNode*> l;
	l.push_back( new ListNode(1) );

	ListNode * pRet = s.mergeKLists( l );


	return 0;
}