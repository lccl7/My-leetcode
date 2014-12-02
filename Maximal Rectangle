//Use the matrix where ones to build a Histogram, then 
//we can use Largest Rectangle in Histogram to give the results
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()) return 0;
        int maxarea = 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> height(row, vector<int>(col, 0));
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
            {
                if(matrix[i][j] == '1')
                {
                    height[i][j] = (i == 0 ? 1 : height[i-1][j] + 1);
                }
            }
            
        for(int i = 0; i < row; ++i)
        {
            int area = LargestHist(height[i]);
            if(area > maxarea)
                maxarea = area;
        }
        return maxarea;
    }
        int LargestHist(vector<int> &height)
        {
            height.push_back(0);
            stack<int> st;
            int maxarea = 0;
            int i = 0;
            while(i < height.size())
            {
                if(st.empty() || height[st.top()] <= height[i])
                st.push(i++);
                else
                {
                    int t = st.top();
                    st.pop();
                // Calculate the area with hist[tp] stack as smallest bar
                    int area = height[t]*(st.empty() ? i : i-st.top()-1);
                    if(area > maxarea)
                        maxarea = area;
                }
            }
            return maxarea;
        }
};
