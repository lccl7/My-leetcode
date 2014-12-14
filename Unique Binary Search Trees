class Solution {
public:
    int numTrees(int n) {
        if(n == 0 || n == 1) return 1;
        vector<int> vi(n+1, 0);
        vi[0] = 1;
        for(int i = 1; i <= n; ++i)
            for(int j = 0; j <= i-1; ++j)
                vi[i] += vi[j] * vi[(i-1)-j];
        return vi[n];
    }
};
