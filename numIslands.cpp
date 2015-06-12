int numIslands(vector<vector<char>>& grid)
{
    if(grid.empty()) return 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> idx(m, vector<int>(n, 0));
    int cnt = 0;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(idx[i][j] == 0 && grid[i][j] == '1')
                dfs(i, j, ++cnt, grid, m, n, idx);
    return cnt;
}

void dfs(int r, int c, int id, vector<vector<char>>& grid, int m, int n, vector<vector<int>>& idx)
{
    if(r >= m || r < 0 || c >= n || c < 0) return;
    if(idx[r][c] > 0 || grid[r][c] != '1') return;
    idx[r][c] = id;
    dfs(r+1, c, id, grid, m, n, idx);
    dfs(r-1, c, id, grid, m, n, idx);
    dfs(r, c-1, id, grid, m, n, idx);
    dfs(r, c+1, id, grid, m, n, idx);
}
