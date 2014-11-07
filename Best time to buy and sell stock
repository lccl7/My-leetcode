local is the current best to buy and sell
gobal is the best of all the stock
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2)   return 0;
        int local = 0, gobal = 0;
        for(int i = 0; i < prices.size()-1; ++i)
        {
            local = max(local + prices[i+1] - prices[i], 0);
            gobal = max(local, gobal);
        }
        return gobal;
    }
};
