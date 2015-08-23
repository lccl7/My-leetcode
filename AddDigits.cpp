int addDigits(int num)
{
    int res = num;
    if(res < 10) return res;
    while(res > 9)
    {
        int sum = 0;
        while(res > 0)
        {
            sum += res % 10;
            res /= 10;
        }
        res = sum;
    }
    return res;
}

int addDigits(int num)
{
    if(num < 10) return num;
    int res = (num - 1) / 9;
    res = num - 9 * res;
    return res;
}
