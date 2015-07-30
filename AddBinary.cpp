//The first solution firstly ensures a and b have the same bits,
//then add them together, sum divide into two results (<2) or (2,3)
//if the last carry is 1, we should add one more bit to the result.
//The second solution is just like the first one, where the different
//is that we don't need to ensure they have the same bits. We just need
//to add a if statement when we add the sum.
class Solution {
public:
    string addBinary(string a, string b) {
        int x = a.length(), y = b.length();
        if(x > y)
        for(int i = 0; i < x-y; ++i)
        {
            b.insert(0, "0");
        }
        else
        for(int i = 0; i < y-x; ++i)
        {
            a.insert(0, "0");
        }
        string s(a.length(), '0');
        int carry = 0;
        for(int i = a.length() - 1; i >= 0; --i)
        {
            int sum = (a[i]-'0') + (b[i]-'0') + carry;
            if(sum < 2)
            {
                s[i] = sum + '0';
                carry = 0;
            }
            else
            {
                s[i] = sum%2 + '0';
                carry = 1;
            }
        }
        if(carry == 1)
            s.insert(0, "1");
        return s;
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        int x = a.length()-1, y = b.length()-1;
        int m = max(a.length(), b.length());
        string s(m, '0');
        int k = m-1;
        int carry = 0;
        while(x >= 0 || y >= 0)
        {
            int sum = carry;
            if(x >= 0)
                sum += (a[x--]-'0');
            if(y >= 0)
                sum += (b[y--]-'0');
            if(sum < 2)
            {
                s[k--] = sum + '0';
                carry = 0;
            }
            else
            {
                s[k--] = sum%2 + '0';
                carry = 1;
            }
        }
        if(carry == 1)
            s.insert(0, "1");
        return s;
    }
};
