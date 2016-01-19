/*
    quickSelect find median.
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int &median3(vector<int> &nums, int beg, int end)
    {
        int &b = nums[beg], &e = nums[end], &m = nums[(beg + end) / 2];
        if(b > m) swap(b, m);
        if(b > e) swap(b, e);
        if(m < e) swap(m, e);
        return e;
    }
    void quickSelect(vector<int> &nums, int b, int e, int k)
    {
        if(b >= e) return;
        if(b + 1 == e)
        {
            if(nums[b] > nums[e]) swap(nums[b], nums[e]);
            return;
        }

        int &pivot = median3(nums, b, e); 
        int i = b, j = e;
        while(i < j)
        {
            while(nums[--j] > pivot);
            while(nums[++i] < pivot);
            if(i < j) swap(nums[i], nums[j]);
        }
        swap(nums[i], pivot);
        if(k-1 < i) quickSelect(nums, b, i - 1, k);
        else if(k-1 > i) quickSelect(nums, i + 1, e, k);
    }
public:
    void quickSelect(vector<int> &nums, int k)
    {
        quickSelect(nums, 0, nums.size() - 1, k);
    }
    double median(vector<int> &nums)
    {   
        int k = nums.size()  / 2;
        quickSelect(nums, k);
        if(nums.size() & 0x1) return nums[k];
        quickSelect(nums, k + 1);
        return (nums[k - 1] + nums[k]) / 2.0;
    }

};

int main()
{
    vector<int> v = {9,4,6,3,7,8,0,2,5};
    Solution so;
    cout << so.median(v) << endl;
    return 0;
}