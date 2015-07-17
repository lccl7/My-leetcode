vector<int> productExceptSelf(vector<int>& nums)
{
    int n = nums.size(), r = 1;
    vector<int> res(n);
    for(int i = 0; i < n; i++)
        res[i] = res[i-1] * nums[i-1];
    for(int i = n-2; i >= 0; i--)
    {
        r *= nums[i+1];
        res[i] *= r;
    }
    return res;
}
