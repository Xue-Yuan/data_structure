/*
    2D segment tree
        O(MN) time construct tree, O(log(MN)) time query.
    
*/

#include <iostream>
#include <utility>
#include <vector>

using namespace::std;

class NumMatrix
{
private:
    struct TreeNode
    {
        int val;
        TreeNode *subranges[4] = {nullptr, nullptr, nullptr, nullptr};
        pair<int, int> leftTop;
        pair<int, int> rightBottom;
        TreeNode(int v):val(v), leftTop({0, 0}), rightBottom({0, 0}){}
        TreeNode(int v, pair<int, int> lt, pair<int, int> rb):val(v), leftTop(lt), rightBottom(rb){}
    };
public:
    NumMatrix(vector<vector<int>> &matrix): root(nullptr), nums(matrix)
    {
        if(matrix.empty() || matrix[0].empty()) return;
        
        root = buildTree({0, 0}, {(int)nums.size() - 1, (int)nums[0].size() - 1});
    }
    
    void update(int row, int col, int val)
    {
        if(row < 0 || row > (int)nums.size() || col < 0 || col > (int)nums[0].size())
            return;
        updateTree(row, col, val - nums[row][col], root);
        nums[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return sumRegion(row1, col1, row2, col2, root);
    }
    
    void print()
    {
        for(auto &v : nums)
        {
            for(auto &e : v)
                cout << e << ' ';
            cout << endl;
        }
    }
    
private:
    TreeNode* root;
    vector<vector<int>> nums;
    
    TreeNode* buildTree(pair<int, int> lt, pair<int, int> rb)
    {
        if(lt.first > rb.first || lt.second > rb.second)
            return nullptr;
        if(lt == rb)
            return new TreeNode(nums[lt.first][lt.second], lt, rb);
        
        int mid_x = lt.first + (rb.first - lt.first) / 2;
        int mid_y = lt.second + (rb.second - lt.second) / 2;
        
        TreeNode *cur = new TreeNode(0, lt, rb);
        cur->subranges[0] = buildTree(lt, {mid_x, mid_y});
        cur->subranges[1] = buildTree({lt.first, mid_y + 1}, {mid_x, rb.second});
        cur->subranges[2] = buildTree({mid_x + 1, lt.second}, {rb.first, mid_y});
        cur->subranges[3] = buildTree({mid_x + 1, mid_y + 1}, rb);
        
        for(int i = 0; i < 4; ++i)
            if(cur->subranges[i])
                cur->val += cur->subranges[i]->val;
        
        return cur;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2, TreeNode* const &ptr)
    {
        if(!ptr) return 0;
        
        auto &lt = ptr->leftTop, &rb = ptr->rightBottom;
        //disjoint
        if(row2 < lt.first || col2 < lt.second || row1 > rb.first || col1 > rb.second)
            return 0;
        
        //fully cover
        if(row1 <= lt.first && col1 <= lt.second && row2 >= rb.first && col2 >= rb.second)
            return ptr->val;
        
        //overlap
        int sum = 0;
        for (int i = 0; i < 4; ++i)
            sum += sumRegion(row1, col1, row2, col2, ptr->subranges[i]);
        
        return sum;
    }
    
    void updateTree(int row, int col, int diff, TreeNode* ptr)
    {
        if(!ptr) return;
        
        auto &lt = ptr->leftTop, &rb = ptr->rightBottom;
        //out of range
        if(row < lt.first || col < lt.second || row > rb.first || col > rb.second)
            return;
        
        ptr->val += diff;
        for(int i = 0; i < 4; ++i)
            updateTree(row, col, diff, ptr->subranges[i]);
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3},
                                  {4,5,6},
                                  {7,8,9}};
    NumMatrix M(matrix);
    
    string cmd = "";
    cout << "cmd: " << endl;
    cout << "  sum\n  print\n  update\n  quit" << endl;
    while (cmd != "quit")
    {
        cout << "cmd> ";
        cin >> cmd;
        if(cmd == "sum")
        {
            cout << "Enter range(row1, col1, row2, col2): ";
            int row1, col1, row2, col2;
            cin >> row1 >> col1 >> row2 >> col2;
            if(cin)
                cout << "Sum: " << M.sumRegion(row1, col1, row2, col2) << endl;
            else
            {
                cin.clear();
                getline(cin, cmd);
            }
        }
        else if(cmd == "update")
        {
            cout << "Enter index(row, col, val): ";
            int row, col, val;
            cin >> row >> col >> val;
            if(cin)
                M.update(row, col, val);
            else
            {
                cin.clear();
                getline(cin, cmd);
            }
        }
        else if(cmd == "print")
        {
            M.print();
        }
        else if(cmd == "quit")
        {
            cout << "Program exit!" << endl;
            break;
        }
        else
        {
            cout << "Invalid!" << endl;
            getline(cin, cmd);
        }
    }
    return 0;
}