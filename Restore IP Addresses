//First of all we should know that an valid IP has 4 parts, every part is divided
// by dot ".", between which is a number no less than 0 and no more than 255. 
//so any string that is shorter than 4 and longer than 12 is invalid.
//the function solution gives when the string is a valid part of IP
//is_solution: if the first of the string is 0, then only "0" is valid,
//other number must be between 0 and 255.
//In dfs count is from 0 to 3, then we know the string s is divided into 4 parts,
//we can push_back into res.
//In every part there are no more than 3 chars is calculated.
//If the string is valid, we can continue to next step.
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.length() < 4 || s.length() > 12) return res;
        dfs(s, "", res, 0);
        return res;
    }
};
void dfs(string s, string tmp, vector<string> &res, int count)
{
    if(count == 3 && is_solution(s))
    {
        res.push_back(tmp+s); return;
    }
    for(int i = 1; i < 4 && i < s.length(); ++i)
    {
        string str = s.substr(0, i);
        if(is_solution(str))
            dfs(s.substr(i), tmp + str + ".", res, count+1);
    }
}

bool is_solution(string s)
{
    if(s[0] == '0') return s == "0";
    int num = atoi(s.c_str());
    return num<=255 && num > 0;
}
