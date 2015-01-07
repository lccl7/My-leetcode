//Another method KMP which is not shown here.
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int length1 = strlen(haystack);
        int length2 = strlen(needle);
        if(haystack == NULL || needle == NULL || length1 < length2)
            return -1;
        if(length2 == 0)
            return 0;
        
        int i = 0, j = 0;
        while(i <= length1 - length2)
        {
            j = 0; 
            int index = i;
            
            while(j < length2 && haystack[index] == needle[j])
            {
                index++;
                j++;
            }
            if(j == length2)
                return i;
                
            ++i;
        }
        return -1;
    }
};
