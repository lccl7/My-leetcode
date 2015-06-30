class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1)
            return s;
        vector<string> vs(nRows, "");
        
        int n = s.length();
        int curR = 0;
        bool flagR = true;
        for(int i = 0; i < n; ++i)
        {
            vs[curR] += s[i];
            if(curR == 0)
                flagR = true;
            if(curR == nRows-1)
                flagR = false;
            if(flagR)
                ++curR;
            else
                --curR;
        }
        
        string res;
        for(int j = 0; j < nRows; ++j)
            res += vs[j];
        return res;
    }
};
