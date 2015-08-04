class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        if(n == 1) return;
        for(int i = n-2, j = n-1; i >= 0; --i, --j)
        {
            if(num[i] < num[j])
            {
                int k = n-1;
                while(num[k] <= num[i]) --k;
                swap(num[i], num[k]);
                reverse(num.begin()+j, num.end());
                return;
            }
        }
        reverse(num.begin(), num.end());
    }
};

//From WiKi
void nextPermutation(vector<int>& nums)
{
    int k = -1, l = 0;
    for(int i = nums.size()-2; i >= 0; i--)
    {
        if(nums[i] < nums[i+1])
        {
            k = i;
            break;
        }
    }
    if(k == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    for(int i = nums.size(); i >= 0; i--)
        if(nums[i] > nums[k])
        {
            l = i;
            break;
        }
    swap(nums[k], nums[i]);
    reverse(nums.begin()+k+1, nums.end());
}
