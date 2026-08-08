class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> min_heap;
        min_heap.push({0,0,0});
        set<vector<int>> visited;
        while(!min_heap.empty()){
            vector<int> cur = min_heap.top();
            int row = cur[1];
            int col = cur[2];
            int val = cur[0];
            if(row == heights.size() - 1 && col == heights[0].size() - 1){
                return val;
            }
            min_heap.pop();
            if(visited.contains({row,col})){
                continue;
            }
            visited.insert({row,col});
            int cur_height = heights[row][col];
            if(row > 0){
                min_heap.push({max(val,abs(heights[row-1][col]-cur_height)),row-1,col});
            }
            if(row < heights.size() - 1){
                min_heap.push({max(val,abs(heights[row+1][col]-cur_height)),row+1,col});
            }
            if(col > 0){
                min_heap.push({max(val,abs(heights[row][col-1]-cur_height)),row,col-1});
            }
            if(col < heights[0].size() - 1){
                min_heap.push({max(val,abs(heights[row][col+1]-cur_height)),row,col+1});
            }
        }
        return -1;
    }
};