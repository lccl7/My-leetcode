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
