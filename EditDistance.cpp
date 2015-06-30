int match(char a, char b)
{
    if(a == b)
        return 0;
    else
        return 1;
}

int indel(char c)
{
    return 1;
}

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int opt[3];
        int c[m+1][n+1];
        for(int i = 0; i <= m; ++i) c[i][0] = i;
        for(int j = 0; j <= n; ++j) c[0][j] = j;
        
        if(n == 0) return m;
        if(m == 0) return n;
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                opt[0] = c[i-1][j-1] + match(word1[i-1], word2[j-1]);
                opt[1] = c[i][j-1] + indel(word2[j]);
                opt[2] = c[i-1][j] + indel(word1[i-1]);
                c[i][j] = min(min(opt[0], opt[1]), opt[2]);
            }
        }
        return c[m][n];
    }
};
