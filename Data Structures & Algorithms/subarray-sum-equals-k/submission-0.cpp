class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefix_sums;
        prefix_sums[0] = 1;
        int res=0;
        int cur_sum = 0;
        for(int cur : nums){
            cur_sum+=cur;
            res = res + prefix_sums[cur_sum-k];
            prefix_sums[cur_sum]++;
        }
        return res;
    }
};