class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_i = prices[0];
        int max_dif = 0;
        for(int i = 1; i < prices.size(); i++){
            max_dif = max(max_dif, prices[i]-min_i);
            min_i = min(prices[i],min_i);
        }
        return max_dif;
    }
};
