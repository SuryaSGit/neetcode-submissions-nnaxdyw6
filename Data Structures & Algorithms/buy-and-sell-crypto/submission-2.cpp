class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int res = 0;
        for(int cur : prices){
            min_price = min(min_price,cur);
            res = max(res,cur-min_price);
        }
        return res;
    }
};
