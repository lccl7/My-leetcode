
// sum is used to record there are how many fives in the n.
//every five will have a zero, because two is many more than number of fives.
class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        int i = 5;
        
        while(i <= n)
        {
            sum += n/i;
            i *= 5;
        }
        
        return sum;
    }
};
