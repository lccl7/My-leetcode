class Solution {
public:
    int divide(int dividend, int divisor) {
        long long d1 = abs((long long)dividend);
        long long d2 = abs((long long)divisor);
        long res = 0;
        
        if(d2 == 1)
        {
            if((dividend > 0 && divisor > 0))
                return d1;
            else if(dividend < 0 && divisor < 0 && dividend != divisor)
                return d1 - 1;
            else if(dividend > 0 && divisor < 0)
                return -d1;
        }
        
        while(d1 >= d2)
        {
            long long a = d2;
            long long m = 1;
            while((a << 1) < d1)
            {
                m <<= 1;
                a <<= 1;
            }
            res += m;
            d1 -= a;
        }
        if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
            return res;
        return -res;
    }
    
};
