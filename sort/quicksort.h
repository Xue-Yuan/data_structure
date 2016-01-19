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
	int m = b + ((e - b) >> 1);
	if(vec[b] > vec[m])
		std::swap(vec[b], vec[m]);	// X, (中或大), X
	if(vec[b] > vec[e])
		std::swap(vec[b], vec[e]);	// 小，(中或大)，(中或大)
	if(vec[e] > vec[m])
		std::swap(vec[e], vec[m]);
	return vec[e];
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
	while(i < j)
	{	
		while(vec[--j] > pivot);
		while(vec[++i] < pivot);
		if(i < j) std::swap(vec[i], vec[j]);
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