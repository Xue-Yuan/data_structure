class UF
{
private:
    int* id;     // id[i] = parent of i
    int* size;  // size[i] = size of subtree rooted at i (cannot be more than 31)
    int count;    // number of components
public:
    UF(int N)
    {
        count = N;
        id = new int[N];
        size = new int[N];
        for (int i = 0; i < N; i++)
        {
            id[i] = i;
            size[i] = 0;
        }
    }
    ~UF()
    {
        delete [] id;
        delete [] size;
    }
    int find(int p)
    {
        while (p != id[p])
        {
            // path compression by halving
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }
    int getCount()
    {
        return count;
    }
    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }
    //link the smaller tree to the bigger tree so we can keep the
    //  resulting tree flat. 
    void connect(int p, int q)
    {
        int i = find(p);
        int j = find(q);
        if (i == j) return;
        if (size[i] < size[j]) id[i] = j;
        else if (size[i] > size[j]) id[j] = i;
        elser
        {
            id[j] = i;
            size[i]++;
        }
        count--;
    }
};