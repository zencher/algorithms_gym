// leetcode143.cpp : 定义控制台应用程序的入口点。
//

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
	void reorderList( ListNode *head )
	{
		if ( !head || !head->next )
		{
			return;
		}

		size_t count = 0;
		ListNode * pTmp = NULL;
		stack<ListNode*> s;
		for ( pTmp = head->next; pTmp != NULL ; pTmp = pTmp->next )
		{
			++count;
			s.push( pTmp );
		}

		pTmp = head;
		size_t i = 0, j = count/2 + count%2;
		while( i < j )
		{
			if ( ! s.empty() )
			{
				s.top()->next = pTmp->next;
				pTmp->next = s.top();
				pTmp = s.top();
				s.pop();
			}
			pTmp = pTmp->next;
			++i;
		}
		pTmp->next = NULL;
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);

	Solution s;
	s.reorderList( head );

	return 0;
}
