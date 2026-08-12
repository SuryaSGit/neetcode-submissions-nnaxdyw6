class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& cur, int cur_pos, int n, int k){
        if(cur_pos > n){
            if(cur.size() == k){
                res.push_back(cur);
            }
            return;
        }
        cur.push_back(cur_pos);
        dfs(res,cur,cur_pos+1,n,k);
        cur.pop_back();
        dfs(res,cur,cur_pos+1,n,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(res,temp,1,n,k);
        return res;
    }
};