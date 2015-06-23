//Use a stack to track positive sign or negative sign
//Then we go over the string, give an order for each character
//If it is a number, pop a sign from the stack and calculate with the result
//If it is a right parentheses, remove a sign from the stack
//If anything else except a whitespace, we change the sign of the top of a stack depend whether
//the character is '-'.

int calculate(string s)
{
    int res = 0;
    int sign = 1;
    stack<int> signstack;
    signstack.push(1);
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
        if(s[i] >= '0'&& s[i] <= '9')
        {
            int num = 0;
            while(i < n && s[i] >= '0')
                num = num * 10 + str[i++] - '0';
            i--;
            num *= signstack.top();
            res += num;
        }
        else if(s[i] == ')')
            signstack.pop();
        else if(s[i] != ' ')
        {
            sign = s[i] == '-'? -1 : 1;
            signstack.push(sign);
        }
    }
    return res;
}
