//The min path sum in [i][j] is the sum of left([i][j-1]) and current one, 
//or the sum of above[i-1][j] and the current one, depending which one is smaller.
//Every time update a row from the left to right so that the rightmost is the minimum.
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
            {
                if(i == 0 && j != 0)
                    grid[i][j] += grid[i][j-1];
                if(j == 0 && i != 0)
                    grid[i][j] += grid[i-1][j];
                if(i != 0 && j != 0)
                    grid[i][j] = min(grid[i][j]+grid[i-1][j], grid[i][j]+grid[i][j-1]);
            }
        return grid[m-1][n-1];
    }
};
