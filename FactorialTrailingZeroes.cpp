
// sum is used to record there are how many fives in the n.
//every five will have a zero, because two is many more than number of fives.
class Solution {
public:
    int trailingZeroes(int n) {
        long sum = 0;

        while(n /= 5)
        {
            sum += n;
        }

        return sum;
    }
};
