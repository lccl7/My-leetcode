class Solution {
public:
    int romanToInt(string s) {
        map<char, int> r2i;
        r2i['I'] = 1; r2i['V'] = 5;
        r2i['X'] = 10; r2i['L'] = 50;
        r2i['C'] = 100; r2i['D'] = 500;
        r2i['M'] = 1000;
        if(s.empty()) return 0;
        int sum = 0;
        for(int i = 0; i < s.length()-1; ++i)
        {
            if(r2i[s[i]] >= r2i[s[i+1]])
                sum += r2i[s[i]];
            else
                sum -= r2i[s[i]];
        }
        sum += r2i[s[s.length()-1]];
        return sum;
    }
};
