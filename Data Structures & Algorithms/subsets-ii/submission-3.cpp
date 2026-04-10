class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int>& nums, vector<int> cur, int i){
        if(i >= nums.size()){
            result.push_back(cur);
            return;
        }          
        cur.push_back(nums[i]);
        dfs(nums,cur,i+1);
        cur.pop_back();
        while(nums[i+1]==nums[i]){
            i++;
        }
        dfs(nums,cur,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,{},0);
        return result;
    }
};
