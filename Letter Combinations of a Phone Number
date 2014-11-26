//http://blog.csdn.net/u011095253/article/details/9158437
void dfs(vector<string> &res, string digits, string tmp, vector<string> &table)
{
    if(digits.length() == 0)
    {
        res.push_back(tmp); return;
    }
    for(int i = 0; i < table[digits[0]-'0'-1].length(); ++i)
    {
 //       tmp.push_back(table[digits[0]-'0'-1][i]);
        dfs(res, digits.substr(1), tmp+table[digits[0]-'0'-1][i], table);
//        tmp.pop_back();
    }
    
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string letter[9] = { "","abc","def","ghi","jkl","mno","pqrs","tuv", "wxyz"}; 
        vector<string> table(letter, letter+9);
        vector<string> res;
        string tmp;
        dfs(res, digits, "", table);
        return res;
    }
};
