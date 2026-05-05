class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(),gas.end(),0) < accumulate(cost.begin(),cost.end(),0)){
            return -1;
        }
        int cur_gas = 0;
        int res = 0;
        for(int i = 0; i < gas.size(); i++){
            cur_gas = cur_gas + gas[i] - cost[i];
            if(cur_gas < 0){
                res = i + 1;
                cur_gas = 0;
            }
        }
        return res;
    }
};
