class Solution {
public:
    vector<int> cycle;
    bool foundcycle = false;
    bool cyclefin = false;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1);
        for(const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> temp;
        dfs(adj,1,-1,temp);
        set<pair<int,int>> cycle_edges;
        for(int i = 0; i < cycle.size()-1; i++){
            cycle_edges.insert({cycle[i],cycle[i+1]});
        }
        for(int i = edges.size()-1; i >= 0; i--){
            cout << edges[i][0] << endl;
            cout << edges[i][1] << endl;
            pair<int,int> temp1 = {edges[i][0],edges[i][1]};
            pair<int,int> temp2 = {edges[i][1],edges[i][0]};
            cout << temp1.first << " " << temp1.second << endl;
            cout << temp2.first << " " << temp2.second << endl;
            if(cycle_edges.contains(temp1)||cycle_edges.contains(temp2)){
                return edges[i];
            }
        }
        vector<int> empty;
        return empty;
    }
    void dfs(vector<vector<int>>& adj, int cur, int parent, unordered_set<int>& visited){
        cout << cur << endl;
        if(visited.contains(cur)){
            foundcycle = true;
            cycle.push_back(cur);
            cycle.push_back(parent);
            return;
        }
        visited.insert(cur);
        for(int i : adj[cur]){
            if(i==parent){
                continue;
            }
            dfs(adj,i,cur,visited);
            if(cyclefin){
                return;
            }
            if(foundcycle){
                if(cur == cycle[0]){
                    cyclefin = true;
                    return;
                }
                cycle.push_back(parent);
                return;
            }
        }
    }
};
