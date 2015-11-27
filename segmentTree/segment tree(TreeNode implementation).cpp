class segmentTree 
{
private:
    struct segmentTreeNode
    {
        int val;
        int start, end;
        segmentTreeNode *left;
        segmentTreeNode *right;
        segmentTreeNode(int s, int e):val(0), start(s), end(e), left(nullptr), right(nullptr){}
    };
    vector<int> nums;
    segmentTreeNode *tree;
public:
    segmentTree(vector<int> &nums): nums(move(nums))
    {
        tree = buildTree(0, this->nums.size() - 1, this->nums);
    }

    void update(int i, int val) 
    {
        int diff = val - nums[i];
        update(tree, i , diff);
        nums[i] = val;
    }

    int sumRange(int i, int j) 
    {
        return getSum(tree, i, j);   
    }

private:
    segmentTreeNode* buildTree(int start, int end, vector<int> &nums)
    {
        if(start > end) return nullptr;
        segmentTreeNode *root = new segmentTreeNode(start, end);
        if(start == end) root->val = nums[start];
        else
        {
            int mid = start + ((end - start) >> 1);
            root->left = buildTree(start, mid, nums);
            root->right = buildTree(mid + 1, end, nums);
            root->val = root->left->val + root->right->val;
        }
        return root;
    }
    void update(segmentTreeNode *root, int i, int diff)
    {
        if(!root || i < root->start || i > root->end) return;
        root->val += diff;
        update(root->left, i, diff);
        update(root->right, i, diff);
    }
    int getSum(segmentTreeNode *root, int i, int j)
    {
        if(!root || j < root->start || i > root->end) return 0;
        if(i <= root->start && j >= root->end) return root->val;
        return getSum(root->left, i, j) + getSum(root->right, i, j);
    }
};