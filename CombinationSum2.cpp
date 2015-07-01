void dfs(vector<vector<int> > &res, vector<int> &num, int target, vector<int> tmp, int pos)
{
    if(target == 0)
    {
        res.push_back(tmp); return;
    }
    for(int i = pos; i < num.size() && target >= num[i]; ++i)
    {
        tmp.push_back(num[i]);
        dfs(res, num, target - num[i], tmp, i+1);
        tmp.pop_back();
        while(i < num.size()-1 && num[i] == num[i+1]) ++i;
    }
}

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        vector<int> tmp;
        sort(num.begin(), num.end());
        dfs(res, num, target, tmp, 0);
        return res;
    }
};
