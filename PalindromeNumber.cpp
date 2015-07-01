//The program think negative number as not Palindrome.
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int y = x;
        int res = 0;
        while(x > 0)
        {
            int num = x % 10;
            res = res*10 + num; 
            x /= 10;
        }
        if(res == y) return true;
        else return false;
    }
};
