//http://www.cnblogs.com/TenosDoIt/p/3770126.html
//
class Solution {
public:
    string getPermutation(int n, int k) {
        string tmp = string("123456789").substr(0, n);
        string res(n, ' ');
        for(int i = 0; i < n; ++i)
            res[i] = dfs(tmp, k);
        return res;
    }
    char dfs(string &tmp, int &k)
    {
        int f = factorial(tmp.size()-1),
            i = (k-1)/f;
        char c = tmp[i];
        tmp.erase(i, 1);
        k -= i*f;
        return c;
    }
    int factorial(int n)
    {
        int result = 1;
        for(int i = 2; i <= n; ++i)
        {
            result *= i;
        }
        return result;
    }
};
