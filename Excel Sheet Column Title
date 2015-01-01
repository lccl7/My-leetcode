Given a positive integer, return its corresponding column title as appear in an Excel sheet.
class Solution {
public:
    string convertToTitle(int n) {
        string s;
        vector<int> v;
        int i = 0;
        int r;
        for(i = 0; pow(26, i) <= n; ++i)
        {
            v.push_back(pow(26, i));
        }
        
        for(int j = i-1; j >= 0 && n > 0; -- j)
        {
            r = n % (int)pow(26, j);
            n /= pow(26, j);
            if(r)
                s.append(1, r - 1 + 'A');
            else
            {
                s.append(j, 'Z');
                n --;
            }
        }
        
        return s;
    }
};
