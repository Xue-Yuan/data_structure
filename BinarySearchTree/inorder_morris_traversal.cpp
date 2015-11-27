#include <iostream>

using namespace std;

struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderMorrisTraversal(TreeNode *root)
{
	TreeNode *cur = root, *prev;
	while(cur)
	{
		if(!cur->left)
		{
			cout << cur->val;
			cur = cur->right;		//we get back from here
		}
		else
		{
			prev = cur->left;
			while(prev->right && prev->right != cur)
				prev = prev->right;
			if(!prev->right)
			{
				prev->right = cur;
				cur = cur->left;
			}
			else	//now it's back to mid node, we can print it
			{
				cout << cur->val;
				cur = cur->right;
				prev->right = nullptr;
			}
		}
	}
}