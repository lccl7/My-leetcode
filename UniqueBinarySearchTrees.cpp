class Solution {
public:
    int numTrees(int n) {
        if(n == 0 || n == 1) return 1;
        vector<int> v(n+1, 0);
        v[0] = v[1] = 1;
        for(int i = 2; i <= n; ++i)
            for(int j = 0; j < i; ++j)
                //左子树个数j, 右子树个数i-j-1
                v[i] += v[j] * v[(i-1)-j];
        return v[n];
    }
};
