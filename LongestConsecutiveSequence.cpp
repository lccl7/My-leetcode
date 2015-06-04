//建立一个集合存储所有数据
//在集合中寻找连续的数据
//达到在O(n)的复杂度

int longestConsecutive(vector<int>& nums)
{
    set<int> numset;
    for(int i = 0; i < nums.size(); i++)
    {
        numset.insert(nums[i]);
    }
    int maxcount = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(numset.find(nums[i]) != numset.end())
        {
            int count = 1;
            int n = nums[i]+1;
            while(numset.find(n) != numset.end())
            {
                numset.erase(n);
                count++;
                n++;
            }
            n = nums[i]-1;
            while(numset.find(n) != numset.end())
            {
                numset.erase(n);
                count++;
                n--;
            }
            if(count > maxcount)
                maxcount = count;
        }
    }
    return maxcount;
}
