int findMin(vector<int>& nums)
{
    int lo = 0, high = nums.size()-1, mid = 0;
    while(lo < high)
    {
        mid = lo + (high - lo)/2;
        if(nums[mid] > nums[high])
            lo = mid + 1;
        else if(nums[mid] > nums[high])
            high = mid;
        else high--;
    }
    return nums[lo];
}
