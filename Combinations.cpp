void dfs(vector<vector<int> > &res, vector<int> &tmp, int n, int k, int pos)
{
    if(k == 0)
    {
        res.push_back(tmp); return;
    }
    for(int i = pos; i <= n-k+1; ++i)
    {
        tmp.push_back(i);
        dfs(res, tmp, n, k-1, i+1);
        tmp.pop_back();
    }
}

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, tmp, n, k, 1);
        return res;
    }
};

void dfs(vector<vector<int> > &res, vector<int> &tmp, int n, int k, int pos)
{
    if(k == tmp.size())
    {
        res.push_back(tmp); return;
    }
    if(k < tmp.size()) return;
    for(int i = pos; i <= n; ++i)
    {
        tmp.push_back(i);
        dfs(res, tmp, n, k, i+1);
        tmp.pop_back();
    }
}
