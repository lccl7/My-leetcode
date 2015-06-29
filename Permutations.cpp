//The same as Subset, this time we should pay attention that tmp is not a subset but a permutation
//so when tmp is the same size as the num, we can push_back
//another variable is visit which records whether we have push_back an element(true) or not (false)
void dfs(vector<int> &num, vector<vector<int> > &res, vector<int> tmp, vector<bool> &visit)
{
    if(tmp.size() == num.size())
    {
        res.push_back(tmp); return;
    }
    for(int i = 0; i < num.size(); ++i)
    {
        if(visit[i] == false)
        {
            tmp.push_back(num[i]);
            visit[i] = true;
            dfs(num, res, tmp, visit);
            tmp.pop_back();
            visit[i] = false;
        }
    }
}

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> tmp;
        vector<bool> visit(num.size(), false);
        dfs(num, res, tmp, visit);
        return res;
    }
};

//The second method using algorithm of next_permutation
//Pay attention that we should sort the original nums
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vvi;
        if(nums.empty()) return vvi;
        sort(nums.begin(), nums.end());
        permutation(vvi, nums);
        return vvi;
    }
    void permutation(vector<vector<int>>& vvi, vector<int>& nums)
    {
        do
        {
            vector<int> tmp;
            for(int i = 0; i < nums.size(); i++)
                tmp.push_back(nums[i]);
            vvi.push_back(tmp);
        }
        while(next_permutation(nums.begin(), nums.end()));
    }
};


//the third way to give a permutation
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vvi;
        if(nums.empty()) return vvi;
        sort(nums.begin(), nums.end());
        vector<int> v(nums.size(), 0);
        permutation(vvi, nums, v, 0);
        return vvi;
    }
    void permutation(vector<vector<int>>& vvi, vector<int>& nums, vector<int>& v, int cur)
    {
        if(cur == nums.size())
        {
            vector<int> tmp;
            for(int i = 0; i < nums.size(); i++)
                tmp.push_back(v[i]);
            vvi.push_back(tmp);
        }
        else
        for(int i = 0; i < nums.size(); i++)
        {
            bool flag = true;
            for(int j = 0; j < cur; j++)
                if(v[j] == i) flag = false;
            if(flag)
            {
                v[cur] = nums[i];
                permutation(vvi, nums, v, cur+1);
            }
        }
    }
};
