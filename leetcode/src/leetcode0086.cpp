// leetcode086.cpp
//
// Partition List
//     Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//     You should preserve the original relative order of the nodes in each of the two partitions.
//     For example,
//     Given 1->4->3->2->5->2 and x = 3,
//     return 1->2->2->4->3->5.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode left(0);
        ListNode right(0);
        ListNode * left_cur = &left;
        ListNode * right_cur = &right;
        ListNode * cur = head;
        while (cur)
        {
            if (cur->val>=x)
            {
                right_cur->next = cur;
                right_cur = right_cur->next;
            }else{
                left_cur->next = cur;
                left_cur = left_cur->next;
            }
            cur = cur->next;
        }
        left_cur->next = right.next;
        right_cur->next = nullptr;
        return left.next;
    }
};

int main()
{
    //     ListNode * pNote = new ListNode(1);
    //     pNote->next = new ListNode(4);
    //     pNote->next->next = new ListNode(3);
    //     pNote->next->next->next = new ListNode(2);
    //     pNote->next->next->next->next = new ListNode(5);
    //     pNote->next->next->next->next->next = new ListNode(2);
    
    ListNode * pNote = new ListNode(2);
    pNote->next = new ListNode(1);
    
    Solution s;
    ListNode * pNew = s.partition( pNote, 2 );
    
    return 0;
}

