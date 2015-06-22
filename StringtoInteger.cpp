int myAtoi(string str)
{
    long num = 0;
    int flag = 1;
    int n = str.length();
    int i = 0;
    while(i < n)
    {
        i = str.find_first_not_of(' ');
        if(str[i] == '-' || str[i] == '+')
        {
            flag = str[i] == '-'? -1 : 1;
            i++;
        }
        while(i < n && str[i] >= '0' && str[i] <= '9')
        {
            num = num * 10 + str[i++] - '0';
            if(num * flag >= INT_MAX) return INT_MAX;
            if(num * flag <= INT_MIN) return INT_MIN;
        }
        return num * flag;
    }
}
