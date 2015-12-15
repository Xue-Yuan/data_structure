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

//use pair
//some how this is slower than previous two methods
class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        stack<pair<TreeNode *, bool>> stk;
        std::vector<int> ret;
        TreeNode *cur = root;

        while(cur || !stk.empty())
        {
            while(cur)
            {
                stk.push({cur, true});      //use pair
                cur = cur->left;
            }
            if(!stk.empty())
            {
                auto &top = stk.top();   //Here we have to use reference  
                if(top.second)
                {
                    top.second = false;
                    cur = top.first->right;
                }
                else
                {
                    ret.push_back(top.first->val);
                    stk.pop();
                    cur = nullptr;      //very important
                }
            }
        }
        return ret;
    }
};

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
