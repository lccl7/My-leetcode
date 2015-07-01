//the problem request "do it in place"
//so we first transpose the matrix 
// [00, 01]
// [10, 11] becomes
// [00, 10]
// [01, 11]
// then on each row we swap the first half with the second half
// [10, 00]
// [11, 01]
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        for(int i = 0; i < rows; ++i)
        {
            for(int j = i+1; j < cols; ++j)
                swap(matrix[i][j], matrix[j][i]);
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
