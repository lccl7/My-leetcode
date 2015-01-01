class Solution {
public:
    int reverse(int x) {
        if (x == 0)
            return x;
        if(x > 0)
        {
            vector<int> v;
            while(x%10 == 0)
                x /= 10;
            while(x)
            {
                v.push_back(x%10);
                x = x/10;
            }
            vector<int>::size_type i = 0;
           // while(v[i] == 0 && i != v.size()) i++;
            int result = 0;
            for(; i != v.size(); i++)
            {
                    result = result*10 + v[i];
            }
            return result;
        }
        if(x < 0)
        {
            vector<int> v;
            x = abs(x);
            while(x%10 == 0)
                x /= 10;
            while(x)
            {
                v.push_back(x%10);
                x = x/10;
            }
            vector<int>::size_type i = 0;
           // while(v[i] == 0 && i != v.size()) i++;
            int result = 0;
            for(; i != v.size(); i++)
            {
                    result = result*10 + v[i];
            }
            return result*(-1);
            
        }
        
    }
};
