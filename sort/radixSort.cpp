void radixSort(vector<int> &nums)
{
    auto max = max_element(nums.begin(), nums.end());
    
    const int base = 10;
    int t = 1;
    vector<int> tmp(nums.size(), 0);
    while (*max / t)
    {
        vector<int> count(base, 0);
        for (auto &e : nums) 
            count[e / t % 10]++;
        for (int i = 0; i < base - 1; ++i)
            count[i + 1] += count[i];
        //go backwards to remain the previous order
        for (auto itr = nums.rbegin(); itr != nums.rend(); ++itr)
            tmp[--count[*itr / t % 10]] = *itr;
        swap(nums, tmp);
        t *= 10;
    }
}
