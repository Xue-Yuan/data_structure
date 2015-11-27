#ifndef QUICKSORT_H
#define QUICKSORT_H

/*
	Manually handle the vector of only 1 or 2 elements;
	Choose the median of a vector as the pivot, put it at the end;
	Start from the end side.	
*/

template <class T>
T &median3(std::vector<T> &vec, int b, int e)
{	
	auto &beg = vec[b], &end = vec[e], &mid = vec[(b+e)/2];
	if(beg > mid)
		std::swap(beg, mid);	// X, (中或大), X
	if(beg > end)
		std::swap(beg, end);	// 小，(中或大)，(中或大)
	if(end > mid)
		std::swap(mid, end);
	return end;
}

template <class T>
void quicksort(std::vector<T> &vec, int beg, int end)
{	
	if(beg >= end) return;
	if(beg + 1 == end)
	{
		if(vec[beg] > vec[end]) std::swap(vec[beg], vec[end]);
		return;
	}
	auto &pivot = median3(vec, beg, end);
		
	int i = beg, j = end;
	for(;;)
	{	
		while(vec[--j] > pivot);
		while(pivot > vec[++i]);
		if(i < j)
			std::swap(vec[i], vec[j]);
		else break;
	}
	std::swap(pivot, vec[i]);
	quicksort(vec, beg, i-1);
	quicksort(vec, i+1, end);
}

template <class T>
void quicksort(std::vector<T> &vec)
{
	quicksort(vec, 0, vec.size()-1);
}

#endif