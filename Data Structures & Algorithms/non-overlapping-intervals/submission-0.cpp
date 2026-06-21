class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
        [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int last_interval_end = intervals[0][1];
        int count = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < last_interval_end && intervals[i][1] >= last_interval_end){
                count++;
            }
            else{
                last_interval_end = intervals[i][1];
            }
        }
        return count;
    }
};
