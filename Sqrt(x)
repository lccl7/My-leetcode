class Solution {
public:
    int sqrt(int x) {
        double low = 0, high = x;
        double y = (low + high)/2;
        while(abs(y*y - x) > 1e-6)
        {
            if(y*y - x > 0)
            {
                high = y;
                y = (low + high) / 2;
            }
            else
            {
                low = y;
                y = (low + high) / 2;
            }
        }
        if(y < 1 && abs(y-1) < 1e-3) return 1;
        return int(y);
    }
};
