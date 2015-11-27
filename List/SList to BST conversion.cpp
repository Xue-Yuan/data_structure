#include <iostream>

using namespace std;
 
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, nullptr);
    }
    TreeNode *sortedListToBST(ListNode *head, ListNode *tail)
    {
        TreeNode *root;
        if(head == tail) return nullptr;
        if(head->next == tail) return new TreeNode(head->val);
        if(head->next->next == tail)
        {
            root = new TreeNode(head->val);
            root -> right = new TreeNode(head->next->val);
            return root;
        }
        ListNode *mid = head,*tmp = head;
        while(tmp != tail && tmp->next != tail)
        {
            mid = mid->next;
            tmp = tmp->next->next;
        }
        root = new TreeNode(mid->val);
        root->left = sortedListToBST(head, mid);
        root->right = sortedListToBST(mid->next, tail);
        return root;
    }
};

int main()
{
	ListNode *A[10];
    A[9] = new ListNode(9);
    for(int i = 8; i >= 0; --i)
    {
        A[i] = new ListNode(i);
        A[i]->next = A[i+1];
    }
    Solution so;
    auto root = so.sortedListToBST(A[0]);
    return 0;
}
