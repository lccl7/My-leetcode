//i, j indicates the place where we at.
//deep is how long we have gone farther, means how many letters have been matched
//because we cannot use a letter twice, so we define res first as ' ', once we use 
//the letter, we change the letter with 'o', but when we return false, we should
//change back with ' ', so that next time we can use this letter again.
bool dfs(vector<vector<char>> &board, string word, int i, int j, int deep, vector<vector<char>> &res)
{
    if(deep == word.size()) return true;
    int row = board.size(), col = board[0].size();
    if(i < 0 || i >= row || j < 0 || j >= col || 
        board[i][j] != word[deep] || res[i][j] == 'o') return false;
    res[i][j] = 'o';
    if(dfs(board, word, i+1, j, deep+1, res)) return true;
    if(dfs(board, word, i-1, j, deep+1, res)) return true;
    if(dfs(board, word, i, j+1, deep+1, res)) return true;
    if(dfs(board, word, i, j-1, deep+1, res)) return true;
    res[i][j] = ' ';
    return false;
}

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word.empty()) return true;
        char c = word[0];
        int row = board.size(), col = board[0].size();
        vector<vector<char>> res(row, vector<char>(col, ' '));
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
            {
                    if(dfs(board, word, i, j, 0, res)) return true;
            }
        return false;
    }
};
