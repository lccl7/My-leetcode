void rotate(vector<int>& nums, int k)
{
    k %= nums.size();
    if( k == 0) return;
    vector<int> res1, res2;
    for(itn i = 0; i < nums.size(); i++)
    {
        if(i < nums.size()-k)
            res1.push(nums[i]);
        else {
            res2.push(nums[i])l
        }
    }

    for(int i = 0; i < nums.size(); i++)
        if(i < k)
            nums[i] = res2[i];
        else {
            nums[i] = res1[i-k];
        }
}
