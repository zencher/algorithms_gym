//
//  main.cpp
//  leetcode206
//
//  Created by zencher on 16/5/19.
//  Copyright © 2016年 zencher. All rights reserved.
//
//  Reverse a singly linked list.

#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 


class Solution01
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        
        stack<ListNode*> stk;
        ListNode * pHead = head, * tmpNode = NULL;
        while(pHead)
        {
            stk.push(pHead);
            pHead = pHead->next;
        }
        if(!stk.empty())
        {
            pHead = stk.top(); stk.pop();
            pHead->next = NULL;
            tmpNode = pHead;
        }
        
        while(!stk.empty())
        {
            tmpNode->next = stk.top(); stk.pop();
            tmpNode = tmpNode->next;
            tmpNode->next = NULL;
        }
        return pHead;
    }
};



class Solution02
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        
        ListNode * pNode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return pNode;
    }
};

int main(int argc, const char * argv[])
{
    ListNode * pHead = new ListNode(0);
    pHead->next = new ListNode(1);
    pHead->next->next = new ListNode(2);
    pHead->next->next->next = new ListNode(3);
    pHead->next->next->next->next = new ListNode(4);
    
    Solution01 s1;
    Solution02 s2;
    
    ListNode * pReverseHead01 = s1.reverseList(pHead);
    ListNode * pReverseHead02 = s2.reverseList(pReverseHead01);
    
    
    return 0;
}
