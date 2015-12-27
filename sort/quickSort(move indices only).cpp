template <class T>
T &median3(std::vector<T> &vec, int b, int e, vector<int> &indices)
{
    auto &beg = indices[b], &end = indices[e], &mid = indices[(b+e)/2];
    if(vec[beg] > vec[mid])
        std::swap(beg, mid);	// X, (中或大), X
    if(vec[beg] > vec[end])
        std::swap(beg, end);	// 小，(中或大)，(中或大)
    if(vec[end] > vec[mid])
        std::swap(mid, end);
    return end;
}

template <class T>
void quicksort(std::vector<T> &vec, int beg, int end, vector<int> &indices)
{
    if(beg >= end) return;
    if(beg + 1 == end)
    {
        if(vec[indices[beg]] > vec[indices[end]]) std::swap(indices[beg], indices[end]);
        return;
    }
    auto &pivot = median3(vec, beg, end, indices);
    
    int i = beg, j = end;
    for(;;)
    {
        while(vec[indices[--j]] > pivot);
        while(vec[pivot] > vec[indices[++i]]);
        if(i < j)
            std::swap(indices[i], indices[j]);
        else break;
    }
    std::swap(pivot, indices[i]);
    quicksort(vec, beg, i-1, indices);
    quicksort(vec, i+1, end, indices);
}

template <class T>
void quicksort(std::vector<T> &vec, vector<int> &indices)
{
    quicksort(vec, 0, (int)vec.size()-1, indices);
}