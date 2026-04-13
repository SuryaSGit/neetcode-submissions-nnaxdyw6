class Solution {
public:
    void bfs(vector<vector<int>>& grid, int row, int col){
        queue<pair<int,int>> to_fill;
        to_fill.push({row,col});
        while(!to_fill.empty()){
            pair<int,int> cur = to_fill.front();
            to_fill.pop();
            if(cur.first > 0 && grid[cur.first-1][cur.second] > 0){
                if(1+grid[cur.first][cur.second]<grid[cur.first-1][cur.second]){
                    grid[cur.first-1][cur.second] = 1 + grid[cur.first][cur.second];
                    to_fill.push({cur.first-1,cur.second});
                }
            }
            if(cur.second > 0 && grid[cur.first][cur.second-1] > 0){
                if(1+grid[cur.first][cur.second]<grid[cur.first][cur.second-1]){
                    grid[cur.first][cur.second-1] = 1 + grid[cur.first][cur.second];
                    to_fill.push({cur.first,cur.second-1});
                }
            }
            if(cur.first < grid.size()-1 && grid[cur.first+1][cur.second] > 0){
                if(1+grid[cur.first][cur.second]<grid[cur.first+1][cur.second]){
                    grid[cur.first+1][cur.second] = 1 + grid[cur.first][cur.second];
                    to_fill.push({cur.first+1,cur.second});
                }
            }
            if(cur.second < grid[0].size()-1 && grid[cur.first][cur.second+1] > 0){
                if(1+grid[cur.first][cur.second]<grid[cur.first][cur.second+1]){
                    grid[cur.first][cur.second+1] = 1 + grid[cur.first][cur.second];
                    to_fill.push({cur.first,cur.second+1});
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]==0){
                    bfs(grid,i,j);
                }
            }
        }
    }
};
