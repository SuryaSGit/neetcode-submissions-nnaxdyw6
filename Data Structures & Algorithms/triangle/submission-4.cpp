class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int cols = triangle[rows-1].size();
        vector<vector<int>> memo(rows,vector<int>(cols, INT_MAX));
        //where memo[i][j] = cur_total for row i and pos j.
        int best = INT_MAX;
        dfs(triangle,memo,0,0,best,0);
        return best;
    }
    void dfs(vector<vector<int>>& triangle, vector<vector<int>>& memo, int row, int col, int& best, int cur_total){
        if(row == triangle.size()){
            best = min(best,cur_total);
            return;
        }
        if(cur_total >= memo[row][col]){
            return;
        }
        memo[row][col] = cur_total;
        cur_total = cur_total + triangle[row][col];
        dfs(triangle,memo,row+1,col,best,cur_total);
        dfs(triangle,memo,row+1,col+1,best,cur_total);
    }
};