class Solution {
public:
    struct Compare{
        bool operator()(const auto& a, const auto& b){
            return a[0] < b[0];
        }
    };
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int,vector<int>,greater<int>> available;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> in_progress;
        sort(meetings.begin(),meetings.end(),Compare());
        vector<int> count(n);
        for(int i = 0; i < n; i++){
            available.push(i);
        }
        for(vector<int> cur : meetings){
            while(!in_progress.empty() && in_progress.top().first < cur[0]){
                available.push(in_progress.top().second);
                in_progress.pop();
            }
            if(!available.empty()){
                int room = available.top();
                available.pop();
                in_progress.push({cur[1],room});
                count[room]++;
            }
            else{
                int new_end = cur[1];
                in_progress.push({in_progress.top().first + new_end - cur[0],in_progress.top().second});
                count[in_progress.top().second]++;
                in_progress.pop();
            }
        }
        return distance(count.begin(),max_element(count.begin(),count.end()));
    }
};