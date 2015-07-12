bool isNumber(string s)
{
    int i = 0;
    while(isspace(s[i])) i++;
    if(s[i] == '+' || s[i] == '-') i++;
    int digitc = 0, pointc = 0;
    while(isdigit(s[i]) || s[i] == '.')
        s[i++] == '.' ? pointc++ : digitc++;
    if(pointc > 1 || digitc < 1) return false;
    if(s[i] == 'e')
    {
        i++;
        if(s[i] == '+' || s[i] == '-') i++;
        digitc = 0;
        while(isdigit(s[i]))
        {
            digitc++;
            i++;
        }
        if(digitc < 1) return false;
    }
    while(isspace(s[i])) i++;
    return i == s.length();
}
