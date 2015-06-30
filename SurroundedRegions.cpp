 //This problem can use dfs but runtime error.
 //This is solved by bfs.
 void bfs(vector<vector<char>> &board, int row, int col) 
 {
    if (board[row][col] != 'O') return;
    int N = board.size(), M = board[0].size();
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    while (!q.empty())
    {
        int i = q.front().first, j = q.front().second;
        q.pop();
        if (i < 0 || i >= N || j < 0 || j >= M) continue;
        if (board[i][j] != 'O') continue;// important to recheck!
        board[i][j] = 'D';
        q.push(make_pair(i-1, j));
        q.push(make_pair(i+1, j));
        q.push(make_pair(i, j-1));
        q.push(make_pair(i, j+1));
    }
}

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty()) return;
        int row = board.size(), col = board[0].size();
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
            {
                if(i == 0 || i == row - 1 || j == 0 || j == col - 1)
                {
                    bfs(board, i, j);
                }
            }
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
            {
                if(board[i][j] == 'D')
                    board[i][j] = 'O';
                else
                if(board[i][j] = 'O')
                    board[i][j] = 'X';
            }
    }
};
