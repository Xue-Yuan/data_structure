/*
there are tradeoffs, for very 'lean' tree (most non-leaf node have 
only one child), this dfs appoach consume O(n) memory, while bfs 
approach with queue cost almost constant space. for near complete 
tree (most non-leaf node have two child), dfs approach cost 
O(log(n)) memory, whereas bfs approach cost O(n) memory
*/

void buildVector(TreeNode *root, int depth, vector<vector<int>> &ret)
{
    if(root == NULL) return;
    if(ret.size() == depth)
        ret.push_back(vector<int>());

    ret[depth].push_back(root->val);
    buildVector(root->left, depth + 1);
    buildVector(root->right, depth + 1);
}

vector<vector<int> > levelOrder(TreeNode *root) {
	vector<vector<int>> ret;
    buildVector(root, 0, ret);
    return ret;
}