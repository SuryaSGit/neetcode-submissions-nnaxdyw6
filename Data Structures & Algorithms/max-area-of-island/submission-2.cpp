class Solution {
public:
    int dfs(vector<vector<int>>& grid, int cur_row, int cur_col){
        grid[cur_row][cur_col]=0;
        int area = 1;
        if(cur_row > 0 && grid[cur_row-1][cur_col]==1){
            area = area + dfs(grid,cur_row - 1, cur_col);
        }
        if(cur_col > 0 && grid[cur_row][cur_col-1]==1){
            area = area + dfs(grid,cur_row, cur_col-1);
        }
        if(cur_row < grid.size()-1 && grid[cur_row+1][cur_col]==1){
            area = area + dfs(grid,cur_row + 1, cur_col);
        }
        if(cur_col < grid[0].size()-1 && grid[cur_row][cur_col+1]==1){
            area = area + dfs(grid,cur_row, cur_col+1);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int curmax = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[r].size(); c++){
                if(grid[r][c]==1){
                    curmax = max(curmax,dfs(grid,r,c));
                }
            }
        }
        return curmax;
    }
};
