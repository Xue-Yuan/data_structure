//
//  heap.h
//
//  Binary heap.
//
//  Created by YuanX on 11/26/15.
//
//

#ifndef ____heap__
#define ____heap__

#include <vector>
#include <exception>

using std::vector;

//if COMP()(T &a, T &b) true, a goes up.
template <class T, class COMP>
class heap
{
private:
    int currentSize;
    vector<T> array;
    
    void buildHeap()
    {
        for (int i = currentSize / 2; i > 0; --i)
            percolateDown(i);
    }
    
    void percolateDown(int hole)
    {
        T tmp = std::move(array[hole]);
        while (hole * 2 <= currentSize)
        {
            int child = hole * 2;
            if(hole * 2 + 1 <= currentSize)
                child = COMP()(array[child], array[child + 1]) ? child : child + 1;
            if (COMP()(array[child], tmp))
            {
                array[hole] = std::move(array[child]);
                hole = child;
            }
            else break;
        }
        array[hole] = std::move(tmp);
    }
public:
    //avoid conversion constructor
    explicit heap(int capacity = 100): array(capacity), currentSize(0){}
    explicit heap(const vector<T> &item): currentSize((int)item.size())
    {
        array.assign(currentSize + 10, 0);
        for(int i = 0; i < currentSize; ++i)
            array[i + 1] = item[i];
        buildHeap();
    }
    
    bool isEmpty() const
    {
        return currentSize == 0;
    }
    const T &findMin() const
    {
        if(!isEmpty())
            return array[1];
        else
            throw std::underflow_error{"Empty heap"};
    }
    
    void insert(const T &x)
    {
        if (currentSize == (int)array.size())
        array.resize(currentSize * 2);
    
        int hole = ++currentSize;
        while (hole / 2 > 0)
        {
            int parent = hole / 2;
            if (COMP()(x, array[parent]))
            {
                array[hole] = std::move(array[parent]);
                hole = parent;
            }
            else
                break;
        }
        array[hole] = x;
    }

    void insert(T &&x)
    {
        if (currentSize == (int)array.size())
        array.resize(currentSize * 2);
    
        int hole = ++currentSize;
        while (hole / 2 > 0)
        {
            int parent = hole / 2;
            if (COMP()(x, array[parent]))
            {
                array[hole] = std::move(array[parent]);
                hole = parent;
            }
            else
                break;
        }
        array[hole] = std::move(x);
    }
    
    bool deleteMin()
    {
        if(array.empty())
            return false;
        array[1] = std::move(array[currentSize--]);
        percolateDown(1);
        return true;
    }

    bool deleteMin(T &min)
    {
        if (array.empty())
            throw std::underflow_error("Empty heap");
        min = std::move(array[1]);
        array[1] = std::move(array[currentSize--]);
        percolateDown(1);
        return true;
    }

    void makeEmpty()
    {
        array.clear();
        currentSize = 0;
    }
};

#endif /* defined(____heap__) */
