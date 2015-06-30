first to handle the trivial: if m < 1 and n < 1 then return 0, if m == 1 or n == 1 then return 1;
next we define two vector for update.
vi1 is the latest, and vi2 is used to update and copy to vi1.
we define mxn is the sum of the (m-1)xn and mx(n-1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m < 1 && n < 1) return 0;
        if(m == 1) return 1;
        if(n == 1) return 1;
        vector<int> vi1(n, 1);
        vector<int> vi2(n, 0);
        for(int i = 1; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(j == 0) vi2[j] = 1;
                else
                    vi2[j] = vi2[j-1] + vi1[j];
            }
            vi1 = vi2;
        }
        return vi1[n-1];
    }
};
