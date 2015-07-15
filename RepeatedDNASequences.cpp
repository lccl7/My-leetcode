class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> vs;
        if(s.length() < 10) return vs;
        int mask = 0x7ffffff;
        unordered_map<int, int> m;
        int cur = 0, i = 0;
        while(i < 9)
            cur = (cur << 3) | (s[i++] & 7);
        while(i < s.size())
        {
            cur = ((cur & mask) << 3) | (s[i++] & 7);
            if(m.count(cur))
            {
                if(m[cur] == 1)
                    vs.push_back(s.substr(i - 10, 10));
                ++m[cur];
            }
            else
            {
                m[cur] = 1;
            }
        }
        return vs;
    }
};
