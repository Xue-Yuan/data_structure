/*
    Range Minimum Query
*/
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

/*
    Query for minimum of a given range.
    http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/

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
    int constructUntil(const vector<int> &arr, int si, int ss, int se)
    {
        if(ss == se)
        {
            st[si] = arr[ss];
            return st[si];
        }

        int mid = getMid(ss, se);
        st[si] = min(constructUntil(arr, si * 2 + 1, ss, mid), constructUntil(arr, si * 2 + 2, mid + 1, se));
        return st[si];
    }
    int getMinUntil(int si, int ss, int se, int qs, int qe)
    {
        if(ss > qe || se < qs)
            return INT_MAX;
        if(ss == se)
            return st[si];
        if(ss >= qs && se <= qe)
            return st[si];
        int mid = getMid(ss, se);
        return min(getMinUntil(si * 2 + 1, ss, mid, qs, qe), getMinUntil(si * 2 + 2, mid + 1, se, qs, qe));
    }
    void updateValUntil(int si, int ss, int se, int idx, int newVal)
    {   
        // cout << "ss: " << ss << " se: " << se << endl;
        if(ss > se) return;
        if(ss == se)
        {
            if(idx == ss) st[si] = newVal;
            return;
        }
        if(idx < ss || idx > se)
            return;
        st[si] = min(st[si], newVal);
        int mid = getMid(ss, se);
        updateValUntil(si * 2 + 1, ss, mid, idx, newVal);
        updateValUntil(si * 2 + 2, mid + 1, se, idx, newVal);
    }
public:
    segmentTree(const vector<int> &arr):max_idx(arr.size() - 1)
    {
        int n = ceil(log2(arr.size()));
        int maxSize = ((1 << (n + 1)) - 1);
        st.assign(maxSize, 0);
        constructUntil(arr, 0, 0, arr.size() - 1);

    }
    int getMin(int qs, int qe)
    {
        //invalid input
        if(qs < 0 || qs > max_idx)
        {
            cout << "INVALID INPUT!!!" << endl;
            return INT_MAX;
        }

        return getMinUntil(0, 0, max_idx, qs, qe);
    }
    void updateVal(vector<int> &arr, int idx, int newVal)
    {   
        //invaild input index
        if(idx < 0 || idx >= arr.size())
        {
            cout << "INVALID INPUT!!!" << endl;
            return;
        }
        arr[idx] = newVal;
        updateValUntil(0, 0, max_idx, idx, newVal);
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
    cout << "Min from 2 to 5: " << st.getMin(2, 5) << endl;
    st.updateVal(v,2,-1);
    st.print();
    cout << "Min from 2 to 5: " << st.getMin(2, 5) << endl;
    cout << endl;
    return 0;
}