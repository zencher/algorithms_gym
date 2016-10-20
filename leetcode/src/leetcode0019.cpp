// leetcode019.cpp : 定义控制台应用程序的入口点。
//

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
    ListNode *removeNthFromEnd( ListNode *head, int n )
	{
        vector<ListNode*> vec;
		ListNode * pTmp = head;
		while ( pTmp )
		{
			vec.push_back( pTmp );
			pTmp = pTmp->next;
		}

		int index = vec.size()-n;
		if ( index == 0 )
		{
			head = vec[index]->next;
			delete vec[index];
		}else if ( index > 0 && index < vec.size() )
		{
			vec[index-1]->next = vec[index]->next;
			delete vec[index];
		}
		return head;
    }
};


int main()
{
	Solution s;

	ListNode * head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	head = s.removeNthFromEnd( head, 1 );

	return 0;
}

