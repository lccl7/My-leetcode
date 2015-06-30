//Transval the whole vector and find the longest common prefix.
//First find the shortest string of the vector. Here we overload
//the function sort, and use a compare class cmp (be careful that 
// when I use just a function not a class, the program doesnot pass)
//or use a static function which begins with static.
// The we use strs[0] as the longest prefix, and then compare it with 
// all the remaining strings. Once some character is the same as the 
// strs[0], we truncated it as a new strs[0].
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string s;
        if(strs.empty()) return s;
        sort(strs.begin(), strs.end(), cmp);
        
        int n = strs.size();
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < strs[0].length(); ++j)
            {
                if(strs[i][j] != strs[0][j])
                    strs[0] = strs[0].substr(0, j);
            }
        }
        return strs[0];
    }
    
    struct 
    {
        bool operator() (string s1, string s2)
        {
            return s1.length() < s2.length();
        }
    } cmp;

    static bool operator() (string s1, string s2)
    {
        return s1.length() < s2.length();
    }
};
