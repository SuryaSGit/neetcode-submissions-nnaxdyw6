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
        queue<int> bfs;
        bfs.push(k);
        time_vals[k] = 0;
        while(!bfs.empty()){
            int cur = bfs.front();
            cout << cur << endl;
            bfs.pop();
            for(const auto& n : adj[cur]){
                int temp = time_vals[cur] + n.second;
                if(time_vals[n.first] > temp){
                    time_vals[n.first] = temp;
                    bfs.push(n.first);
                }
            }
        }
        int curmax = 0;
        for(int i = 1; i < time_vals.size(); i++){
            int j = time_vals[i];
            cout << "j: " << j << endl;
            if(j==INT_MAX){
                return -1;
            }
            curmax = max(curmax, j);
        }
        return curmax;
    }
};
