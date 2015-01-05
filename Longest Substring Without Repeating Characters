//use hash table
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1) return s.length();
        vector<int> hash(256, -1);
        int start = 0, end = 0, res = 1;
        int n = s.length();
        hash[s[end]] = 0;
        while(++end < n)
        {
            if(hash[s[end]] >= start)
                start = hash[s[end]] + 1;
            hash[s[end]] = end;
            res = max(end - start + 1, res);
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1) return s.length();
        vector<bool> visit(256, false);
        int start = 0, end = 0, res = 0;
        int n = s.length();
        while(end < n && start + res < n)
        {
            if(!visit[s[end]])
                visit[s[end++]] = true;
            else
                visit[s[start++]] = false;
            res = max(end - start, res);
        }
        return res;
    }
};
