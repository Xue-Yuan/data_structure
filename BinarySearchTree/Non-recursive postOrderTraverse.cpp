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
 

struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Record how many times the current node is on top of the stack.
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        stack<pair<TreeNode*, bool>> stk;
        TreeNode *cur = root;
        while(cur || !stk.empty())
        {
            if (cur)
            {
                stk.push({cur, false});
                cur = cur->left;
            }
            else if (!stk.empty())
            {
                auto p = stk.top(); stk.pop();
                if (p.second) ret.push_back(p.first->val);
                else
                {
                    stk.push({p.first, !p.second});
                    cur = p.first->right;
                }
            }
        }
        return ret;
    }
};

// Record the last visited node.
class Solution2
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        stack<TreeNode *> stk;
        TreeNode *cur = root, *last = nullptr;
        vector<int> ret;
        
        while (cur || !stk.empty())
        {
            while (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            if (!stk.empty())
            {
                TreeNode *top = stk.top();
                if (top->right && last != top->right)
                    cur = top->right;
                else
                {
                    last = top; 
                    ret.push_back(top->val);
                    stk.pop();
                }
            }
        }
        return ret;
    }
};


int main()
{
	TreeNode *A = new TreeNode(10), *B = new TreeNode(11), *C = new TreeNode(12), *D = new TreeNode(14);
	A->left = B; A->right = C;
	C->left = D;
	std::vector<int> v;
	Solution so;
	v = so.postorderTraversal(A);	

	for(auto &e : v)
		cout << e << ' ';
	cout << endl;
	return 0;
}
