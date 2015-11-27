#include <vector>
#include <iostream>

using namespace std;

template <class T>
void merge(std::vector<T> &vec)
{
	std::vector<T> tmpV(vec.size());

	int b1, e1, b2, e2, cur;
	for(int k = 1; k < vec.size(); k <<= 1)
	{		
		cur = b1 = 0;
		e1 = b1 + k;
		b2 = e1;
		e2 = b2 + k;
		while(b1 < vec.size())
		{
			while(b2 < vec.size() && b1 != e1 && b2 != e2)
				if(vec[b1] < vec[b2])
					tmpV[cur++] = vec[b1++];
				else
					tmpV[cur++] = vec[b2++];
			while(b1 != e1)
				tmpV[cur++] = vec[b1++];
			while(b2 < vec.size() && b2 != e2)
				tmpV[cur++] = vec[b2++];			

			b1 = e2;
			e1 = b1 + k;
			b2 = e1;
			e2 = b2 + k;
		}
		for(int i = 0; i < vec.size(); ++i)
			vec[i] = tmpV[i];
	}	
}

int main()
{
	std::vector<int> v = {10,2,30,5,99,390,24,56,7900,89};
	merge<int>(v);
	for(auto &e : v)
		cout << e << ' ';
	cout << endl;
}