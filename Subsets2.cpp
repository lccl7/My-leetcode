//Just the same as Subset
//Be careful that jump the duplicate element
//so add one more statement in line 12.
void dfs(vector<int> &S, vector<vector<int> > &res, vector<int> tmp, int pos)
{
    for(int i = pos; i < S.size(); ++i)
    {
        tmp.push_back(S[i]);
        res.push_back(tmp);
        dfs(S, res, tmp, i+1);
        tmp.erase(tmp.end()-1);
        while(i < S.size() && S[i] == S[i+1]) ++i;
    }
}

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> tmp;
        res.push_back(tmp);
        sort(S.begin(), S.end());
        dfs(S, res, tmp, 0);
        return res;
    }
};
