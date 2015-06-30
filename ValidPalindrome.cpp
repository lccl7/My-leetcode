class Solution {
public:
    bool isPalindrome(string s) {
        string str = s;
        string s1, s2;
        string::iterator i = str.begin(), j = str.end();
        while(i != j)
        {
            if(isalnum(*i))
            {    if(isalpha(*i))
                    s1.push_back(tolower(*i));
                 else
                    s1.push_back(*i);
            }     
            i++;
        }
      //  if(s1.size() == 1) return true;
        reverse_copy(s1.begin(), s1.end(), back_inserter(s2));
        return s1 == s2;
    }
};
