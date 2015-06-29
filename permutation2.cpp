//This time may have duplicate elements so we should sort first so that the same element can get together
//Another is that jump element that are equal( line 18).
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
            while(i < num.size()-1 && num[i] == num[i+1]) i++;
        }
    }
}

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> tmp;
        vector<bool> visit(num.size(), false);
        sort(num.begin(), num.end());
        dfs(num, res, tmp, visit);
        return res;
    }
};

//The second method 
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
        if(!i || nums[i] != nums[i-1])
        {
            int c1 = 0, c2 = 0;
            for(int j = 0; j < cur; j++)            if(v[j] == nums[i]) c1++;
            for(int j = 0; j < nums.size(); j++) if(nums[j] == nums[i]) c2++;
            if(c1 < c2)
            {
                v[cur] = nums[i];
                permutation(vvi, nums, v, cur+1);
            }
        }
    }
};
