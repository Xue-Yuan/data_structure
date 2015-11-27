/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //Reverse a singly list in place
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(!head || !head->next) return head;
        ListNode *p = head, *c = p->next, *n = c->next;
        p->next = nullptr;
        
        while(c)
        {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
    ListNode *reverseList2(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode prehead(0);
        prehead.next = head;
        ListNode *pre = &prehead;
        ListNode *pstart = prehead.next;
        while(pstart->next)
        {
            ListNode *p = pstart->next;
            pstart->next = p->next;
            p->next = pre->next;
            pre->next = p;
        }
    }
};