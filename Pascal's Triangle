The trivial is that no Rows output
then for the next: we define two lines: one for thisline and one for previous line.
the first preline is [1]; for line 2 to line numRows:
first push [1] in the vector, and then add two elements of the previous line.
at last push[1] again in the vector. The thisline become the previous one.
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vvi;
        if(numRows == 0) return vvi;
        vector<int> preline(1,1);
        vvi.push_back(preline);
        vector<int> thisline;
        for(int i = 2; i <= numRows; ++i)
        {
            thisline.clear();
            thisline.push_back(1);
            for(int j = 0; j < preline.size()-1; ++j)
            {
                int next = preline[j] + preline[j+1];
                thisline.push_back(next);
            }
            thisline.push_back(1);
            vvi.push_back(thisline);
            preline = thisline;
        }
        return vvi;
    }
};
