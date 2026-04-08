class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> vals;
        for(int i = 0; i < nums.size(); i++){
            vals.push(nums[i]);
            if(vals.size()>k){
                vals.pop();
            }
        }
        return vals.top();
    }
};
