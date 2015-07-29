class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int dis = INT_MAX, res = 0;

        for(int i = 0; i < nums.size() - 2; i++)
        {
            int start = i+1, end = nums.size()-1;
            while(start < end)
            {
                sum = nums[i] + nums[start] + nums[end];
                if(sum == target)
                    return target;
                else if(sum < target)
                {
                    if(dis > target - sum)
                    {
                        dis = target - sum;
                        res = sum;
                    }
                    start++;
                }
                else {
                    if(dis > sum - target)
                    {
                        dis = sum - target;
                        res = sum;
                    }
                    end--;
                }
            }
        }
        return res;
    }
}
