//Just the same as Sudoku solve. We can just change dfs from void to bool value.
//Use is_valid function to search the same element in the same row, 
//or the same column, or the same small box.
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<int> number;
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j)
            {
                if(board[i][j] != '.')
                    number.push_back(i*9 + j);
            }
        int len = number.size();
        return dfs(len, 0, number, board);
    }
    
    bool dfs(int len, int cur, vector<int> &number, vector<vector<char>> &board)
    {
        if(len == cur) return true;
        int index = number[cur];
        int row = index/9, col = index%9;
        if(is_valid(row, col, board))
        {
            return dfs(len, cur+1, number, board);
        }
        else
            return false;
    }
    
    bool is_valid(int row, int col, vector<vector<char>> &board)
    {
        char c = board[row][col];
        for(int i = 0; i < 9; ++i)
        {
            if(i != col && board[row][i] == c) return false;
            if(i != row && board[i][col] == c) return false;
            int row_s = 3*(row/3) + i/3, col_s = 3*(col/3)+i%3;
            if(row_s != row && col_s != col && board[row_s][col_s] == c) return false;
        }
        return true;
    }
};
