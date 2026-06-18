class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int max_interval = 0;
        for(int i = 0; i < intervals.size(); i++){
            max_interval = max(max_interval, intervals[i][1]);
        }
        vector<int> max_reach(max_interval + 1, -1);
        for(int i = 0; i < intervals.size(); i++){
            int cur_start = intervals[i][0];
            int cur_end = intervals[i][1] + 1;
            max_reach[cur_start] = max(max_reach[cur_start],cur_end);
        }
        vector<vector<int>> result; 
        int cur_interval_start = -2;
        int cur_interval_end = -2;
        for(int i = 0; i < max_interval + 1; i++){
            if(max_reach[i]!=-1){
                if(cur_interval_start != -2){
                    cur_interval_end = max(cur_interval_end,max_reach[i]-1);
                }
                else{
                    cur_interval_start = i;
                    cur_interval_end = max_reach[i]-1;
                }
            }
            if(i == cur_interval_end){
                vector<int> temp;
                temp.push_back(cur_interval_start);
                temp.push_back(cur_interval_end);
                result.push_back(temp);
                cur_interval_start = -2;
                cur_interval_end = -2; 
            }
        }
        if(cur_interval_start != -2){
            vector<int> temp;
            temp.push_back(cur_interval_start);
            temp.push_back(max_interval);
            result.push_back(temp);
        }
        return result;
    }
};
