class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end(),
        [](auto& a, auto& b){
            return a[0]<b[0];
        });
        int cur_query = -1;
        vector<int> result(queries.size());
        int cur_bound = 0;
        for(int i = 0; i < queries.size(); i++){
            cur_query = queries[i];
            cur_bound = 0;
            int best_length = 10001;
            int pos = binary_search(intervals,cur_query,0,intervals.size()-1);
            //cout << pos << endl;
            //return result;
            while(pos >= 0 && intervals[pos][0] >= cur_bound){
                if(intervals[pos][0] <= cur_query && intervals[pos][1] >= cur_query){
                    int cur_length = 1 + intervals[pos][1] - intervals[pos][0]; 
                    cur_bound = cur_query - cur_length;
                    best_length = min(best_length,cur_length);
                }
                pos--;
            }
            if(best_length == 10001){
                best_length = -1;
            }
            result[i] = best_length;
        }
        return result;
    }
    int binary_search(vector<vector<int>>& intervals, int cur_query, int low, int high){
        if(low < 0 || high > intervals.size()-1){
            return -1;
        }
        int mid = (low + high)/2;
        if(low > high){
            return mid;
        }
        if(intervals[mid][0] > cur_query){
            return binary_search(intervals,cur_query,low,mid-1);
        }
        else{
            return binary_search(intervals,cur_query,mid+1,high);
        }
    }
};
