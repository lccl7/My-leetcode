http://blog.csdn.net/u011095253/article/details/9158397
//tmp is a null set at first, we can just push it into res.
//sort can make all element at a non-descending order.
//dfs is a recursive way to push_back subset in res. Be careful that res is reference.
//the integer pos remember where we begin to push_back elements in tmp
//after this level we should erase the element we just push_back
void dfs(vector<int> &S, vector<vector<int> > &res, vector<int> tmp, int pos)
{
    for(int i = pos; i < S.size(); ++i)
    {
        tmp.push_back(S[i]);
        res.push_back(tmp);
        dfs(S, res, tmp, i+1);
        tmp.erase(tmp.end()-1);
    }
}

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> tmp;
        res.push_back(tmp);
        sort(S.begin(), S.end());
        dfs(S, res, tmp, 0);
        return res;
    }
};

//second way
vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> vvi;
    if(nums.empty()) return vvi;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < (1 << nums.size()); i++)
        print_subset(vvi, nums, i);
    return vvi;
}

void print_subset(vector<vector<int>>& vvi, vector<int>& nums, int cur)
{
    vector<int> tmp;
    for(int i = 0; i < nums.size(); i++)
        if(cur & (1 << i))
            tmp.push_back(nums[i]);
    return vvi;
}

//third way, use a vector to indicate whether the index cur is in
vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> vvi;
    if(nums.empty()) return vvi;
    sort(nums.begin(), nums.end());
    vector<int> v(nums,size(), 1);
    print_subset(vvi, v, nums, 0);
    return vvi;
}

void print_subset(vector<vector<int>&, vvi, vector<int>& v, vector<int>& nums, cur)
{
    vector<int> tmp;
    if(cur == nums.size())
    {
        for(int i = 0; i < nums.size(); i++)
            if(v[i]) tmp.push_back(nums[i]);
        vvi.push_back(tmp);
        return;
    }
    v[cur] = 1;
    print_subset(vvi, v, nums, cur+1);
    v[cur] = 0;
    print_subset(vvi, v, nums, cur+1);
}
