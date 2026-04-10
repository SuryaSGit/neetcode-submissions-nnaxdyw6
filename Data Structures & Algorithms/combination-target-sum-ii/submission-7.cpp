class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int>& candidates, int target, vector<int> cur, int total, int i){
        if(total == target){
            result.push_back(cur);
            return;
        }
        if(total + candidates[i] > target){
            return;
        }
        for(int j = i; j < candidates.size(); j++){
            if(j > i && candidates[j] == candidates[j-1]){
                continue;
            }
            cur.push_back(candidates[j]);
            dfs(candidates,target,cur,total + candidates[j],j+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,{},0,0);
        return result;
    }
};
