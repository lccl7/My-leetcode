//First we should know what is the longest valid parentheses,
//it is a Continuous valid parentheses, e.g. (()) (4), ()(() (2)
//the simple way is to use a stack and a vector, which does not store '(' or ')'
//but the index of the string, so we can track them and calculate.
//The last is scan what we store in the vector to calculate the continuous 1

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if(n <= 1) return 0;
        
        stack<int> schar;
        vector<int> v(n, 0);
        int count = 0;
        int sum = 0;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '(')
            {
                schar.push(i);
            }
            else if (!schar.empty()) 
            {
                v[i] = 1;
                v[schar.top()] = 1;
                schar.pop();
            } 
        }
        for(int i = 0; i < n; ++i)
        {
            if(v[i] == 1)
            {
                count++;
                sum = max(sum, count);
            }
            else
            {
                count = 0;
            }
        }
        return sum;
    }
};
