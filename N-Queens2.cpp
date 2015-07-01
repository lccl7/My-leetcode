//Just the same as N-Queens, be careful that we should pass by reference.
//If not, sum is unchanged.
class Solution {
public:
    int totalNQueens(int n) {
        int sum = 0;
        vector<int> tmp(n);
        dfs(n, 0, sum, tmp);
        return sum;
    }
    bool is_solution(int row, vector<int>& tmp)
    {
        for(int i = 0; i < row; ++i)
        {
            if(tmp[i] == tmp[row] || abs(tmp[i]-tmp[row]) == row - i)
            return false;
        }
        return true;
    }
    void dfs(int n, int row, int &sum, vector<int>& tmp)
    {
        if(n == row)
        {
            sum++;
            return;
        }
        else
        {
            for(int i = 0; i < n; ++i)
            {
                tmp[row] = i;
                if(is_solution(row, tmp))
                {
                    dfs(n, row+1, sum, tmp);
                }
            }
        }
    }
};

int totalNQueens(int n)
{
    int tot = 0;
    vector<vector<int>> vis(3, vector(2*n, 0));
    search(0, n, tot, vis);
    return tot;
}

void search(int cur, int n, int& tot, vector<vector<int>>& vis)
{
    if(cur == n)
        tot++;
    else {
        for(int i = 0; i < n; i++)
        {
            if(vis[0][i] == 0 && vis[1][cur+i] == 0 && vis[2][cur-i+n] == 0)
            {
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 1;
                search(cur+1, n, tot, vis);
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 0;
            }
        }
    }
}
