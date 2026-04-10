class Solution {
public:
    vector<vector<int>> res;
    void dfs(int j, vector<int>& nums, int target, vector<int> cur, int total){
        if(total == target){
            res.push_back(cur);
            return;
        }
        for(int i = j; i < nums.size(); i++){
            if(total + nums[i] > target){
                return;
            }
            cur.push_back(nums[i]);
            dfs(i,nums,target,cur,total + nums[i]);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        dfs(0,nums,target,{},0);
        return res;
    }
};
