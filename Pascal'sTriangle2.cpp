class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(1,1);
        if(rowIndex == 0) return v; 
        vector<int> pre(1,1);
        vector<int> next;
        for(int i = 1; i <= rowIndex; ++i)
        {
            next.clear();
            next.push_back(1);
            for(int j = 0; j < pre.size()-1; ++j)
            {
                int n = pre[j] + pre[j+1];
                next.push_back(n);
            }
            next.push_back(1);
            pre = next;
        }
        return next;
    }
};
