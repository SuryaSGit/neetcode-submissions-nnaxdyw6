class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time_vals(n+1);
        for(int i = 0; i < n + 1; i++){
            time_vals[i] = INT_MAX;
        }
        vector<vector<pair<int,int>>> adj(n+1);
        for(const auto& edge : times){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        int curmax = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> djk;
        djk.push({0,k});
        unordered_set<int> visited;
        while(!djk.empty()){
            int curtime = djk.top().first;
            int curnode = djk.top().second;
            djk.pop();
            if(visited.contains(curnode)){
                continue;
            }
            visited.insert(curnode);
            curmax=curtime;
            for(const auto& edge : adj[curnode]){
                djk.push({curtime+edge.second, edge.first});
            }
        }
        if(visited.size() < n){
            return -1;
        }
        return curmax;
    }
};
