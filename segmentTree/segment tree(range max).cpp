/*
    segmentTree range max, with idx.
*/

class segmentTree
{
private:
    struct segmentTreeNode
    {
        int val;
        int start, end, max_idx;
        segmentTreeNode *left;
        segmentTreeNode *right;
        segmentTreeNode(int s, int e):val(0), start(s), end(e), left(nullptr), right(nullptr){}
    };
    vector<int> nums;
    segmentTreeNode *tree;
public:
    segmentTree(vector<int> &nums): nums(move(nums))
    {
        tree = buildTree(0, (int)this->nums.size() - 1, this->nums);
    }
    pair<int, int> rangeMax(int i, int j)
    {
        return getMax(tree, i, j);
    }
    ~segmentTree(){destoryTree(tree);}
private:
    segmentTreeNode* buildTree(int start, int end, vector<int> &nums)
    {
        if(start > end) return nullptr;
        segmentTreeNode *root = new segmentTreeNode(start, end);
        
        if(start == end)
        {
            root->val = nums[start];
            root->max_idx = start;
        }
        else
        {
            int mid = start + (end - start) / 2;
            root->left = buildTree(start, mid, nums);
            root->right = buildTree(mid + 1, end, nums);
            if (root->left->val >= root->right->val)
            {
                root->val = root->left->val;
                root->max_idx = root->left->max_idx;
            }
            else
            {
                root->val = root->right->val;
                root->max_idx = root->right->max_idx;
            }
        }
        return root;
    }
    pair<int, int> getMax(segmentTreeNode *root, int i, int j)
    {
        if(!root || j < root->start || i > root->end) return {INT_MIN, -1};
        if(i <= root->start && j >= root->end) return {root->val, root->max_idx};
        auto left = getMax(root->left, i, j), right = getMax(root->right, i, j);
        return left.first >= right.first ? left : right;
    }
    void destoryTree(segmentTreeNode *root)
    {
        if (!root) return;
        destoryTree(root->left);
        destoryTree(root->right);
        delete root;
    }
};