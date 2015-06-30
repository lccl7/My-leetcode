//num[i][j] represents that how many methods can from S[0...i] to T[0...j] by
//deleting several chars. First initialize num[i][0] = 1;
//If S[i] equals T[j], then num[i][j] = num[i-1][j-1] + num[i-1][j];
//else num[i][j] = num[i-1][j];
class Solution {
public:
    int numDistinct(string S, string T) {
        if(S.empty()) return 0;
        if(T.empty()) return 1;
        int lens = S.length(), lent = T.length();
        vector<vector<int>> num(lens+1, vector<int>(lent+1, 0));
        for(int i = 0; i <= lens; ++i)  num[i][0] = 1;
        for(int i = 1; i <= lens; ++i)
            for(int j = 1; j <= lent; ++j)
            {
                if(S[i-1] == T[j-1]) 
                    num[i][j] = num[i-1][j-1] + num[i-1][j];
                else
                    num[i][j] = num[i-1][j];
            }
        return num[lens][lent];
    }
};
