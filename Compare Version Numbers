//I just give some example (be careful!):
//01 = 1, 1.0 = 1, 1.1 < 1.10, 0.1 > 0.0.1, 1.1.0 = 1.1
class Solution {
public:
    int compareVersion(string version1, string version2) {
        long a = 0, b = 0;
        int n1 = version1.size(), n2 = version2.size();
        int i=0, j=0;
        while(i < n1 || j < n2)
        {
            a = 0, b = 0;
            while(version1[i] != '.' && i < n1)
            {
                a = a*10 + version1[i]-'0';
                ++i;
            }
            while(version2[j] != '.' && j < n2)
            {
                b = b*10 + version2[j]-'0';
                ++j;
            }
            if(a > b) return 1;
            if(a < b) return -1;
            ++i; 
            ++j;
        }
        return 0;
    }
};
