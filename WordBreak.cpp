//build a vector<bool> to indicate whether there is segment frome 0 to current index, 
//no matter it is directly go to the current index s(0, i), or have segment between (0, i)
//use Dynamic programming we can say that f(0,n) = f(0, j) + f(j, i) + f(i, n)
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length();
        vector<bool> visit(len+1);
        visit[0] = true;
        for(int i = 1; i <= len; ++i)
            for(int j = 0; j < i; ++j)
            {
                string str = s.substr(j, i-j);
                if(visit[j] && dict.find(str) != dict.end())
                {
                    visit[i] = true;
                    break;
                }
            }
        return visit[len];
    }
};
