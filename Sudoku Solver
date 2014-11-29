//First, we build a empty vector<int> to keep those box that there is no num(.)
//The len is the size that have no num, we keep tracking until cur equals len, then game over.
//In dfs we begin with 0, and find the index in vector empty. Next we try the attempnum
//from 1 to 9 to find a suitable one. If it is a solution, continue dfs, else back try another.
//In function is_solution is to find a valid attempnum, which can not conflict with the row,
//column, and in the small box(3*3), 3*(row/3), 3*(col/3) is defined which box the element belongs.
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        vector<int> empty;
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j)
            {
                if(board[i][j] == '.')
                    empty.push_back(i*9 + j);
            }
        int len = empty.size();
        dfs(len, 0, empty, board);
    }
    bool dfs(int len, int cur, vector<int> empty, vector<vector<char>> &board)
    {
        if(cur == len)  return true;
        int index = empty[cur];
        int row = index/9, col = index%9;
        for(int attempnum = 1; attempnum <=9; ++attempnum)
        {
            if(is_solution(attempnum, row, col, board))
            {
                board[row][col] = attempnum + '0';
                if(dfs(len, cur+1, empty, board))
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    
    bool is_solution(int v, int row, int col, vector<vector<char>> &board)
    {
        for(int i = 0; i < 9; ++i)
        {
            if(board[row][i] - '0' == v || board[i][col] - '0' == v)
                return false;
            int row_s = 3*(row/3) + i/3, col_s = 3*(col/3)+i%3;
            if(board[row_s][col_s] - '0' == v) return false;
        }
        return true;
    }
    
};
