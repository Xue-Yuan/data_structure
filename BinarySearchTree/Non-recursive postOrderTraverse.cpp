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
 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    	unordered_map<TreeNode *, int> count;
    	stack<TreeNode *> stk;
    	std::vector<int> v;
    	TreeNode *tmp = root;

    	while(tmp || !stk.empty())
    	{
    		while(tmp)
    		{
    			stk.push(tmp);
    			tmp = tmp->left;
    		}
    		if(!stk.empty())
    		{
    			tmp = stk.top();
    			if(count[tmp] == 0)
    			{
    				count[tmp]++;
    				tmp = tmp->right;
    			}
    			else if(count[tmp] == 1)
    			{
    				v.push_back(tmp->val);
    				stk.pop();
    				tmp = nullptr;		//very important
    			}
    		}
    	}
    	return v;
    }
};

//without using hash map
class Solution2 {
public:
    struct myNode
    {
        TreeNode *node;
        bool isFirst;
        myNode():node(nullptr), isFirst(false){};
    };
    vector<int> postorderTraversal(TreeNode* root) {
        stack<myNode *> stk;
        std::vector<int> v;
        TreeNode *tmp = root;
        myNode *mine;

        while(tmp || !stk.empty())
        {
            while(tmp)
            {
                myNode *tmpNode = new myNode();
                tmpNode->node = tmp;
                tmpNode->isFirst = true;
                stk.push(tmpNode);
                tmp = tmp->left;
            }
            if(!stk.empty())
            {
                mine = stk.top();
                if(mine->isFirst)
                {
                    mine->isFirst = false;
                    tmp = mine->node->right;
                }
                else
                {
                    v.push_back(mine->node->val);
                    stk.pop();
                    delete mine;
                    tmp = nullptr;      //very important
                }
            }
        }
        return v;
    }
};

//use pair
//some how this is slower than previous two methods
class Solution3 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode *, bool>> stk;
        std::vector<int> v;
        TreeNode *tmp = root;

        while(tmp || !stk.empty())
        {
            while(tmp)
            {
                stk.push({tmp, true});      //use pair
                tmp = tmp->left;
            }
            if(!stk.empty())
            {
                auto &mine = stk.top();     //here must be reference
                if(mine.second)
                {
                    mine.second = false;
                    tmp = mine.first->right;
                }
                else
                {
                    v.push_back(mine.first->val);
                    stk.pop();
                    tmp = nullptr;      //very important
                }
            }
        }
        return v;
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
