class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string str = s;
        if(str.size() == 0) return 0;
       // if(str.size() == 1 && !isspace(str[0])) return 1;
        string::size_type i = 0, j = str.size()-1;
        while(j != 0 && isspace(str[j])) j--;
       // while(i != str.size()-1 && isspace(str[i])) i++;
      //  if(i <= j )
       // {
            i = j;
            while(i != 0 && !isspace(s[i])) i--;
            if(i == 0 && !isspace(s[i]))
                return j - i + 1;
            else
                return j - i;
       // }
        //else if(isspace(str[i]))
          //      return 0;
        //    else
          //      return 1;
    }
};
