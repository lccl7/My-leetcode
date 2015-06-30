// we just pay attention that which parentheses are valid
//we initialize left and right with n, then when we add a left parentheses
//left is smaller by one, when left is smaller than right, we can add right ones.
void dfs(vector<string> &res, string tmp, int left, int right)
{
    if(left == 0 && right == 0)
    {
        res.push_back(tmp); return;
    }
    if(left > 0)
    {
        string ntmp = tmp + "(";
        dfs(res, ntmp, left-1, right);
        tmp = ntmp.substr(0, ntmp.length()-1);
    }
    if(left < right)
    {
        string ntmp = tmp + ")";
        dfs(res, ntmp, left, right-1);
        tmp = ntmp.substr(0, ntmp.length()-1);
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n <= 0) return res;
        string tmp;
        dfs(res, "", n, n);
        return res;
    }
};
