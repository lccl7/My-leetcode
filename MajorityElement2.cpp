class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int n1, n2, c1 = 0, c2 = 0;
        if(nums.size() <= 1) return nums;
        for(int i = 0; i < nums.size(); i++)
        {
            if(c1*c2 != 0)
            {
                if(nums[i] == n1)
                    c1++;
                else if(nums[i] == n2)
                    c2++;
                else
                {
                    c1--, c2--;
                }
            }
            else
            {
                if(c1 == 0 && nums[i] != n2)
                {
                    n1 = nums[i];
                    c1++;
                }
                else if(c2 == 0 && nums[i] != n1)
                {
                    n2 = nums[i];
                    c2++;
                }
                else
                {
                    if(nums[i] == n1)
                        c1++;
                    else
                        c2++;
                }
            }
        }
        int c3 = 0, c4 = 0;
        for(auto a: nums)
        {
            if(a == n1)
                c3++;
            if(a == n2)
                c4++;
        }
        if(c3*3 > nums.size())
            v.push_back(n1);
        if(n2 != n1 && c4*3 > nums.size())
            v.push_back(n2);
        return v;
    }
};
