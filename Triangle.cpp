//Given a triangle, find the minimum path sum from top to bottom.
//Each step you may move to adjacent numbers on the row below.
//  [
//     [2],
//    [3,4],
//   [6,5,7],
//  [4,1,8,3]
//  ]
//The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//the adjacent numbers below is limited to
//only below the number or the right to the number below.
//first we give the minimum is the triangle[0][0]
//then calculate the next row to update the vector we define. Again to the last.
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty()) return 0;
        vector<int> v;
        v.push_back(triangle[0][0]);
        for(int i = 1; i < triangle.size(); ++i)
        {
            for(int j = 0; j < triangle[i].size(); ++j)
            {
                if(j == 0)
                    triangle[i][j] = triangle[i][j] + v[j];
                else
                if(j == triangle[i].size()-1)
                    triangle[i][j] = triangle[i][j] + v[j-1];
                else
                {
                    int sum1 = triangle[i][j] + v[j];
                    int sum2 = triangle[i][j] + v[j-1];
                    triangle[i][j] = min(sum1, sum2);
                }
            }
            v.resize(triangle[i].size());
            v = triangle[i];
        }
        sort(v.begin(), v.end());
        return v[0];
    }
};
//we can also calculate reversely from the last row to the first.
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        const int rows = triangle.size();
        int dp[rows];
        for(int i = 0; i < rows; i++)
            dp[i] = triangle[rows-1][i];
        for(int i = rows-2; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
        return dp[0];
    }
};
