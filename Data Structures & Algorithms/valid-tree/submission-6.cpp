class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        unordered_set<int> visited;
        if(!dfs(adj,-1,0,visited)){
            return false;
        }
        if(visited.size()==n){
            return true;
        }
        return false;
    }
    bool dfs(vector<vector<int>>& adj, int parent, int node, unordered_set<int>& visit){
        if(visit.contains(node)){
            return false;
        }
        visit.insert(node);
        for(int j : adj[node]){
            if(j == parent){
                continue;
            }
            if(!dfs(adj,node,j,visit)){
                return false;
            }
        }
        return true;
    }
};
