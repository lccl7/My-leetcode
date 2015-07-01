//bool vb[n][n] cannot be substituted by vector<vector<bool>> why?
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;
        int n = s.length();
        bool vb[n][n];
        int maxlen = 0;
        int start = 0;
//pair<int, int> res = make_pair(0, 0);
        for(int k = 0; k < n; ++k)
        {
            for(int i = 0; i < n-k; ++i)
            {
                if (k == 0 || k == 1)
                   vb[i][i+k] = s[i] == s[i+k];
                else
                    vb[i][i+k] = (s[i] == s[i+k]) ? vb[i+1][i+k-1] : false;
                if(vb[i][i+k] && k + 1 > maxlen)
//              if(vb[i][i+k] && k + 1 > res.second)
                {
                    maxlen = k + 1;
                    start = i; 
//res = make_pair(i, k+1);
                }
            }
        }
        return s.substr(start, maxlen);
        //return s.substr(res.first, res.second);
    }
};
