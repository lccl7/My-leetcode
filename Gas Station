class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if(gas.empty() || cost.empty() || gas.size() != cost.size())
            return -1;
        int index = -1;
        int sum = 0, total = 0;
        int n = gas.size();
        for(int i = 0; i < n; ++i)
        {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            
            if(sum < 0)
            {
                index = i;
                sum = 0;
            }
        }
        
        return total >= 0 ? index+1 : -1;
    }
};
