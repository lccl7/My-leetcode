Given an array of strings, return all groups of strings that are anagrams.
Note: All inputs will be in lower-case.
For example:
Input:　　["tea","and","ate","eat","den"]
Output:   ["tea","ate","eat"]
Interface: vector<string>anagrams(vector<string>&strs);

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        if(strs.size() <= 1)  return res;
        map<string, int> maptmp;
        int n = strs.size();
        for(int i = 0; i < n; ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if(maptmp.end() == maptmp.find(s))
                maptmp.insert(make_pair(s, i));
            else
            if(maptmp[s] != -1)
            {
                res.push_back(strs[maptmp[s]]);
                maptmp[s] = -1;
                res.push_back(strs[i]);
            }
            else
            {
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};
