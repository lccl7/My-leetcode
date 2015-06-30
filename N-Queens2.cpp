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
    bool is_solution(int row, vector<int> tmp)
    {
        for(int i = 0; i < row; ++i)
        {
            if(tmp[i] == tmp[row] || abs(tmp[i]-tmp[row]) == row - i)
            return false;
        }
        return true;
    }
    void dfs(int n, int row, int &sum, vector<int> tmp)
    {
        if(n == row)
        {
            sum += 1;
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
