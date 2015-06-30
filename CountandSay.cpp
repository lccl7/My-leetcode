// start is the begining, count records the number, so 
//once the next one is different from the privious, 
//count should turn back to 1.
class Solution {
public:
    string countAndSay(int n) {
        string s;
        if(n <= 0) return s;
        s = "1";
        int start = 1; //start from 1
        while(start < n)
        {
            string tmp;
            int count = 1; // the consecutive same number
            for(int j = 1; j < s.length(); ++j)
            {
                if(s[j] == s[j-1])
                    ++count;
                else
                {
                    tmp.push_back(count + '0');
                    tmp.push_back(s[j-1]);
                    count = 1;
                }
            }
            tmp.push_back(count + '0');
            tmp.push_back(s[s.length()-1]);
            s = tmp;
            ++start;
        }
        return s;
    }
};
