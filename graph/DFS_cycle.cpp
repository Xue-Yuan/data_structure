/*
    cycle detected, return true; else return false
    
    The idea is to maintain a new path each time we begin a DFS.

    Because the path is new, no previous vetices(or ancestors)
        will appear on the path unless there is a cycle, meaning
        there is a back edge.
*/
bool DFS(int c, vector<bool> &ondfs) 
{
    ondfs[c] = visit[c] = true;
    for(auto &e : graph[c])     //for every vertex e adjacent to c 
    {
        if(ondfs(e) || DFS(e, ondfs))
            return true;
    }
    return ondfs[c] = false;    //reset
}