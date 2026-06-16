class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        int insert_pos = findpos(intervals, newInterval, 0,intervals.size() - 1);
        cout << insert_pos << endl;
        if(insert_pos == 0){
            intervals.insert(intervals.begin(),newInterval);
            checkMerge(intervals,0);
            return intervals;
        }
        else if(insert_pos == intervals.size()){
            intervals.push_back(newInterval);
            checkMerge(intervals,intervals.size()-1);
            return intervals;
        }
        else{
            intervals.insert(intervals.begin() + insert_pos, newInterval);
            checkMerge(intervals,insert_pos);
            return intervals;
        }
    }
    void checkMerge(vector<vector<int>>& intervals, int pos){
        if(pos > 0 && intervals[pos - 1][1] >= intervals[pos][0]){
            intervals[pos-1][1] = max(intervals[pos-1][1],intervals[pos][1]);
            intervals.erase(intervals.begin()+pos);
            checkMerge(intervals,pos-1);
        }
        if(pos < intervals.size()-1 && intervals[pos+1][0] <= intervals[pos][1]){
            intervals[pos][1] = max(intervals[pos][1],intervals[pos+1][1]);
            intervals.erase(intervals.begin() + pos + 1);
            checkMerge(intervals,pos);
        }
    }
    int findpos(vector<vector<int>>& intervals, vector<int>& newInterval, int low, int high){
        if(low > high){
            return low;
        }
        int mid = (low + high) / 2;
        if(intervals[mid][0] > newInterval[0]){
            if(mid == 0 || intervals[mid-1][0] < newInterval[0]){
                return mid;
            }
            else{
                return findpos(intervals,newInterval,low,mid-1);
            }
        }
        else{
            return findpos(intervals,newInterval,mid + 1, high);
        }
    }
};
