class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int>& nums, vector<int> cur, unordered_set<int> vals){
        if(cur.size()== nums.size()){
            result.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!vals.contains(nums[i])){
                cur.push_back(nums[i]);
                vals.insert(nums[i]);
                dfs(nums,cur,vals);
                cur.pop_back();
                vals.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> temp;
        dfs(nums,{},temp);
        return result;
    }
};
