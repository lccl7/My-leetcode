The first method is to use O(m+n) to memory which index is 0.
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        set<int> indexset1, indexset2;
        for(int i = 0; i < matrix.size(); ++i)
            for(int j = 0; j < matrix[i].size(); ++j)
            {
                if(matrix[i][j] == 0)
                {
                    indexset1.insert(i);
                    indexset2.insert(j);
                }
            }
        for(int i = 0; i < matrix.size(); ++i)
            for(int j = 0; j < matrix[i].size(); ++j)
            {
                if(indexset1.find(i) != indexset1.end())
                    matrix[i][j] = 0;
                else if(indexset2.find(j) != indexset2.end())
                    matrix[i][j] = 0;
            }
    }
};

class Solution {
public    void setZeroes(vector<vector<int> > &matrix) {
        bool row0 = false, col0 = false;
        for(int i = 0; i < matrix.size(); ++i)
            if(matrix[i][0] == 0)
            {
                row0 = true; break;
            }
        for(int j = 0; j < matrix[0].size(); ++j)
            if(matrix[0][j] == 0)
            {
                col0 = true; break;
            }
        for(int i = 0; i < matrix.size(); ++i)
            for(int j = 0; j < matrix[i].size(); ++j)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        for(int i = 1; i < matrix.size(); ++i)
            for(int j = 1; j < matrix[i].size(); ++j)
            {
                if(matrix[i][0] == 0 || if(matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        if(row0)
            for(int i = 0; i < matrix.size(); ++i)
                matrix[i][0] = 0;
        if(col0)
            for(int j = 0; j < matrix[0].size(); ++j)
                matrix[0][j] = 0;
    }
};
