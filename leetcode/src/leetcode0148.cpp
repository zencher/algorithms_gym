// leetcode148.cpp
//

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *sortList(ListNode *head)
	{
		return MergeSort( head );
	}

	ListNode* getMiddle(ListNode * head)
	{
		ListNode *mid, *midl, *p;
		midl = NULL, p = mid = head;

		while (p != NULL && p->next != NULL)
		{
			p = p->next->next;
			midl = mid;
			mid = mid->next;
		}

		midl->next = NULL;
		return mid;
	}

	ListNode * Merge(ListNode * La, ListNode * Lb)
	{
		ListNode * pa = La, *pb = Lb;
		ListNode * Lc = NULL;
		ListNode * q = NULL;
		if (pa->val <= pb->val)
		{
			Lc = q = pa;
			pa = pa->next;
		}
		else {
			Lc = q = pb;
			pb = pb->next;
		}
		while (pa != NULL && pb != NULL)
		{
			if (pa->val <= pb->val)
			{
				q->next = pa, pa = pa->next, q = q->next;
			}else{
				q->next = pb, pb = pb->next, q = q->next;
			}
		}
		if (pa == NULL)
		{
			q->next = pb;
		}else if (pb == NULL)
		{
			q->next = pa;
		}

		return Lc;
	}

	ListNode * MergeSort( ListNode * head )
	{
		if ( head == NULL || head->next == NULL )
		{
			return head;
		}

		ListNode * La, * Lb;
		Lb = getMiddle( head );
		La = head;
		La = MergeSort( La );
		Lb = MergeSort( Lb );
		return Merge( La, Lb );
	}
};

int main()
{
	ListNode * pNew = new ListNode(2);
	pNew->next = new ListNode(1);

	Solution s;
	pNew = s.sortList( pNew );

	return 0;
}
