//
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        vector<int> vs(n1+n2, 0);
        int k = n1 + n2 - 2;
        for(int i = 0; i < n1; ++i)
            for(int j = 0; j < n2; ++j)
            {
                vs[k-i-j] += (num1[i] - '0')*(num2[j] - '0');
            }
        int carry = 0;
        for(int i = 0; i < n1+n2; ++i)  //Here we should pay attention that module operator comes last.
        {
            vs[i] += carry;
            carry = vs[i]/10;
            vs[i] %= 10;
        }
        int i = k+1;
        while(vs[i] == 0) --i;
        if(i < 0) return "0";
        string s;
        while(i >= 0)
            s.push_back(vs[i--] + '0');
        return s;
    }
};
