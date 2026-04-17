class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> vis;
        int count = 0;
        int i = 0;
        while(vis.size()!=n){
            if(vis.contains(i)){
                i++;
                continue;
            }
            count++;
            dfs(vis,i,adj);
            i++;
        }
        return count;
    }
    void dfs(unordered_set<int>& visited, int node, vector<vector<int>>& adj){
        visited.insert(node);
        for(int i : adj[node]){
            if(!visited.contains(i)){
                dfs(visited,i,adj);
            }
        }
    }
};
