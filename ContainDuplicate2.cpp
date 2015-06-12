bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    unordered_set<int> s;
    for(int i = 0; i < nums.size(); i++)
    {
        if(s.find(nums[i]) == s.end())
            s.insert(nums[i]);
        else {
            for(int j = i-1; j >= 0; j--)
            {
                if(nums[j] == nums[i] && i - j <= k)
                    return true;
            }
        }
    }
    return false;
}
