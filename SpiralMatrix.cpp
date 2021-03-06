//star is the start of the row, and endr is the end of the row.
//stac is the start of the col, and endc is the end of the column.
//every loop we push_back a circle of the matrix, then go to the inner one next to it.
//if only one row or one column left the the two if can handle it.
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> v;
        if(matrix.empty()) return v;
        int star = 0, endr = matrix.size()-1;
        int stac = 0, endc = matrix[0].size()-1;
        int num = 1;
        while(star < endr && stac < endc)
        {
            int x = star, y = stac;
            while(y < endc)
                v.push_back(matrix[x][y++]);
            while(x < endr)
                v.push_back(matrix[x++][y]);
            while(y > stac)
                v.push_back(matrix[x][y--]);
            while(x > star)
                v.push_back(matrix[x--][y]);
            ++star, --endr;
            ++stac, --endc;
        }
        if(star == endr)
        {
            while(stac <= endc)
                v.push_back(matrix[star][stac++]);
        }
        else if(stac == endc)
        {
            while(star <= endr)
                v.push_back(matrix[star++][stac]);
        }
        return v;
    }
};
