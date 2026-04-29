class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> hasCoin(prices.size() + 2);
        vector<int> noCoin(prices.size() + 2);
        for(int i = prices.size() -1; i >= 0; i--){
            noCoin[i] = max(0, hasCoin[i+1]-prices[i]);
            noCoin[i] = max(noCoin[i],noCoin[i+1]);
            hasCoin[i] = max(hasCoin[i+1], prices[i] + noCoin[i + 2]);
        }
        return noCoin[0];
    }
};
