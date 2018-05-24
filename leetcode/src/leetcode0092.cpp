// leetcode092.cpp
//

#include <stack>
#include <queue>
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
	ListNode *reverseBetween( ListNode *head, int m, int n )
	{
		int index = 0;
		ListNode * tmp = head;
		queue<ListNode*> q;
		stack<ListNode*> s;
		while ( tmp )
		{
			index++;
			if ( m <= index && index <= n )
			{
				s.push( tmp );
			}else{
				while ( !s.empty() )
				{
					q.push( s.top() );
					s.pop();
				}
				q.push( tmp );
			}
			tmp = tmp->next;
		}
		while ( !s.empty() )
		{
			q.push( s.top() );
			s.pop();
		}

		head = NULL;
		if ( !q.empty() )
		{
			head = q.front();
			q.pop();
			tmp = head;
		}

		while ( !q.empty() )
		{
			tmp->next = q.front();
			q.pop();
			tmp = tmp->next;
		}
		tmp->next = NULL;
		
		return head;
	}
};

int main()
{
	ListNode * tmp = new ListNode(1);
	tmp->next = new ListNode(2);
// 	tmp->next->next = new ListNode(3);
// 	tmp->next->next->next = new ListNode(4);
// 	tmp->next->next->next->next = new ListNode(5);
// 	tmp->next->next->next->next->next = new ListNode(6);
// 	tmp->next->next->next->next->next->next = new ListNode(7);

	Solution s;
	ListNode * nodeRet = s.reverseBetween( tmp, 1, 2 );

	return 0;
}

