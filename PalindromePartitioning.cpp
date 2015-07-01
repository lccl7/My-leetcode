//every time we have a palindrome string, dfs begins with the remaining chars.
//there are many ways to implement function is_palindrome.
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        dfs(s, tmp, res);
        return res;
    }
    void dfs(string s, vector<string> tmp, vector<vector<string>> &res)
    {
        if(s.length() == 0)
        {
            process_string(tmp, res);
            return;
        }
        for(int i = 1; i <= s.length(); ++i)
        {
            string str = s.substr(0, i);
            if(is_palindrome(str))
            {
                tmp.push_back(str);
                dfs(s.substr(i), tmp, res);
                tmp.pop_back();
            }
        }
    }
    bool is_palindrome(string s)
    {
        int i = 0, j = s.length()-1;
        while(i < j)
        {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    void process_string(vector<string> tmp, vector<vector<string>> &res)
    {
        res.push_back(tmp);
    }
};
