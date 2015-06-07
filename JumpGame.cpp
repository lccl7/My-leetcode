//minstep is the minimum step that reach the end
//maxlen is the distance that the position can reach at most
//tmp is the position that reaches farthest from now to the maxlen

int jump(vector<int> nums)
{
    int minstep = 0, maxlen = 0;
    int n = nums.size(), i = 0;
    if(n <= 1) return 0;
    while(i < n)
    {
        if(nums[i] > 0)
            minstep++;
        else
            return 0;
        int maxlen = nums[i]+i;
        if(maxlen > n-1) return minstep;
        int tmp = 0;
        for(int j = i+1; j <= maxlen; j++)
        {
            if(tmp <= nums[j]+j)
            {
                tmp = nums[j] + j;
                i = j;
            }
        }
    }
    return minstep;
}
