//We can just make zero when we find obstacle is 1.
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> v(n+1, 0);
        v[1] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j)
            if(obstacleGrid[i-1][j-1] == 0)
                v[j] = v[j] + v[j-1];
            else
                v[j] = 0;
        return v[n];
    }
};
