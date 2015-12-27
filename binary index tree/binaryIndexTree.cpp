/*
    There is one index shift from the original array to
        the binary index tree.
*/
class binaryIndexTree
{
private:
    vector<int> arr;
    vector<int> bitree;
public:
    binaryIndexTree(vector<int> &nums):arr(nums), bitree(nums.size() + 1, 0) 
    {        
        for(int i = 0; i < nums.size(); ++i)
            add(i + 1, bitree.size(), nums[i]);
    }

    void update(int i, int val) 
    {
        if(arr.empty() || i < 0 || i >= arr.size()) return;
        int diff = val - arr[i];
        arr[i] = val;
        add(i + 1, bitree.size(), diff);
    }

    int sumRange(int i, int j) 
    {
        if(i > j) return 0;
        j++;        //Note here!
        int sum_i = 0, sum_j = 0;
        for(int k = i; k > 0; k -= lowBit(k))
            sum_i += bitree[k];
        for(int k = j; k > 0; k -=lowBit(k))
            sum_j += bitree[k];
        return sum_j - sum_i;
    }
private:
    int lowBit(int x)
    {
        return x & (-x);
    }
    void add(int beg, int end, int val)
    {
        for(int i = beg; i < end; i += lowBit(i))
            bitree[i] += val;
    }
};