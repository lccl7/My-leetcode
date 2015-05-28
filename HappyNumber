//use a set to find whether a number has been
//calculate to prevent a infinite loop 
// if a number is not a happy number.

bool isHappy(int n)
{
    set<int> s;
    while(true)
    {
        if(n == 1)
            return true;
        else if(!s.count(n))
        {
            s.insert(n);
            n = calculate(n);
        }
            else
                return false;
    }
}

int calculate(int n)
{
    int sum = 0;
    while(n)
    {
        sum += (n%10)*(n%10);
        n /= 10;
    }
    return sum;
}
