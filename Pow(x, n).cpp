//We should pay attention to two details.
//The first thing is to use recursive method: it may exceed time limit.
//The second is that n is not known whether it is positive or negative.
//Based on the iterative the solution is as follows.
class Solution {
public:
    double pow(double x, int n) {
        if(n == 0) return 1.0;
        if(n == 1) return x;
        double temp = pow(x, abs(n/2));
        if(abs(n)%2 == 0)
        {
            if(n > 0)
                return temp*temp;
            else
                return 1.0/(temp*temp);
        }
        if(abs(n)%2 == 1)
        {
            if(n > 0)
                return temp*temp*x;
            else
                return 1/(x*temp*temp);
        }
    }
};
