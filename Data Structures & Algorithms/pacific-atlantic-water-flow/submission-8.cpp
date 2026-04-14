
class Solution {
public:
    struct pair_hash {
        inline std::size_t operator()(const std::pair<int,int> & v) const {
            return v.first*31+v.second;
        }
    };
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        unordered_set<pair<int,int>,pair_hash> pacific_set;
        queue<pair<int,int>> pacific;
        for(int i = 0; i < heights.size(); i++){
            pacific.push({i,0});
            pacific_set.insert({i,0});
        }
        for(int i = 1; i < heights[0].size(); i++){
            pacific.push({0,i});
            pacific_set.insert({0,i});
        }
        while(!pacific.empty()){
            pair<int,int> cur = pacific.front();
            int cur_val = heights[cur.first][cur.second];
            pacific.pop();
            if(cur.first < heights.size()-1 && heights[cur.first+1][cur.second] >= cur_val){
                pacific.push({cur.first+1,cur.second});
                pacific_set.insert({cur.first+1,cur.second});
            }
            if(cur.second < heights[0].size() && heights[cur.first][cur.second +1 ] >= cur_val){
                pacific.push({cur.first,cur.second + 1});
                pacific_set.insert({cur.first,cur.second+1});
            }
            if(cur.first > 0 && heights[cur.first-1][cur.second] >= cur_val){
                if(!pacific_set.contains({cur.first-1,cur.second})){
                    pacific.push({cur.first-1,cur.second});
                    pacific_set.insert({cur.first-1,cur.second});
                }
            }
            if(cur.second > 0 && heights[cur.first][cur.second-1] >= cur_val){
                if(!pacific_set.contains({cur.first,cur.second-1})){
                    pacific.push({cur.first,cur.second-1});
                    pacific_set.insert({cur.first,cur.second-1});
                }
            } 
        }
        vector<vector<int>> result;
        unordered_set<pair<int,int>,pair_hash> result2;
        unordered_set<pair<int,int>,pair_hash> atlantic_set;
        queue<pair<int,int>> atlantic;
        for(int i = 0; i < heights.size(); i++){
            atlantic.push({i,heights[0].size()-1});
            atlantic_set.insert({i,heights[0].size()-1});
        }
        for(int i = 0; i < heights[0].size()-1; i++){
            atlantic.push({heights.size()-1,i});
            atlantic_set.insert({heights.size()-1,i});
        }
        while(!atlantic.empty()){
            pair<int,int> cur = atlantic.front();
            int cur_val = heights[cur.first][cur.second];
            atlantic.pop();
            if(pacific_set.contains(cur)&&!result2.contains(cur)){
                vector<int> temp;
                temp.push_back(cur.first);
                temp.push_back(cur.second);
                result.push_back(temp);
                result2.insert(cur);
            }
            if(cur.first > 0 && heights[cur.first-1][cur.second] >= cur_val){
                atlantic.push({cur.first-1,cur.second});
                atlantic_set.insert({cur.first-1,cur.second});
            } 
            if(cur.second > 0 && heights[cur.first][cur.second -1 ] >= cur_val){
                atlantic.push({cur.first,cur.second - 1});
                atlantic_set.insert({cur.first,cur.second - 1});
            }
            if(cur.first < heights.size()-1 && heights[cur.first+1][cur.second] >= cur_val){
                if(!atlantic_set.contains({cur.first+1,cur.second})){
                    atlantic.push({cur.first+1,cur.second});
                    atlantic_set.insert({cur.first+1,cur.second});
                }
            }
            if(cur.second < heights[0].size()-1 && heights[cur.first][cur.second+1] >= cur_val){
                if(!atlantic_set.contains({cur.first,cur.second+1})){
                    atlantic.push({cur.first,cur.second+1});
                    atlantic_set.insert({cur.first,cur.second+1});
                }
            } 
        }
        return result;
    }
};
