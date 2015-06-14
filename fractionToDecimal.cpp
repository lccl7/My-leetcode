//One caution: numerator and denominator should be transformed
//to long long type, or the result may be wrong,
//for example numerator = -1, denominator = -2147483648
//Output is "0.00000000000",
//the expected is "0.000000004656612873077392578125"
string fractionToDecimal(int numerator, int denominator)
{
    long long n = numerator, d = denominator;
    if(numerator == 0) return "0";
    bool b1 = n < 0, b2 = d < 0;
    if(b1) n *= -1;
    if(b2) n *= -1;
    string s = "";
    if(b1^b2) s += "-";

    long long q = n/d, r = n/d;
    result += to_string(q);
    if(r == 0) return s;
    n = r;
    unordered_map<long long, int> remain;
    remain[n] = s.size();
    n *= 10;
    result += ".";
    remain[n] = s.size();

    while(n)
    {
        if(n < d)
        {
            n *= 10;
            s += "0";
            remain[n] = s.size();
        }
        if(n > d)
        {
            s += to_string(n/d);
            n %= d;
            n *= 10;
            if(remain.find(n) == remain.end())
                remain[n] = s.size();
            else {
                s = s.substr(0, remain[n]) + "("+s.substr(remain[n], string::npos) + ")";
                break;
            }
        }
    }
    return s;
}
