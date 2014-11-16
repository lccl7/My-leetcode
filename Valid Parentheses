class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        stack<char> sch;
        for(int i = 0; i < s.length(); i++)
        {
            switch(s[i])
            {
                case '[':
                case '{':
                case '(':
                    sch.push(s[i]);
                    break;
                case ']':
                    {
                        if(!sch.empty() && sch.top() == '[')
                        {
                            sch.pop();break;
                        }
                        else
                            return false;
                    }
                case '}':
                    {
                        if(!sch.empty() && sch.top() == '{')
                        {
                            sch.pop();break;
                        }
                        else
                            return false;
                    }
                case ')':
                    {
                        if(!sch.empty() && sch.top() == '(')
                        {
                            sch.pop();break;
                        }
                        else
                            return false;
                    }
            }
        }
        if(sch.empty()) return true;
        else return false;
    }
};
