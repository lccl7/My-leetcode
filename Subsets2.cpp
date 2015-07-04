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
        tmp.pop_back();
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

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> vvi;
        if(nums.empty()) return vvi;
        sort(nums.begin(), nums.end());
        vector<int> tmp(nums.size(), 0);
        print_subset(vvi, nums, tmp, 0);
        return vvi;
    }

private:
    void print_subset(vector<vector<int>>& vvi, vector<int>& nums, vector<int>& tmp, int cur)
    {
        if(cur == nums.size())
        {
            vector<int> v;
            for(int i = 0; i < cur; i++)
                if(tmp[i]) v.push_back(nums[i]);
            vvi.push_back(v);
            return;
        }
        tmp[cur] = 1;
        print_subset(vvi, nums, tmp, cur+1);
        tmp[cur] = 0;
        for(cur++; cur < nums.size(); cur++)
        {
            if(nums[cur] = nums[cur-1])
                tmp[cur] = 0;
            else break;
        }
        print_subset(vvi, nums, tmp, cur);
    }
};
