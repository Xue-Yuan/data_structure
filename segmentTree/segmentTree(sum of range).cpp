/*
    Query for sum of a given range.
    http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
*/

#include <cmath>
#include <vector>

/*
    If we don't need to update the values, simply a prefix sum table is enough.
*/

using namespace std;

/*
    si: index in segment tree;
    ss: segment start index(the index from original array)
    se: segment end index(the index from original array)
    qs: query start index
    qe: query end index
*/
class segmentTree
{
private:
    //st: save the segment tree;
    vector<int> st;
    //max index from the original array
    int max_idx;
    int getMid(int beg, int end){return beg + (end - beg) / 2;}
    int constructSTUntil(const vector<int> &arr, int ss, int se, int si)
    {
        if(ss == se)
        {
            st[si] = arr[ss];
            return st[si];
        }

        int mid = getMid(ss, se);
        st[si] = constructSTUntil(arr, ss, mid, 2 * si + 1) + constructSTUntil(arr, mid + 1, se, 2 * si + 2);
        return st[si];
    }
    int getSumUtil(int ss, int se, int qs, int qe, int si)
    {
        if(qs <= ss && qe >= se)
            return st[si];
        if(qe < ss || se < qs)
            return 0;

        int mid = getMid(ss, se);
        return getSumUtil(ss, mid, qs, qe, si * 2 + 1) + getSumUtil(mid + 1, se, qs, qe, si * 2 + 2);
    }
    void updateUntil(int ss, int se, int idx, int diff, int si)
    {
        if(ss > se)
            return;
        if(ss == se)
        {
            st[si] += diff;
            return;
        }
        if(ss > si || se < si)
            return;

        st[si] += diff;

        int mid = getMid(ss, se);
        updateUntil(ss, mid, idx, diff, si * 2 + 1);
        updateUntil(mid + 1, se, idx, diff, si * 2 + 2);
    }
public:
    segmentTree(const vector<int> &arr):max_idx(arr.size() - 1)
    {
        int n = ceil(log2(arr.size()));
        int maxSize = ((1 << (n + 1)) - 1);
        st.assign(maxSize, 0);

        constructSTUntil(arr, 0, arr.size() - 1, 0);
    }
    int getSum(int qs, int qe)
    {
        return getSumUtil(0, max_idx, qs, qe, 0);
    }
    void updateVal(vector<int> &arr, int idx, int newVal)
    {   
        //invaild input index
        if(idx < 0 || idx >= arr.size())
            return;
        
        int diff = newVal - arr[idx];
        arr[idx] = newVal;
        updateUntil(0, arr.size() - 1, idx, diff, 0);
    }
    void print()
    {
        for(auto &e : st)
            cout << e << ' ';
        cout << endl;
    }
};


int main()
{
    std::vector<int> v = {1,3,5,7,9,11};
    segmentTree st(v);
    st.print();
    cout << "Sum from 0 - 3: " << st.getSum(0, 3) << endl;
    st.updateVal(v,2,10);
    st.print();
    cout << "Sum from 0 - 3: " << st.getSum(0, 3) << endl;
    cout << endl;
    return 0;
}
