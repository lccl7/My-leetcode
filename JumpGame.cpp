bool canJump(vector<int>& nums)
{
    if(nums.size() == 0) return true;
    int step = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        step--;
        if(step < 0) return false;
        if(step < nums[i])
            step = nums[i];
    }
    return true;
}

bool canJump(vector<int>& nums)
{
    if(nums.size() == 0) return true;
    int maxlength = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        if(maxlength >= i && (i + nums[i] >= nums.size()-1)
            return true;
        if(maxlength <= i && nums[i] == 0)
            return false;
        if(maxlength < nums[i] + i)
            maxlength = nums[i] + i;
    }
}
