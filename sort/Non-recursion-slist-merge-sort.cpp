#include <iostream>
#include "algorithm.h"
#include "algorithm.cpp"
#include <map>
#include <string>
#include <vector>
#include <random>
#include <sstream>
#include <stack>
#include <set>
#include <queue>
#include <unordered_map>

using namespace std;


struct ListNode {
    int val;
  	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 

class Solution {    
public:
    ListNode* sortList(ListNode* head) 
    {
        int size = 0;
        ListNode *tmp = head;
        for(; tmp; tmp = tmp -> next, ++size);
        
        ListNode *b1, *e1, *b2, *e2;        //the end cannot be reached;
        ListNode *beforehead = new ListNode(0), *cur;		//Since we have to use beforehand->next

        cur = beforehead;		//iterate through the list
        beforehead->next = head;	//store the start point
        
        for(int k = 1; k < size; k <<= 1)
        {
            b1 = beforehead->next;            
            cur = beforehead;		//very IMPORTANT!!!

            while(b1)
            {
                e1 = moveForward(b1, k);
                b2 = e1;
                e2 = moveForward(b2, k);

                while(b1 != e1 && b2 != e2)
                    if(b1->val < b2->val)
                    {
                        cur->next = b1;
                        cur = cur->next;
                        b1 = b1->next;
                    }
                    else
                    {
                        cur->next = b2;
                        cur = cur->next;
                        b2 = b2->next;
                    }
                while(b1 != e1)
                {
                    cur->next = b1;
                    cur = cur->next;
                    b1 = b1->next;
                }
                while(b2 != e2)
                {
                    cur->next = b2;
                    cur = cur->next;
                    b2 = b2->next;
                }
                b1 = e2;
                cur->next = nullptr;
            }
        }
        return beforehead->next;
    }
    
    ListNode *moveForward(ListNode *head, int k)
    {
        if(!head) return head;
        while(k--)
        {
            head = head->next;
            if(!head) break;
        }
        return head;
    }
};

int main()
{
	ListNode *A = nullptr, *B = new ListNode(10), *D = new ListNode(99);
	// A->next = B;
	B->next = D;

	Solution so;
	auto C = so.sortList(A);

	while(C)
	{
		cout << C->val << ' ';
		C = C->next;
	}
	cout << endl;
	return 0;
}
