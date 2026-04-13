class Solution {
public:
    void bfs(vector<vector<int>>& grid, int row, int col){
        queue<pair<int,int>> to_fill;
        to_fill.push({row,col});
        while(!to_fill.empty()){
            row = to_fill.front().first;
            col = to_fill.front().second;
            to_fill.pop();
            if(row > 0 && grid[row-1][col] > 0){
                if(grid[row-1][col] == 1){
                    grid[row-1][col]=grid[row][col]+1;
                    to_fill.push({row-1,col});
                }
                else if(1 + grid[row][col] < grid[row-1][col]){
                    grid[row-1][col] = 1 + grid[row][col];
                    to_fill.push({row-1,col});
                }
            }
            if(col > 0 && grid[row][col-1] > 0){
                if(grid[row][col-1] == 1){
                    grid[row][col-1]=grid[row][col]+1;
                    to_fill.push({row,col-1});
                }
                else if(1 + grid[row][col] < grid[row][col-1]){
                    grid[row][col-1] = 1 + grid[row][col];
                    to_fill.push({row,col-1});
                }
            }
            if(row < grid.size()-1 && grid[row+1][col] > 0){
                if(grid[row+1][col] == 1){
                    grid[row+1][col]=grid[row][col]+1;
                    to_fill.push({row+1,col});
                }
                else if(1 + grid[row][col] < grid[row+1][col]){
                    grid[row+1][col] = 1 + grid[row][col];
                    to_fill.push({row+1,col});
                }
            }
            if(col < grid[0].size()-1 && grid[row][col+1] > 0){
                if(grid[row][col+1] == 1){
                    grid[row][col+1]=grid[row][col]+1;
                    to_fill.push({row,col+1});
                }
                else if(1 + grid[row][col] < grid[row][col+1]){
                    grid[row][col+1] = 1 + grid[row][col];
                    to_fill.push({row,col+1});
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]==2){
                    bfs(grid,i,j);
                }
            }
        }
        int curmax = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                curmax = max(curmax,grid[i][j]);
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        if(curmax==0){
            return 0;
        }
        return curmax-2;
    }
};
