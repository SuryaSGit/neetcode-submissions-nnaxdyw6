class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
    void dfs(int cur_x, int cur_y, vector<vector<char>>& grid){
        grid[cur_x][cur_y] = '0';
        if(cur_x > 0 && grid[cur_x-1][cur_y]=='1'){
            dfs(cur_x-1,cur_y,grid);
        }
        if(cur_y > 0 && grid[cur_x][cur_y-1]=='1'){
            dfs(cur_x,cur_y-1,grid);
        }
        if(cur_x < grid.size()-1 && grid[cur_x+1][cur_y]=='1'){
            dfs(cur_x+1,cur_y,grid);
        }
        if(cur_y < grid[0].size()-1 && grid[cur_x][cur_y+1]=='1'){
            dfs(cur_x,cur_y+1,grid);
        }
    }
};
