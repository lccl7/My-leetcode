class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length();
        vector<int> v(n, 0);  
        for(int j = 0; j < n; ++j)
        {
            v[j] = pow(26, j);
        }
        int sum = 0;
        for(int i = 0, j = n - 1; i < n; ++i, -- j)
        {
            sum += (s[i] - 'A' + 1)*v[j];
        }
        return sum;
    }
};
