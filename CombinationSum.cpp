//http://blog.csdn.net/u011095253/article/details/9158423
void dfs(vector<vector<int> > &res, vector<int> &cad, int target, vector<int>& tmp, int pos)
{
    if(target < 0) return;
    if(target == 0)
    {
        res.push_back(tmp); return;
    }
    for(int i = pos; i < cad.size() && cad[i] <= target; ++i)
    {
        tmp.push_back(cad[i]);
        dfs(res, cad, target - cad[i], tmp, i);
        tmp.pop_back();
    }
}

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(res, candidates, target, tmp, 0);
        return res;
    }
};
