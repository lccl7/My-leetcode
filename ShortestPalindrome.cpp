class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        vector<int> p(t.size(), 0);
        for (int i = 1; i < t.size(); ++i) {
            int j = p[i - 1];
            while (j > 0 && t[i] != t[j]) j = p[j - 1];
            p[i] = (j += t[i] == t[j]);
        }
        return r.substr(0, s.size() - p[t.size() - 1]) + s;
    }
};

class Solution {
public:
    string shortestPalindrome(string s) {
        string s2(s);
        reverse(s2.begin(), s2.end());
        int l;
        for(l = s.size(); l >= 0; l--)
        {
            if(s2.substr(s.size()-l) == s.substr(0, l))
                break;
        }
        return s2.substr(0, s2.size()-l) + s;
    }
};
