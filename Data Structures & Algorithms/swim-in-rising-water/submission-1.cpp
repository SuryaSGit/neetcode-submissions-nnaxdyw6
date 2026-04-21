class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> djk;
        vector<int> start_elems;
        start_elems.push_back(grid[0][0]);
        start_elems.push_back(0);
        start_elems.push_back(0);
        int grid_size = grid.size();
        djk.push(start_elems);
        pair<int,int> end_cords;
        end_cords.first = grid.size();
        end_cords.second = grid.size();
        set<pair<int,int>> visited;
        while(!visited.contains(end_cords) && djk.size() > 0){
            vector<int> temp1 = djk.top();
            int cur_max = temp1[0];
            int cur_x = temp1[1]; 
            int cur_y = temp1[2];
            if(cur_x == grid_size - 1 && cur_y == grid_size - 1){
                return cur_max;
            }
            djk.pop();
            if(visited.contains({cur_x,cur_y})){
                continue;
            }
            visited.insert({cur_x,cur_y});
            vector<int> temp(3);
            if(cur_x > 0){
                temp[0]=max(grid[cur_x-1][cur_y],cur_max);
                temp[1] = cur_x-1;
                temp[2] = cur_y;
                djk.push(temp);
            }
            if(cur_y > 0){
                temp[0]=max(grid[cur_x][cur_y-1],cur_max);
                temp[1] = cur_x;
                temp[2] = cur_y-1;
                djk.push(temp);
            }
            if(cur_y < grid_size-1){
                temp[0]=max(grid[cur_x][cur_y+1],cur_max);
                temp[1] = cur_x;
                temp[2] = cur_y+1;
                djk.push(temp);
            }
            if(cur_x < grid_size-1){
                temp[0]=max(grid[cur_x+1][cur_y],cur_max);
                temp[1] = cur_x+1;
                temp[2] = cur_y;
                djk.push(temp);
            }
        }
        return -1;
    }
};
